#ifndef CONV3D_H
#define CONV3D_H

#include "ImageRGB.h"
#include "Kernel3D.h"
class Conv3D
{
private:
	ImageRGB out;
	Kernel3D kernel;
	ImageRGB input;

	void convStep(int t_x, int t_y);
public:
	ImageRGB perform();
	Conv3D(ImageRGB input, Kernel3D kernel);

};

#endif