#include <iostream>

class A {
public:
	A(){}
	virtual ~A(){}

	virtual void func1() = 0;

};

class B : public A {
public:
	B(){}
	~B(){}
	virtual void func1()
	{
		std::cerr << "ddddddddddd" << std::endl;
	}
	void func2()
	{
		std::cerr << "func2 ..." << std::endl;
	}
};

int main()
{
	A *a = new B;
	a->func1();
	
	return 0;
}

