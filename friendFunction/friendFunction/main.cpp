#include <iostream>

class Test
{
public:
	Test() :a(5)
	{
		t = this;
	}

	static void test();
	static Test *t;

private:
	int a;
};

void Test::test()
{
	std::cout << "a = " << t->a << std::endl;
}

Test *Test::t = NULL;

int main()
{
	Test a;
	//Test::t = &a;
	a.test();

	return 0;
}
