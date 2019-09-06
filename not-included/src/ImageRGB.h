#ifndef IMAGERGB_H
#define IMAGERGB_H

#include "Mat3D.h"
class ImageRGB :
	public Mat3D
{
public:
	ImageRGB();
	~ImageRGB();
	ImageRGB(int width, int height);
	ImageRGB(const char* filename);
	ImageRGB(Mat3D mat);
	void read(const char* filename);
	void write(const char* filename);
	ImageRGB operator=(ImageRGB other);
};

#endif