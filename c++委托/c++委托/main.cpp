#include "delegate.h"
#include <iostream>
#include <memory>

void test()
{
	std::cout << "hello ..." << std::endl;
}


std::shared_ptr<CMultiDelegate> ptr;
void triger()
{
	CMultiDelegate *e = nullptr;
	*e += newDelegate(test);
}

int main()
{
	std::cout << "program begins ..." << std::endl;

	triger();
	return 0;
}