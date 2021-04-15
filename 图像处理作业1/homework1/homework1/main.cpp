#include <iostream>
#include <string> 
#include <fstream> 

#pragma pack(2)

namespace homework1 {
//bfType：2字节，文件类型；
//bfSize：4字节，文件大小；
//bfReserved1：2字节，保留，必须设置为0；
//bfReserved2：2字节，保留，必须设置为0；
//bfOffBits：4字节，从头到位图数据的偏移；
struct BmpFileHeader {
	unsigned short bfType;
	unsigned long bfSize;
	unsigned short bfReserved1;
	unsigned short bfReserved2;
	unsigned long bfOffBits;
};
typedef struct BmpFileHeader BmpFileHeader;

//biSize：4字节，信息头的大小，即40；
//biWidth：4字节，以像素为单位说明图像的宽度；
//biHeight：4字节，以像素为单位说明图像的高度，同时如果为正，说明位图倒立（即数据表示从图像的左下角到右上角），如果为负说明正向；
//biPlanes：2字节，为目标设备说明颜色平面数，总被设置为1；
//biBitCount：2字节，说明比特数 / 像素数，值有1、2、4、8、16、24、32；
//biCompression：4字节，说明图像的压缩类型，最常用的就是0（BI_RGB），表示不压缩；
//biSizeImages：4字节，说明位图数据的大小，当用BI_RGB格式时，可以设置为0；
//biXPelsPerMeter：表示水平分辨率，单位是像素 / 米，有符号整数；
//biYPelsPerMeter：表示垂直分辨率，单位是像素 / 米，有符号整数；
//biClrUsed：说明位图使用的调色板中的颜色索引数，为0说明使用所有；
//biClrImportant：说明对图像显示有重要影响的颜色索引数，为0说明都重要；
struct BmpFileInfoHeader {
	unsigned long biSize;
	unsigned long biWidth;
	unsigned long biHeight;
	unsigned short biPlanes;
	unsigned short biBitCount;
	unsigned long biCompression;
	unsigned long biSizeImages;
	long biXPelsPerMeter;
	long biYPelsPerMeter;
	unsigned long   biClrUsed;
	unsigned long   biClrImportant;
};
typedef struct BmpFileInfoHeader BmpFileInfoHeader;

/* 构建Bmp图片的类 */
class myBmpMap {
	typedef struct {
		unsigned char rgb;
	}EightBitRGB;
	typedef struct {
		unsigned char r;
		unsigned char g;
		unsigned char b;
	}TweentyFourBitRGB;
public:
	myBmpMap( int height_, int width_, int colorType_ ): height(height_),
														width(width_),
														colorType(colorType_)
	{
		initParam();
	}
	myBmpMap() : height(100),
				width(100),
				colorType(1)
	{
		initParam();
	}
	~myBmpMap() {}

	void generateBMP( std::string type )
	{
		std::ofstream outfile;
		outfile.open( "./worktest1.bmp", std::ios::out|std::ios::binary | std::ios::app);
		if (!outfile.is_open()) {
			std::cerr << "Open File Faile ..." << std::endl;
			exit(-1);
		}
		std::cout << "bmpHeader size = " << sizeof(BmpFileHeader) << " bmpInfoHeader size = " << sizeof(bmpInfoHeader) << std::endl;
		unsigned char *header = new unsigned char[ sizeof(bmpHeader) + sizeof(bmpInfoHeader) ];
		memset( header, 0, sizeof(header) );
		memcpy( header, &bmpHeader, sizeof(bmpHeader));
		memcpy( &header[sizeof(bmpHeader)], &bmpInfoHeader, sizeof(bmpInfoHeader));

		/*for (int i = 0; i < 54; i++) {
			outfile << header[i];
		}*/
		outfile.write( (const char*)header, 54 );
		delete[] header;

		if (!type.compare("blackwhite")) {
			std::cout << "write a black white picture ..." << std::endl;
			EightBitRGB *data = new EightBitRGB[width * height];
			int i = 0;
			for (; i < width * height * 0.5; i++) {
				data[i].rgb = 0;
				//outfile << data[i].rgb;
			}
			for (; i < width * height; i++) {
				data[i].rgb = 255;
				//outfile << data[i].rgb;
			}


			delete[] data;
		}
		
		outfile.close();
	}

private:
	void initParam()
	{
		int Size = width * height * colorType;
		bmpHeader.bfType = 0X4d42;
		bmpHeader.bfSize = Size + sizeof(BmpFileHeader) + sizeof(BmpFileInfoHeader);
		std::cout << "bmpHeader.bfsize = " << bmpHeader.bfSize << std::endl;
		bmpHeader.bfReserved1 = 0;
		bmpHeader.bfReserved2 = 0;
		bmpHeader.bfOffBits = bmpHeader.bfSize - Size;

		bmpInfoHeader.biSize = sizeof(BmpFileInfoHeader);
		bmpInfoHeader.biWidth = width;
		bmpInfoHeader.biHeight = height;
		bmpInfoHeader.biPlanes = 1;
		bmpInfoHeader.biBitCount = colorType * 8;
		bmpInfoHeader.biCompression = 0;
		bmpInfoHeader.biSizeImages = Size;
		bmpInfoHeader.biXPelsPerMeter = 0;
		bmpInfoHeader.biYPelsPerMeter = 0;
		bmpInfoHeader.biClrUsed = 0;
		bmpInfoHeader.biClrImportant = 0;
	}
private:
	BmpFileHeader bmpHeader;
	BmpFileInfoHeader bmpInfoHeader;
	int height;
	int width;
	int colorType;
};

}

int main()
{
	homework1::myBmpMap bmp( 100, 100, 1 );
	bmp.generateBMP( "blackwhite" );
	return 0;
}