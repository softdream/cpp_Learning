#include <iostream>
#include <sstream>
#include <fstream>

int main()
{
	std::ifstream binFile;
	binFile.open( "0.jpg", std::ifstream::binary );
	if (!binFile) {
		std::cerr << "Open file failed ..." << std::endl;
		return -1;
	}

	binFile.seekg( 0, std::ios::end );
	unsigned int length = binFile.tellg();

	std::cout << "file length = " << length << "bytes" << std::endl;

	unsigned char *data = new unsigned char[ length + 1 ];
	
	binFile.seekg( 0, std::ios::beg );
	binFile.get();

	if (!binFile.eof()) {
		std::cout << "target reading ..." << std::endl;
		binFile.read( reinterpret_cast<char*>(data), sizeof(char) * length );// 读入文件流
		std::cout << "finished reading ..." << std::endl;
	}

	binFile.close(); // 关闭文件

	for (unsigned int i = 0; i < length; i++) {
		//std::cout << std::hex << data[i] << " "<< std::endl;
		printf( "%x ", data[i] );
	}

	delete[] data;

	return 0;
}