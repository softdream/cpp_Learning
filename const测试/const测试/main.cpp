#include <iostream>

class A
{
public:
	const int& getX() const
	{
		std::cout << "const int getX() const" << std::endl;
		return x;
	}

	const int& getNum() const
	{
		std::cout << "const int getNum() const" << std::endl;
		int a = 100;
		return a;
	}

	/*int getX()
	{
		std::cout << "in getX()" << std::endl;
		return x;
	}*/

private:
	int x = 10;
};

int main()
{
	//std::cout << "x = " << A().getX() << std::endl;
	int x1 = A().getX();
	std::cout << "x1 = " << x1 << std::endl;

	const int x2 = A().getX();
	std::cout << "x2 = " << x2 << std::endl;

	x1++;
	std::cout << "x1 = " << x1 << std::endl;

	int a = A().getNum();
	std::cout << "a = " << a << std::endl;

	return 0;
}