#include <iostream>
#include <bitset>

#include "runLengthCode.h"

int main()
{
	char str[10] = "hello";
	std::cout << "str = " << str << " " << strlen(str) << std::endl;

	pcs::charRLC rlc;
	rlc.coding( str, 5 );

	return 0;
}