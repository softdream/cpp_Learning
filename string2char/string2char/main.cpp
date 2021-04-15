#include<iostream>

#include <string.h>

int main()
{
	std::string str = "Hello world";
	char s[100] = {};
	strcpy_s( s, str.c_str() );
	std::cout << "s = " << s << std::endl;
	return 0;
}