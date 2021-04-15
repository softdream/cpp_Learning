#include <iostream>

class Test {
public:
	Test():a(5), b(10)
	{

	}
	Test( int a_, int b_ ): a(a_), b(b_)
	{

	}

	~Test() {

	}

	void print()
	{
		std::cout << "a = " << a << std::endl;
		std::cout << "b = " << b << std::endl;
	}

private:
	int a;
	int b;
};

class Test2 {
public:
	Test2()
	{

	}
	~Test2()
	{

	}

	const Test& createATest()
	{
		Test t(8, 7);
		return t;
	}

};

int main()
{

	Test2 t;
	Test a = t.createATest();
	a.print();
	return 0;
}