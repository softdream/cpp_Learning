#include <iostream>

const char a[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

int main()
{
	for (int i = 0; i < 10; i ++) {
		a[i] = i ;
	}

	for (int j = 0; j < 10; j ++) {
		std::cout << "a[" << j << "] = " << a[j] << std::endl;
	}

	return 0;
}