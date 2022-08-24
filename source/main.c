#include "tigr.h"
#include <stdio.h>
#include <stdlib.h>
#include "images/test.h"
#include "miniz.h"

void img_to_tigr(int w, int h, int bpp, const unsigned char* comp_data, unsigned long data_len, Tigr* out) {
	// Prepare Tigr Struct
	int num_pix = w * h;
	out->w = w;
	out->h = h;
	out->pix = calloc(num_pix, sizeof(TPixel));

	unsigned long uncomp_len = num_pix * bpp;
	unsigned char * uncomp = calloc(uncomp_len, sizeof(unsigned char));

	int uncomp_status = uncompress(uncomp, &uncomp_len, comp_data, data_len);
	if (uncomp_status != Z_OK) {
		fprintf(stderr, "Error: Couldn't decompress image!\n");
		exit(-1);
	}
	memcpy(out->pix, uncomp, uncomp_len);

	free(uncomp);
}

int main(const int argc, const char** argv) {
	Tigr* screen = tigrWindow(320, 240, "hello", 0);
	
	Tigr img = {0};
	img_to_tigr(img_test.width, img_test.height, img_test.bytes_per_pixel, img_test.comp_pixel_data, img_test.data_len, &img);

	while(!tigrClosed(screen)) {
		tigrBlit(screen, &img, 0, 0, 0, 0, img.w, img.h);
		tigrUpdate(screen);
	}

	return 0;
}
