#ifndef MAT3D_H
#define MAT3D_H

#include <fstream>
class Mat3D
{
protected:
	int width, height, depth;
	int* data;
public:
	Mat3D();
	Mat3D(const Mat3D &other);
	Mat3D(int width, int height, int depth);
	~Mat3D();
	int getSize();
	virtual void read(const char* filename);
	int getElement(int index);
	void setElement(int index, int value);
	void setElement(int x, int y, int z, int value);
	int getElement(int x, int y, int z);
	virtual Mat3D& operator=(Mat3D& other);
	int getWidth();
	int getHeight();
	int getDepth();
	void paste(int x, int y, int z, Mat3D frame);
	Mat3D copy(int x, int y, int z, int w, int h, int d);
	virtual void fill(int value);
};

#endif