#include<stdio.h>

#include "encode_png.h"//引用encode模块的头文件
#include "my_test.h"//引用my_test模块的头文件

int main()
{	
	//调用my_test模块的接口，实现1+1 ， 1-1计算
	int c;
	a_add_b(1, 1, &c);
	printf("a+b=%d\n", c);//打印结果
	
	a_minus_b(1, 1, &c);
	printf("a-b=%d\n", c);//打印结果
	
	//调用encode模块的YUV420P_TO_PNG接口将yuv格式的图片编码成png图片
	YUV420P_TO_PNG("../resource/frame.yuv", "../resource/frame.png", 1790, 1080);
	
	return 0;
}