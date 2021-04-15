#include <iostream>
#include <vector>

int main()
{
	/*int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	for (auto it : a) {
		std::cout << it << std::endl;
	}*/
	std::vector<int> a = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	for (auto it : a) {
		std::cout << it << std::endl;
	}


	return 0;
}