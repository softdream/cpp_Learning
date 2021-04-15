#include <iostream>

class Father {
public:
	Father() : a(0), b(0), c(0)
	{
		std::cout << "父类初始化1" << std::endl;
	}
	Father( int a_, int b_, int c_ )
	{
		std::cout << "父类初始化2" << std::endl;
	}

private:
	int a;
	int b;
	int c;
};

class Child : public Father{
public:
	Child():Father( 0, 0, 0 ) {
		std::cout << "子类初始化" << std::endl;
	}
};

int main()
{
	Child c;
	return 0;
}

