#include <iostream>

int main()
{
	std::string str = "qwertyuiopasdfghjkl";
	std::string sub = str.substr(0, 5);

	std::cout << "str = " << str.c_str() << std::endl;

		return 0;
}