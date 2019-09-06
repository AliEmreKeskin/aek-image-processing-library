#define _CRT_SECURE_NO_WARNINGS

#include "ImageRGB.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

ImageRGB::ImageRGB()
{
}

ImageRGB::~ImageRGB()
{
}

ImageRGB::ImageRGB(int width, int height):Mat3D(width,height,3)
{
}

ImageRGB::ImageRGB(const char* filename)
{
	this->read(filename);
}

ImageRGB::ImageRGB(Mat3D mat)
{
	this->width = mat.getWidth();
	this->height = mat.getHeight();
	this->depth = mat.getDepth();
	this->data = new int[this->getSize()];
	for (int i = 0; i < this->getSize(); i++) {
		this->data[i] = mat.getElement(i);
	}
}

void ImageRGB::read(const char* filename)
{
	unsigned char* temp = stbi_load(filename, &this->width, &this->height, &this->depth, 3);
	this->data = new int[this->getSize()];
	for (int i = 0; i < this->getSize(); i++) {
		this->data[i] = int(temp[i]);
	}
}

void ImageRGB::write(const char* filename)
{
	unsigned char* temp = new unsigned char[this->getSize()];
	for (int i = 0; i < this->getSize(); i++) {
		temp[i] = (unsigned char)this->data[i];
	}
	stbi_write_png(filename, this->width, this->height, this->depth, temp, this->depth * this->width);
}

ImageRGB ImageRGB::operator=(ImageRGB other)
{
	this->width = other.getWidth();
	this->height = other.getHeight();
	this->depth = other.getDepth();
	this->data = new int[this->getSize()];
	for (int i = 0; i < this->getSize(); i++) {
		this->data[i] = other.getElement(i);
	}
	return *this;	
}