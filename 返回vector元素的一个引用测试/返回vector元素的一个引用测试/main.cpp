#include <vector>
#include <iostream>

int& getElement(std::vector<int> &vec, int index) {
	return vec[index];
}

void printVec(std::vector<int> &vec)
{
	std::cout << "----------------------" << std::endl;
	for (auto it : vec) {
		std::cout << it << std::endl;
	}
	std::cout << "----------------------" << std::endl;
}

int main()
{
	std::vector<int> vec = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	int &a = getElement( vec, 3 );
	std::cout << "a = " << a << std::endl;

	a = 300; //这里a只是vector的第四个元素的别名而已，改变a也就是改变了第四个元素的值。
	//getElement(vec, 3) = 300;

	printVec(vec);

	return 0;
}