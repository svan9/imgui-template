#include "buffer.h"

Buffer::Buffer() { 
}

Buffer::Buffer(uint32 *data, size_t width, size_t height) 
	: data(data), width(width), height(height) { }

void Buffer::draw() {
	glBegin(GL_POINTS);
	#pragma omp parallel for reduction(+:x,y)
	for (int x = 0; x < width;x++) {
		for (int y = 0; y < height; y++) {
			auto pixel = *(data+(width*y)+x);
			glColor3f(pixel[0],pixel[1], pixel[2]);
			glVertex2i(x,y);
		}
	}
	glEnd();
}

void Buffer::draw(size_t _width, size_t _height) {
	glBegin(GL_POINTS);
	size_t max_w = __max(_width, width);
	size_t min_w = __min(_width, width);
	size_t max_h = __max(_height, height);
	size_t min_h = __min(_height, height);
	size_t pixel_size_x = max_w / min_w;
	size_t pixel_size_y = max_h / min_h;
	#pragma omp parallel for reduction(+:x,y)
	for (int x = 0; x < width;x++) {
		for (int y = 0; y < height; y++) {
			auto pixel = *(data+(width*y)+x);
			for (int xx = 0; xx < pixel_size_x; xx++) {
				for (int yy = 0; yy < pixel_size_y; yy++) {
					glColor3f(pixel[0], pixel[1], pixel[2]);
					glVertex2i(x+xx,y+yy);
				}
			}
		}
	}
	glEnd();
}
