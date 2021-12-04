#include <iostream>

template<typename T>
class Base
{
public:
	Base( T x1_, T x2_ ): x1(x1_), x2(x2_)
	{

	}
	void print()
	{
		std::cout << "x1 = " << x1 << std::endl;
		std::cout << "x2 = " << x2 << std::endl;
	}

protected:
	T x1;
	T x2;

};

typedef Base<int> B;

class Derived :public B
{
public:
	Derived(int x1_, int x2_) : B(x1_, x2_)
	{

	}

	void print()
	{
		std::cout << "derived " << std::endl;
		std::cout << "x1 = " << x1 << std::endl;
		std::cout << "x2 = " << x2 << std::endl;
	}
};

int main()
{
	Derived d(40, 50);
	d.print();

	return 0;
}