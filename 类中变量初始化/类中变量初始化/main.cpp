#include <iostream>

class A {
public:
	const int getA() const
	{
		return a;
	}

	const double getB() const
	{
		return b;
	}

private:
	int a = 10;
	double b = 2.2f;
};

int main()
{
	std::cout << "a = " << A().getA() << std::endl;
	std::cout << "b = " << A().getB() << std::endl;

	return 0;
}