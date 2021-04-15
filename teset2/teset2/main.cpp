#include <iostream>
#include <fstream>
#include<sstream>
#include "timestamp.h"

void logInit( std::ofstream &outfile_ )
{
	std::stringstream ss;
	SYSTEMTIME tn = getCurrentTime();
	ss << "./" << tn.wYear << "-" << tn.wMonth << "-" << tn.wDay << "-" << tn.wHour << "-" << tn.wMinute;

	std::string filepath;
	ss >> filepath;
	outfile_ = std::ofstream(filepath, std::ios::app);
	if (outfile_.fail()) {
		std::cout << "error" << std::endl;
		exit(-1);
	}
}

int main()
{
	std::ofstream outfile;
	logInit( outfile );

	return 0;
}
