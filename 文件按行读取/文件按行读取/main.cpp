#include <iostream>
#include <vector>
#include <fstream>
#include <string.h>
#include <sstream>
#include <iomanip>

#include <stdlib.h>
#include <stdint.h>

template<int Size>
struct LidarScan {
	LidarScan() {}
	~LidarScan() {}

	LidarScan(const LidarScan& obj) : angle_min(obj.angle_min),
		angle_max(obj.angle_max),
		angle_increment(obj.angle_increment),
		scan_time(obj.scan_time),
		time_increment(obj.time_increment),
		range_min(obj.range_min),
		range_max(obj.range_max)
	{
		memcpy(this->ranges, obj.ranges, Size);
		memcpy(this->intensities, obj.intensities, Size);
	}
	LidarScan& operator=(const LidarScan& other)
	{
		angle_min = other.angle_min;
		angle_max = other.angle_max;
		angle_increment = other.angle_increment;
		scan_time = other.scan_time;
		time_increment = other.time_increment;
		range_min = other.range_min;
		range_max = other.range_max;
		memcpy(this->ranges, other.ranges, Size);
		memcpy(this->intensities, other.intensities, Size);
	}

	const int size()
	{
		return Size;
	}
	const int size() const {
		return Size;
	}

	float angle_min;
	float angle_max;
	float angle_increment;
	float scan_time;
	float time_increment;
	float range_min;
	float range_max;
	float ranges[Size];
	float intensities[Size];

};
typedef struct LidarScan<360> LaserScan;


class Simulation
{
public:
	Simulation();
	~Simulation();

	bool openSimulationFile(const std::string &inputFile);
	void closeSimulationFile();

	bool readAFrameData(LaserScan &scan);

	inline const int filePointPose()
	{
		return input_file.tellg();
	}

	inline const int endOfFile()
	{
		return input_file.eof();
	}

private:
	std::ifstream input_file;
	long count;
};

Simulation::Simulation() : count(0)
{

}

Simulation::~Simulation()
{

}

bool Simulation::openSimulationFile(const std::string &inputFile)
{
	input_file.open(inputFile.c_str(), std::ifstream::in);

	if (!input_file.is_open()) {
		std::cout << "Failed to open the simulation file ..." << std::endl;
		return false;
	}

	std::cout << "............Open the Simulation File ............." << std::endl;

}

void Simulation::closeSimulationFile()
{
	return input_file.close();
}

bool Simulation::readAFrameData(LaserScan &scan)
{
	memset(&scan, 0, sizeof(scan));

	std::string line;

	std::getline(input_file, line);{
		std::cout << line << std::endl;
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
					scan.ranges[i] = 65536;
				}
				else {
					scan.ranges[i] = std::stof(num);
				}
			}
			count++;
		}
	}

	return true;
}

int main()
{
	LaserScan scan;
	Simulation s;

	std::string file = "laser_log.txt";
	s.openSimulationFile( file );

	/*s.readAFrameData( scan );
	int pose = s.filePointPose();
	std::cout << "file pose = " << pose << std::endl;

	std::cout << "---------------------------------------------------------" << std::endl << std::endl;

	s.readAFrameData(scan);
	pose = s.filePointPose();
	std::cout << "file pose = " << pose << std::endl;*/

	while (!s.endOfFile()) {
		s.readAFrameData(scan);
		int pose = s.filePointPose();
		std::cout << "file pose = " << pose << std::endl;
		std::cout << "---------------------------------------------------------" << std::endl << std::endl;
	}

	s.closeSimulationFile();

	return 0;
}
