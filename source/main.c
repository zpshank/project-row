#include "tigr.h"
#include <stdio.h>
#include <stdlib.h>
#include "images/test.h"

void img_to_tigr(int w, int h, int bpp, const unsigned char* data, Tigr* out) {
	int num_pix = w * h;
	out->w = w;
	out->h = h;
	out->pix = calloc(num_pix, sizeof(TPixel));

	// Loop through every entry in data and assign a TPixel
	for(int i = 0; i < num_pix; i++) {
		int data_idx = i * bpp;
		out->pix[i].r = data[data_idx];
		out->pix[i].g = data[data_idx + 1];
		out->pix[i].b = data[data_idx + 2];
		if (bpp == 4) {
			out->pix[i].a = data[data_idx + 3];
		} else {
			out->pix[i].a = 255;
		}
	}
}

int main(const int argc, const char** argv) {
	Tigr* screen = tigrWindow(320, 240, "hello", 0);
	
	Tigr img = {0};
	img_to_tigr(img_test.width, img_test.height, img_test.bytes_per_pixel, img_test.pixel_data, &img);

	while(!tigrClosed(screen)) {
		tigrBlit(screen, &img, 0, 0, 0, 0, img.w, img.h);
		tigrUpdate(screen);
	}

	return 0;
}
