#include <iostream>

class Father {
public:
	virtual void test()
	{
		std::cout << "this is father ..." << std::endl;
	}
};


class Son : public Father {
public:
	virtual void test()
	{
		std::cout << "this is son ..." << std::endl;
	}
};

void fun( Father &p )
{
	p.test();
}

int main()
{
	Father  f;
	Son s;
	fun( f );
	fun( s );
	return 0;
}