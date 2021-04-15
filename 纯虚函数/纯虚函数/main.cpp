#include <iostream>

class A {
public:
	virtual void test(){}
	void test2()
	{
		std::cout << "this is not virtual function in class A " << std::endl;
	}
};

class B : public A {
public:
	virtual void test();

};

void B::test()
{
	std::cout << "this is virtual function in class B " << std::endl;
}

A t;
B t2;
int main()
{
	t.test2();
	t2.test();
	return 0;
}