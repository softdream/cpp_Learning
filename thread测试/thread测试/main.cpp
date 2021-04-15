#include <thread>
#include <iostream>

class Test {
public:
	Test() :a(100)
	{

	}
	void test()
	{
		std::cout << "a = " << a << std::endl;

	}

private: 
	int a;
};

class BTest{
public:
	void subscribe()
	{
		Test t;
		std::thread t1( &Test::test, &t);
		t1.join();
	}
};

int main()
{
	BTest bt;
	bt.subscribe();
}


