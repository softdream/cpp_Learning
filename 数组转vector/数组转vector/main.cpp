#include <vector>
#include <iostream>

int main()
{
	std::vector<float> v;
	float a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };

	v.assign( a, a+ 10 );

	for (auto it : v) {
		std::cout << "it = " << it << std::endl;
	}

	return 0;
}