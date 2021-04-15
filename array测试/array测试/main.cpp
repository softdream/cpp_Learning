#include <iostream>
#include <array>

std::array<int, 50> arr;

int main()
{
	arr[0] = 1;
	arr[1] = 2;
	int i = 0;
	for (auto it = arr.begin(); it != arr.end(); it++) {
		i++;
	}
	std::cout << "i = " << i << std::endl;

	return 0;
}