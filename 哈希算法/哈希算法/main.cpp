#include <iostream>

// RS Hash Function
unsigned int RSHash(const char *str)
{
	unsigned int b = 378551;
	unsigned int a = 63689;
	unsigned int hash = 0;

	while (*str)
	{
		hash = hash * a + (*str++);
		a *= b;
	}

	return (hash & 0x7FFFFFFF);
}

int main()
{
	std::string test1 = "du";
	const char *p1 = test1.c_str();
	int num1 = RSHash( p1 );
	std::cout << "num1 = " << num1 << std::endl;

	std::string test2 = "dao";
	const char *p2 = test2.c_str();
	int num2 = RSHash(p2);
	std::cout << "num2 = " << num2 << std::endl;

	std::string test3 = "feng";
	const char *p3 = test3.c_str();
	int num3 = RSHash(p3);
	std::cout << "num3 = " << num3 << std::endl;
	
	return 0;
}