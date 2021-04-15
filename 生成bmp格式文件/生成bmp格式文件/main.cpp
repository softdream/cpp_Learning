#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <math.h>

#define min3( x1, x2, x3 )  ( x1 < x2 ) ? ( ( x1 < x3 ) ? x1 : x3 ) : ( x2 < x3 ? x2 : x3 )

class BMP
{
	struct RGB{
		unsigned char r;
		unsigned char g;
		unsigned char b;
	};
	using RGB = struct RGB;

public:
	BMP():width(100), height(100), homeworkType(2)
	{
		rgb = new RGB[width * height];
		memset(rgb, 0, width * height * sizeof(RGB));

	}

	BMP(int width_, int height_, int homeworkType_) : width(width_),
												height(height_),
												homeworkType(homeworkType_)
	{
		rgb = new RGB[width * height];
		memset(rgb, 0, width * height * sizeof(RGB));
		
	}

	~BMP()
	{
		delete[] rgb;
	}

	virtual void generateBMP(  )
	{
		//------------- 打开文件 --------------//
		std::ofstream outfile;
		outfile.open( "./homework1.bmp", std::ios::out | std::ios::binary | std::ios::app );
		if (!outfile.is_open()) {
			std::cout << "打开文件失败 ..." << std::endl;
			exit(-1);
		}
		std::cout << "打开文件" << std::endl;
		//------------ 写入头信息 ------------//
		this->generateHeader();
		for (int i = 0; i < 14; i ++ )
			outfile << header[i];
		std::cout << "写入头信息" << std::endl;

		//------------ 写入位图信息 ----------//
		this->generateBitMapInfo();
		for (int i = 0; i < 40; i++)
			outfile << bitMapInfo[i];
		std::cout << "写入位图信息" << std::endl;

		//----------- 写入图像数据 -----------//
		this->generateData(homeworkType);
		unsigned char *data = new unsigned char[width * height * 3];
		memcpy( data, rgb, width * height * 3);
		for (int i = 0; i < width * height * 3; i++)
			outfile << data[i];

		std::cout << "写入像素信息" << std::endl;
		delete[] data;
		// 
		outfile.close();
		std::cout << "关闭文件" << std::endl;
	}

protected:
	void generateHeader()
	{
		int size = width * height * 3;
		header[0] = 0x42;
		header[1] = 0x4d; // 2字节文件类型
		unsigned long bfsize = size + 54;
		memcpy( &header[2], &bfsize, sizeof( bfsize )); //4字节文件大小
		header[6] = 0;
		header[7] = 0;
		header[8] = 0;
		header[9] = 0; // 保留位

		unsigned long bfOffBit = bfsize - size;
		memcpy( &header[10], &bfOffBit, sizeof( bfOffBit ) ); //4字节从头到位图数据的偏移字节数
	}

	void generateBitMapInfo()
	{
		unsigned long biSize = 40;
		memcpy(bitMapInfo, &biSize, sizeof( biSize )); // 4字节信息头大小，即40

		long biWidth = width;
		memcpy( &bitMapInfo[4], &biWidth, sizeof(biWidth) ); // 4字节图像宽度

		long biHeight = height;
		memcpy( &bitMapInfo[8], &biHeight, sizeof( biHeight ) ); // 4字节图像高度

		unsigned short biPlanes = 1;
		memcpy(&bitMapInfo[12], &biPlanes, sizeof(biPlanes)); //2字节位平面数

		unsigned short biBitCount = 24; // 2字节每个像素位数
		memcpy( &bitMapInfo[14], &biBitCount, sizeof( biBitCount ) );

		unsigned long biCompression = 0;
		memcpy( &bitMapInfo[16], &biCompression, sizeof(biCompression)); //4字节压缩类型

		unsigned long biSizeImages = 0;
		memcpy(&bitMapInfo[20], &biSizeImages, sizeof(biSizeImages)); // 4字节图像大小字节数

		long biXPelsPerMeter = 0;
		memcpy(&bitMapInfo[24], &biXPelsPerMeter, sizeof(biXPelsPerMeter) );// 4字节水平分辨率

		long biYPelsPerMeter = 0;
		memcpy(&bitMapInfo[28], &biYPelsPerMeter, sizeof(biYPelsPerMeter));// 4字节垂直分辨率

		unsigned long biClrUsed = 0;
		memcpy(&bitMapInfo[32], &biClrUsed, sizeof(biClrUsed));// 4字节位图实际用到的色彩数

		unsigned long biClrImportant = 0;
		memcpy(&bitMapInfo[36], &biClrImportant, sizeof(biClrImportant));// 4字节本为图中重要的色彩数
		
	}

	void generateData( int homeworkType )
	{
		if (homeworkType == 1) {
			for (int i = 0; i < width * height / 2; i++) {
				rgb[i].r = 0;
				rgb[i].g = 0;
				rgb[i].b = 0;
			}
			for (int i = width * height / 2; i < width * height; i++) {
				rgb[i].r = 255;
				rgb[i].g = 255;
				rgb[i].b = 255;
			}
		}
		else if (homeworkType == 2) {
			for (int i = 0; i < height; i++) {
				if (i % 2 == 0) {
					unsigned char color_r = rand() % 100;
					unsigned char color_g = rand() % 100;
					unsigned char color_b = rand() % 100;
					for (int j = 0; j < width; j++) {
						rgb[j + width * i].r = color_r;
						rgb[j + width * i].g = color_g;
						rgb[j + width * i].b = color_b;
					}
				}
				else {
					unsigned char color_r = rand() % 100;
					unsigned char color_g = rand() % 100;
					unsigned char color_b = rand() % 100;
					for (int j = 0; j < width; j++) {
						rgb[j + width * i].r = color_r;
						rgb[j + width * i].g = color_g;
						rgb[j + width * i].b = color_b;
					}
				}
			}
		}
	}

protected:
	unsigned char header[14];
	unsigned char bitMapInfo[40];

	RGB *rgb;

	int width;
	int height;

	int homeworkType;
};

class BmpOperate final: public BMP 
{
	struct HSI {
		unsigned char h;
		unsigned char s;
		unsigned char i;
	};
	using HSI = struct HSI;

public:
	BmpOperate(  ): BMP()
	{
		hsi = new HSI[ width * height ];
		memset(hsi, 0, width * height * sizeof(HSI));
	}

	BmpOperate(int width_, int height_, int homeworkType_) : BMP(width_, height_, homeworkType_)
	{
		hsi = new HSI[width * height];
		memset(hsi, 0, width * height * sizeof(HSI));

	}

	~BmpOperate()
	{
		delete[] hsi;
	}

	void rgb2hsi()
	{
		const float PI2 = 2 * 3.1415926;
		for (int i = 0; i < width * height; i++) {
			
			float r = static_cast<float>(rgb[i].r);
			float g = static_cast<float>(rgb[i].g);
			float b = static_cast<float>(rgb[i].b);

			float I = (r + b + g) / std::sqrt( 3 );
			float S = 1 - (3 * min3(r, g, b)) / (r + b + g);
			float H, theta;
			
			float temp = (r - g) * (r - g) + (r - b) * (g - b);
			if (temp == 0) temp = 1;
			theta = 1 / ( std::cos( ( 0.5 * ( 2 * r - g - b ) ) / std::sqrt( temp ) ) );

			if (g > b || g == b) H = theta;
			else H = PI2 - theta;

			hsi[i].h = (unsigned char)round( H );
			hsi[i].s = (unsigned char)round( S );
			hsi[i].i = (unsigned char)round( I );
		}
	}

	virtual void generateBMP()
	{
		//------------- 打开文件 --------------//
		std::ofstream outfile;
		outfile.open("./hsitest.bmp", std::ios::out | std::ios::binary | std::ios::app);
		if (!outfile.is_open()) {
			std::cout << "打开文件失败 ..." << std::endl;
			exit(-1);
		}
		std::cout << "打开文件" << std::endl;
		//------------ 写入头信息 ------------//
		this->generateHeader();
		for (int i = 0; i < 14; i++)
			outfile << header[i];
		std::cout << "写入头信息" << std::endl;

		//------------ 写入位图信息 ----------//
		this->generateBitMapInfo();
		for (int i = 0; i < 40; i++)
			outfile << bitMapInfo[i];
		std::cout << "写入位图信息" << std::endl;

		//----------- 写入图像数据 -----------//
		this->generateData(homeworkType);
		unsigned char *data = new unsigned char[width * height * 3];
		memcpy(data, hsi, width * height * 3);
		for (int i = 0; i < width * height * 3; i++)
			outfile << data[i];

		std::cout << "写入像素信息" << std::endl;
		delete[] data;
		// 
		outfile.close();
		std::cout << "关闭文件" << std::endl;
	}

	void medianFilter()
	{

	}

private:
	HSI *hsi;

};

int main()
{
	std::cout << "Program Begins ... " << std::endl;

	//BMP bmp;
	//bmp.generateBMP();

	BmpOperate b;
	b.BMP::generateBMP();
	b.rgb2hsi();
	b.generateBMP();

	return 0;
}