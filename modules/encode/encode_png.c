#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <png.h>

#include "encode_png.h"

//RGB24格式转PNG格式图片
int RGB24_TO_PNG(const char *filename, const char *rgbData, int width, int height,
                           int quality) {
    FILE *fp;
    png_structp png_ptr = NULL;
    png_infop info_ptr = NULL;
    fp = fopen(filename, "wb");
    if (fp) {
        png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
        info_ptr = png_create_info_struct(png_ptr);
        if (png_ptr == NULL || info_ptr == NULL) {
            fclose(fp);
            return -1;
        }
        png_init_io(png_ptr, fp);
        png_set_IHDR(png_ptr, info_ptr, width, height, 8, PNG_COLOR_TYPE_RGB, PNG_INTERLACE_NONE,
                     PNG_COMPRESSION_TYPE_BASE, PNG_FILTER_TYPE_BASE);
        png_write_info(png_ptr, info_ptr);
        png_set_packing(png_ptr);
        unsigned char *data = (unsigned char*)malloc(width * 3);
        memset(data, 255, width * 3);
        int nv_start = width * height;
        unsigned int rgb_index = 0, pos;
        int r, g, b, nv_index, y, ru, rv;
        for (unsigned int i = 0; i < height; ++i) {
            for (unsigned int j = 0; j < width; ++j) {
                data[j * 3 + 0] = rgbData[rgb_index++];
                data[j * 3 + 1] = rgbData[rgb_index++];
                data[j * 3 + 2] = rgbData[rgb_index++];
            }
            png_write_row(png_ptr, data);
        }

		free(data);
        png_write_end(png_ptr, info_ptr);
        png_destroy_write_struct(&png_ptr, &info_ptr);
        fclose(fp);
        return 0;
    }
    return -1;
}
//YUV420P格式转RGB24格式
void YUV420P_TO_RGB24(unsigned char *yuv420p, unsigned char *rgb24, int width, int height) {
    int index = 0;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {

            int indexY = y * width + x;
            int indexU = width * height + y / 2 * width / 2 + x / 2;
            int indexV = width * height + width * height / 4 + y / 2 * width / 2 + x / 2;

            u_char Y = yuv420p[indexY];
            u_char U = yuv420p[indexU];
            u_char V = yuv420p[indexV];

            rgb24[index++] = Y + 1.402 * (V - 128); //R
            rgb24[index++] = Y - 0.34413 * (U - 128) - 0.71414 * (V - 128); //G
            rgb24[index++] = Y + 1.772 * (U - 128); //B
        }
    }
}
//YUV420P格式编码成PNG格式
void YUV420P_TO_PNG(const char *yuvPath, const char *pngPath, int width, int height) {
    FILE *file = fopen(yuvPath, "rb");

    unsigned char *yuv420p = (unsigned char*)malloc(width * height * 3 / 2);

    fread(yuv420p, 1, width * height * 3 / 2, file);

    unsigned char *rgb24 = (unsigned char*)malloc(width * height * 3);

    //YUV420P转RGB24
	YUV420P_TO_RGB24(yuv420p, rgb24, width, height);

    //RGB24转PNG文件
    RGB24_TO_PNG(pngPath, rgb24, width, height, 100);

    //释放内存
    free(yuv420p);
    free(rgb24);

    //关闭文件句柄
    fclose(file);
}
