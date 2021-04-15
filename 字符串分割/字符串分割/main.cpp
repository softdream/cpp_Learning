#include <iostream>
#include <string>

int number = 0;

int main()
{
	std::string s = "int body[10]";
	std::cout << "s = " << s.data() << std::endl;

	size_t start_pose = s.find("[");
	size_t end_pose = s.find("]");
	if (start_pose != std::string::npos && end_pose != std::string::npos) {
		std::cout << "string length = " << s.length() << std::endl;
		std::cout << "start_pose = " << start_pose << std::endl;
		std::cout << "end_pose = " << end_pose << std::endl;

		std::string arrayLength = s.substr(start_pose + 1, end_pose - start_pose - 1);
		std::cout << "arrayLength = " << arrayLength.data() << std::endl;

		number = std::stoi( arrayLength );
	}

	std::cout << "number = " << number << std::endl;
	return 0;
}