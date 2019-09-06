#include <iostream>
#include <chrono>
#include "Kernel3D.h"
#include "ImageRGB.h"
#include "Conv3D.h"
int main(int argc, char** argv) {
	//check for usage
	if (argc != 3)
	{
		std::cout << " Usage: program input_image kernel" << std::endl;
		return -1;
	}

	//timer start
	auto start = std::chrono::steady_clock::now();

	//read inputs
	ImageRGB img1(argv[1]);
	Kernel3D kernel1(argv[2]);

	//process
	Conv3D conv1(img1, kernel1);
	ImageRGB img2 = conv1.perform();

	//write output
	img2.write("output_image.png");

	//timer end
	auto end = std::chrono::steady_clock::now();
	auto diff = end - start;

	//print execution time
	std::cout<<"Execution time: ";
	std::cout << std::chrono::duration <double, std::nano> (diff).count() << " ns" << std::endl;

	return 0;
}