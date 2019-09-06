#include "Conv3D.h"

void Conv3D::convStep(int t_x, int t_y)
{
	int pixel[3] = { 0,0,0 };
	for (int y = 0; y < this->kernel.getHeight(); y++) {
		for (int x = 0; x < this->kernel.getWidth(); x++) {
			for (int z = 0; z < this->kernel.getDepth(); z++) {
				pixel[z] += this->input.getElement(t_x + x, t_y + y, z) * this->kernel.getElement(x, y, z);
			}
		}
	}
	for (int i = 0; i < this->kernel.getDepth(); i++) {
		//this->out.setElement(t_x, t_y, i, pixel[i] * this->kernel.getCoefficient(i));
		double coeff = this->kernel.getCoefficient(i);
		int pix = pixel[i];
		int val = coeff * pix;
		this->out.setElement(t_x, t_y, i, val);
	}
}

ImageRGB Conv3D::perform()
{
	for (int y = 0; y < this->out.getHeight(); y++) {
		for (int x = 0; x < this->out.getWidth(); x++) {
			this->convStep(x, y);
		}
	}

	return this->out;
}

Conv3D::Conv3D(ImageRGB t_input, Kernel3D t_kernel)
{
	this->out = t_input;
	this->kernel = t_kernel;

	int border_width = (t_kernel.getWidth() - 1) / 2;
	int border_height = (t_kernel.getHeight() - 1) / 2;
	int output_width = t_input.getWidth() + 2 * border_width;
	int output_height = t_input.getHeight() + 2 * border_height;
	this->input = ImageRGB(output_width, output_height);
	this->input.fill(255);
	this->input.paste(border_width, border_height, 0, this->out);
}
