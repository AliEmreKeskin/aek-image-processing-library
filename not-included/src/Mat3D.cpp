#include "Mat3D.h"

Mat3D::Mat3D()
{
	this->width = 0;
	this->height = 0;
	this->depth = 0;
	this->data = nullptr;
}

Mat3D::Mat3D(const Mat3D &other)
{
	this->width = other.width;
	this->height = other.height;
	this->depth = other.depth;
	this->data = new int[this->getSize()];
	for (int i = 0; i < this->getSize(); i++) {
		this->data[i] = other.data[i];
	}
}

Mat3D::Mat3D(int t_width, int t_height, int t_depth)
{
	this->width = t_width;
	this->height = t_height;
	this->depth = t_depth;
	this->data = new int[this->getSize()];
}

Mat3D::~Mat3D()
{
	delete[]this->data;
}

int Mat3D::getSize()
{
	return this->width * this->height * this->depth;
}

void Mat3D::read(const char* filename)
{
	std::ifstream inData;
	inData.open(filename, std::ios::in);

	//read size
	inData >> this->width;
	inData >> this->height;
	inData >> this->depth;
	this->data = new int[this->getSize()];

	//read data
	for (int i = 0; i < this->getSize(); i++) {
		inData >> this->data[i];
	}
	inData.close();
}

int Mat3D::getElement(int index)
{
	return this->data[index];
}

void Mat3D::setElement(int index, int value)
{
	this->data[index] = value;
}

void Mat3D::setElement(int x, int y, int z, int value)
{
	int index = y * this->width * this->depth + x * this->depth + z;
	this->setElement(index, value);
}

int Mat3D::getElement(int x, int y, int z)
{
	int index = y * this->width * this->depth + x * this->depth + z;
	return this->getElement(index);
}

Mat3D& Mat3D::operator=(Mat3D& other)
{
	this->width = other.width;
	this->height = other.height;
	this->depth = other.depth;
	this->data = new int[this->getSize()];
	for (int i = 0; i < this->getSize(); i++) {
		this->data[i] = other.data[i];
	}
	return *this;
}

int Mat3D::getWidth()
{
	return this->width;
}

int Mat3D::getHeight()
{
	return this->height;
}

int Mat3D::getDepth()
{
	return this->depth;
}

void Mat3D::paste(int x, int y, int z, Mat3D frame)
{
	int temp;
	for (int i = 0; i < frame.getHeight(); i++) {
		for (int j = 0; j < frame.getWidth(); j++) {
			for (int k = 0; k < frame.getDepth(); k++) {
				temp = frame.getElement(j, i, k);
				this->setElement(x + j, y + i, z + k, temp);
			}
		}
	}
}

Mat3D Mat3D::copy(int x, int y, int z, int w, int h, int d)
{
	Mat3D res(w, h, d);
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			for (int k = 0; k < d; k++) {
				int temp = this->getElement(j, i, k);
				res.setElement(j, i, k, temp);
			}
		}
	}
	return res;
}

void Mat3D::fill(int value)
{
	for (int i = 0; i < this->getSize(); i++)
	{
		this->setElement(i, value);
	}
}
