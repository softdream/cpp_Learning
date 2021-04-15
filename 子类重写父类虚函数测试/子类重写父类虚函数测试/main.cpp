#include <iostream>

class Base
{
public:
	virtual void test()
	{
		std::cout << "Base::test " << std::endl;
		this->inside();
	}

	void inside()
	{
		std::cout << "inside ..." << std::endl;
	}
};

class Derived: public Base
{
public:
	virtual void test()
	{
		std::cout << "Derived::test " << std::endl;
		this->inside();
	}
};

int main()
{
	Derived d;
	d.test();

	Base b;
	b.test();


	return 0;
}