#include <iostream>

int *ad;

template<typename T>
void test()
{
	T a;
	std::cout << "address of a = " << &a << std::endl;
	ad = &a;
}

int main()
{
	test<int>();
	std::cout << "address of ad = " << ad << std::endl;
	return 0;
}