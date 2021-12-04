#include <iostream>
#include <vector>
#include <fstream>
#include <string.h>
#include <sstream>
#include <iomanip>

#include <stdlib.h>
#include <stdint.h>

typedef struct {
	uint32_t time_stamp;

	float range[360];
}Laser;


int readLaserTXT(Laser *scan)
{
	int count = 0;
	std::string input_file_name = "laser_data.txt";
	std::ifstream input_file(input_file_name.c_str(), std::ifstream::in);

	if (!input_file.is_open()) {
		std::cout << "Failed to open file ..." << std::endl;
		exit(-1);
	}
	std::cout << "open file ..." << std::endl;

	std::string line;
	while (getline(input_file, line)) {
		//std::cout << line << std::endl;
		std::istringstream iss(line);
		std::string tag;
		iss >> tag;
		std::string num;
		if (tag.compare("laser") == 0) {
			
			for (int i = 0; i < 360; i++) {
				iss >> num;
				//std::cout << num << "\t";
				//iss >> scan[count].range[i];
				if (!num.compare("inf")) {
					scan[count].range[i] = 65536;
				}
				else{
					scan[count].range[i] = std::stof( num );
				}
			}
			count++;
		}
	}
	return count;
}

int main()
{
	Laser scanArray[3];

	int ret = readLaserTXT( scanArray );
	std::cout << "scan count: " << ret << std::endl;

	std::cout << "laser ranges: " << std::endl;
	for (size_t i = 0; i < 360; i++) {
		std::cout << scanArray[0].range[i] << "\t";
	}
	std::cout << std::endl;
	
	for (size_t i = 0; i < 360; i++) {
		std::cout << scanArray[1].range[i] << "\t";
	}
	std::cout << std::endl;


	return 0;
}