#include <pshpack2.h>
#include "stdio.h"
#include "stdlib.h"
#include "string.h"


#pragma pack(2)//必须得写，否则sizeof得不到正确的结果

typedef long BOOL;
typedef long LONG;
typedef unsigned char BYTE;
typedef unsigned long DWORD;
typedef unsigned short WORD;

//位图文件头文件定义
//其中不包括文件类型信息（由于结构体的内存结构决定，要是加了的话将不能正确的读取文件信息）
typedef struct {
	WORD    bfType;//文件类型，必须是0x424D,即字符“BM”
	DWORD   bfSize;//文件大小
	WORD    bfReserved1;//保留字
	WORD    bfReserved2;//保留字
	DWORD   bfOffBits;//从文件头到实际位图数据的偏移字节数
} BMPFILEHEADER_T;

struct BMPFILEHEADER_S {
	WORD    bfType;
	DWORD   bfSize;
	WORD    bfReserved1;
	WORD    bfReserved2;
	DWORD   bfOffBits;
};
typedef struct {
	DWORD      biSize;//信息头大小
	LONG       biWidth;//图像宽度
	LONG       biHeight;//图像高度
	WORD       biPlanes;//位平面数，必须为1
	WORD       biBitCount;//每像素位数
	DWORD      biCompression;//压缩类型
	DWORD      biSizeImage;//压缩图像大小字节数
	LONG       biXPelsPerMeter;//水平分辨率
	LONG       biYPelsPerMeter;//垂直分辨率
	DWORD      biClrUsed;//位图实际用到的色彩数
	DWORD      biClrImportant;//本位图中重要的色彩数
} BMPINFOHEADER_T;//位图信息头定义

void generateBmp(BYTE * pData, int width, int height, char * filename)//生成Bmp图片，传递RGB值，传递图片像素大小，传递图片存储路径
{
	int size = width*height * 3 ; // 每个像素点3个字节
								 // 位图第一部分，文件信息
	BMPFILEHEADER_T bfh;
	bfh.bfType = 0X4d42;  //bm
	bfh.bfSize = size  // data size
		+ sizeof(BMPFILEHEADER_T) // first section size
		+ sizeof(BMPINFOHEADER_T) // second section size
		;
	bfh.bfReserved1 = 0; // reserved
	bfh.bfReserved2 = 0; // reserved
	bfh.bfOffBits = bfh.bfSize - size;

	// 位图第二部分，数据信息
	BMPINFOHEADER_T bih;
	bih.biSize = sizeof(BMPINFOHEADER_T);
	bih.biWidth = width;
	bih.biHeight = height;
	bih.biPlanes = 1;
	bih.biBitCount = 8;
	bih.biCompression = 0;
	//bih.biSizeImage = size;
	bih.biSizeImage = 0;
	bih.biXPelsPerMeter = 0;
	bih.biYPelsPerMeter = 0;
	bih.biClrUsed = 0;
	bih.biClrImportant = 0;
	FILE * fp = fopen(filename, "wb");
	if (!fp) return;
	fwrite(&bfh, 1, sizeof(BMPFILEHEADER_T), fp);
	fwrite(&bih, 1, sizeof(BMPINFOHEADER_T), fp);
	fwrite(pData, 1, size, fp);
	fclose(fp);
}
void main()
{
	int i = 0, j = 0;

	unsigned char pRGB[30000];  // 定义位图数据
	memset(pRGB, 0, sizeof(pRGB)); // 设置背景为黑色
								   // 在中间画一个100*100的矩形
	for (i = 0; i<30000/2; i++) {
		pRGB[i] = 0;
	}

	for (i = 30000 / 2; i<30000; i++) {
		pRGB[i] = 255;
	}

	// 生成BMP图片
	generateBmp((BYTE*)pRGB, 100, 100, "./bmp.bmp");
}