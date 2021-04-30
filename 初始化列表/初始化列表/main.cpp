#include <iostream>
#include <vector>
#include <algorithm>

struct Data1{
	int a1;
	int a2;

	int c[4];

	std::vector<int> d;

	Data1(int a1_, int a2_, std::initializer_list<int> &&c_) : a1(a1_), a2(a2_)
	{
		std::copy( c_.begin(), c_.end(), c );
	}
};

int main()
{
	int a1[4] = { 10, 20, 30, 40 };

	Data1 d(1, 2, {10, 20, 30, 40});
	//Data1 d(1, 2, a1);

	for (int i = 0; i < 4; i++)
		std::cout << d.c[i] << std::endl;

	return 0;
}