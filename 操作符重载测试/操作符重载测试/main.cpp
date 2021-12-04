#include <iostream>
#include <vector>

std::vector<int> operator+(std::vector<int> &a, std::vector<int> &b)
{
	return std::vector<int>{ a[0] + b[0], a[1] + b[1], a[2] + b[2] };
}

int main()
{
	std::vector<int> a{1, 2, 3};
	std::vector<int> b{ 1, 2, 3 };

	std::vector<int> c = a + b;

	for (auto it : c) {
		std::cout << it << std::endl;
	}

	return 0;
}