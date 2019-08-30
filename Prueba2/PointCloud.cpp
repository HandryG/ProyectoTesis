#include "pch.h"
#include "PointCloud.h"
#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <assert.h>
#include <fstream>
#include <string>
using namespace std;

PointCloud::PointCloud(const string &path)
{
	read(path);
}

void PointCloud::read(const string &path)
{
	ifstream inf(path, ios::binary);

	// Para este caso estamos leyendo archivos LAS versiona 1.2 con puntos que pertencen al Point Data Record 3
	if (inf.is_open()) {
		Header header;
		inf.read((char *)&header, sizeof(header));

		assert(header.versionMaj == 1 && header.versionMin == 2);
		assert(header.headerSize == sizeof(header));
	
		
		assert(header.pointDataRecordFormat == 3);
		
		inf.seekg(header.pointDataOffset);

		for (int i = 0; i < header.numberOfPoints; i++) {
			PointRecord3 point;
			inf.read((char *)&point, sizeof(PointRecord3));
			Point v = {
				(float)(point.x * header.scaleX),
				(float)(point.y * header.scaleY),
				(float)(point.z * header.scaleZ)
			};
			
			cout <<"x = "<< v.x << '  ' <<" y= " <<v.y << '  '<<" z= " << v.z << endl;
			verts.push_back(v);
		}
	}
	else {
		throw runtime_error("No se pudo leer el archivo");
	}
}

int PointCloud::getVertsCount() {
	return(int)verts.size();
}

Point *PointCloud::getVertsData() {
	return verts.data();
}
PointCloud::~PointCloud()
{
}
