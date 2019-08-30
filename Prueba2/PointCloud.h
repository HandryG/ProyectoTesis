#pragma once
#include <vector>
#include <string>
struct  Point{
	float x, y, z;
	Point() : x(-1.0), y(-1.0), z(-1.0){}
	Point(float a, float b, float c) : x(a), y(b), z(c) {}
};

class PointCloud
{
public:
	PointCloud(const std::string &path);

	int getVertsCount();
	Point *getVertsData();

	virtual ~PointCloud();

	
private:
	std::vector<Point> verts;
#pragma pack(push,1)
	struct Header {
		char magic[4];
		uint16_t fileSourceID;
		uint16_t globalEncoding;
		uint32_t guidData1;
		uint16_t guidData2;
		uint16_t guidData3;
		uint8_t guidData4[8];
		uint8_t versionMaj, versionMin;
		char systemIdentifier[32];
		char genSoftware[32];
		uint16_t creationDay, creationYear;
		uint16_t headerSize;
		uint32_t pointDataOffset;
		uint32_t numVerLenRecords;
		uint8_t pointDataRecordFormat;
		uint16_t pointDataRecordLen;
		uint32_t numberOfPoints;
		uint32_t numPointsByReturn[5];
		double scaleX, scaleY, scaleZ;
		double offX, offY, offZ;
		double minX, minY, minZ;
		double maxX, maxY, maxZ;
	};
#pragma pack(pop)

#pragma pack(push,1)
	struct PointRecord3{
		uint32_t x, y, z;
		uint16_t intensity;
		uint8_t flags;
		uint8_t classification;
		uint8_t scanAngleRank;
		uint8_t userData;
		uint16_t  pointSourceId;
		double gpsTime;
		uint16_t red,green,blue;
	};
#pragma pack(pop)
	void read(const std::string &path);
};

