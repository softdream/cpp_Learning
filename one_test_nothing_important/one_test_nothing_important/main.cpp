#include <iostream>
#include <sstream>

template<typename T>
std::string num2String(const T num)
{
	std::stringstream ss;
	ss << num;
	//std::string s = ss.str();
	return ss.str();
}

int main()
{
	/*int sizey = 32;
	int TypefaceNum = (sizey / 8 + ((sizey % 8) ? 1 : 0))*sizey;
	std::cout << "TypefaceNum = " << TypefaceNum << std::endl;
	
	uint8_t num = '0';
	num = num - '0';
	std::cout << "num = " << static_cast<int>(num) << std::endl;*/

	/*int aa = 30;
	std::stringstream ss;
	ss << aa;
	std::string str = ss.str();
	std::cout << str << std::endl;

	std::string s = "num = \n";
	std::cout << s + str << std::endl;*/

	double a = 30.783532;
	std::string s = num2String<double>(a);
	std::cout << "str = " << s << std::endl;
	std::string str = "num = " + s;
	std::cout << "str = " << str << std::endl;
	return 0;
}