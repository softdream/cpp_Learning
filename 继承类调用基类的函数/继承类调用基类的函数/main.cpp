#include <iostream>

class A {
public:
	A():a(10){}
	int getData()
	{
		return a;
	}

private:
	int a;
};

class B :public A {
public:
	void test()
	{
		std::cout << getData() << std::endl;
	}
};


int main()
{
	B b;
	b.test();
	return 0;
}