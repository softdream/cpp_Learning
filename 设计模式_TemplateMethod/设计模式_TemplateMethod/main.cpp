#include <iostream>

class Base
{
public:
	Base()
	{

	}
	~Base()
	{

	}

	void operate()
	{
		std::cout << "Base Operate ..." << std::endl;
		this->test();
	}

	virtual void test() = 0;
	/*virtual void test()
	{
		std::cout << "Base test ..." << std::endl;
	}*/
};

class Derivated1: public Base
{
public:
	virtual void test()
	{
		std::cout << "Derivated1 test ..." << std::endl;
	}
};

class Derivated2 : public Base
{
public:
	virtual void test()
	{
		std::cout << "Derivated2 test ... " << std::endl;
	}
};

int main()
{
	Derivated1 d1;
	d1.operate();

	Derivated2 d2;
	d2.operate();

	return 0;
}