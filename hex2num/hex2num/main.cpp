#include <sstream>
#include <iostream>
#include <string>

template<typename T>
const T hexStr2num(const std::string &hexStr) {
	std::stringstream ss;
	T num;

	ss << std::hex << hexStr; //选用十六进制输出
	ss >> num;

	return num;
}

int main()
{
	std::string str = "F1";

	int num = hexStr2num<int>(str);

	std::cout << "num = " << num << std::endl;

	unsigned char code = static_cast<char>(num);
	for (int i = 7; i >= 0; i--)
	{
		std::cout << ((code >> i) & 1);
	}
	std::cout << std::endl;

	std::cout << "code = " << (int)code << std::endl;


	
	return 0;
}
