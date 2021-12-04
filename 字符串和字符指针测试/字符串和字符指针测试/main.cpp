#include <iostream>
#include <string>
#include <stdlib.h>

int main()
{
	/*char *str = "ddddddd";
	std::cout << "char *str = " << str << std::endl;
	std::string s = "aaaaa";
	
	memcpy(str, s.c_str(), s.size());

	std::cout << "str = " << str << std::endl;*/

	uint8_t count = 1000;
	char num[10];
	itoa(count, num, 10);
	std::cout << num << std::endl;

	return 0;
}