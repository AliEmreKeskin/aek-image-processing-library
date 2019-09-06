#include "Kernel3D.h"

Kernel3D::Kernel3D()
{
	this->coefficients = nullptr;
}

Kernel3D::~Kernel3D()
{
	delete[]this->coefficients;
}

Kernel3D::Kernel3D(int width, int height, int depth):Mat3D(width,height,depth)
{
	this->coefficients = new double[depth];
}

Kernel3D::Kernel3D(const char* filename)
{
	this->read(filename);
}

void Kernel3D::read(const char* filename)
{
	std::ifstream inData;
	inData.open(filename, std::ios::in);
	int temp;

	//read kernel size
	inData >> this->width;
	inData >> this->height;
	inData >> this->depth;
	this->data = new int[this->getSize()];
	this->coefficients = new double[this->depth];

	//read coefficients
	for (int i = 0; i < this->depth; i++) {
		inData >> temp;
		this->coefficients[i] = pow(temp,-1);
	}

	//read data
	for (int i = 0; i < this->depth; i++) {
		for (int j = 0; j < this->getSize() / this->depth; j++) {
			inData >> temp;
			this->data[j * this->depth + i] = temp;
		}
	}
}

void Kernel3D::setCoefficient(int index, int value)
{
	this->coefficients[index] = value;
}

double Kernel3D::getCoefficient(int index)
{
	return this->coefficients[index];
}

void Kernel3D::write(const char* filename)
{
	std::ofstream outData;
	outData.open(filename, std::ios::out);

	//write kernel size
	outData << this->width << " " << this->height << " " << this->depth << std::endl << std::endl;

	//write coefficients
	for (int i = 0; i < this->depth; i++) {
		outData << pow(this->coefficients[i], -1) << " ";
	}
	outData << std::endl << std::endl;

	//write data
	for (int i = 0; i < this->depth; i++) {
		for (int j = 0; j < this->height; j++) {
			for (int k = 0; k < this->width; k++) {
				outData << data[j * this->width * this->depth + k * this->depth + i] << " ";
			}
			outData << std::endl;
		}
		outData << std::endl;
	}

	outData.close();
}

Kernel3D& Kernel3D::operator=(const Kernel3D& other)
{
	this->width = other.width;
	this->height = other.height;
	this->depth = other.depth;
	this->data = new int[this->getSize()];
	for (int i = 0; i < this->getSize(); i++) {
		this->data[i] = other.data[i];
	}
	this->coefficients = new double[this->depth];
	for (int i = 0; i < this->depth; i++) {
		this->coefficients[i] = other.coefficients[i];
	}
	return *this;
}
