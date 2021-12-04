#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>


template <typename Type>
Type stringToNum(const std::string &str)
{
	std::stringstream iss(str);
	Type num;
	iss >> num;

	return num;
}

int main()
{
	std::string s = "2.6809999943";
	std::cout<< std::setiosflags(std::ios::fixed)<< std::setprecision(10);
	float ret1 = std::stof( s );
	
	//std::cout << "ret1 = " << ret1 << std::endl;
	//std::cout << "ret1 = " << std::setiosflags(std::ios::fixed) << std::setprecision(10) <<ret1 << std::endl;

	//float ret2 = stringToNum<float>( s );
	//std::cout << "ret2 = " << ret2 << std::endl;

	float sum = ret1 * 0.22;
	std::cout << "sum = " << sum << std::endl;

	return 0;
}