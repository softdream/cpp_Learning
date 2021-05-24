#include <iostream>
#include <memory>



int main()
{
	int *p = new int[10];

	size_t size = ::_msize(p);
	std::cout << "size = " << size << std::endl;

	if (size == sizeof(int))
		delete p;
	else if (size > sizeof(int))
		delete[] p;

	return 0;
}