#ifndef KERNEL3D_H
#define KERNEL3D_H

#include "Mat3D.h"
#include <cmath>
class Kernel3D :
	public Mat3D
{
protected:
	double* coefficients;
public:
	Kernel3D();
	~Kernel3D();
	Kernel3D(int width, int height, int depth);
	Kernel3D(const char* filename);
	void read(const char* filename);
	void setCoefficient(int index, int value);
	double getCoefficient(int index);
	void write(const char* filename);
	Kernel3D& operator=(const Kernel3D& other);
};

#endif