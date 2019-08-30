#include "pch.h"
#include <iostream>
#include <vector>
#include "Octree.h"
using namespace std;

Octree::Octree() {
	point = new Point;
}

Octree::Octree (float x, float y, float z) {
	point = new Point(x, y, z);
}
