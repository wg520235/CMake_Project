#ifndef _ENCODE_PNG_H_
#define _ENCODE_PNG_H_

#ifdef __cplusplus
extern "C"{
#endif

//RGB24格式转YUV420格式
void RGB2YUV420P(unsigned char *rgb24, int width, int height, unsigned char *yuv420p);
//RGB24格式转PNG格式图片
int RGB24_TO_PNG(const char *filename, const char *rgbData, int width, int height, int quality);
//YUV420P格式转RGB24格式
void YUV420P_TO_RGB24(unsigned char *yuv420p, unsigned char *rgb24, int width, int height);
//YUV420P格式编码成PNG格式
void YUV420P_TO_PNG(const char *yuvPath, const char *pngPath, int width, int height);
	
#ifdef __cplusplus
}
#endif

#endif /*_ENCODE_PNG_H_*/
/** @}*/


