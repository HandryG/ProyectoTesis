#pragma once
#include <vector>
#include "PointCloud.h"
using namespace std;
class Octree
{
private:
	Point* point;
	Point* corner1, corner2;
	vector<Octree*> children;

public:
	Octree();
	Octree(float x, float y, float z);
	Octree(float x1, float y1, float z1, float x2, float y2, float z2);
	void insert(float x, float y, float z);
	bool find(float x, float y, float z);


};

