#include <iostream>

class Base {
public:
	Base(int x_, int y_) :x(x_), y(y_)
	{
		std::cout << "Base address; " << this << std::endl;
	}

	int add()
	{
		return x + y;
	}

	void printRet()
	{
		int ret = this->add();
		std::cout << "result = " << ret << std::endl;
	}

private:
	int x;
	int y;
};

class Derivate : public Base {
public:
	Derivate(int x_, int y_, int c_, int d_) : Base(x_, y_), c(c_), d(d_)
	{
		std::cout << "Derivate address; " << this << std::endl;
	}

	int add()
	{
		return c + d;
	}

	void printRet2()
	{
		
		int ret = Base::add();
		std::cout << "result = " << ret << std::endl;
	}


private:
	int c;
	int d;
};

int main()
{
	/*Base *base = new Base(10, 20);
	base->add();
	base->printRet();*/

	Derivate *der = new Derivate( 10, 20, 30, 40 );
	int ret = der->add();
	der->printRet();

	der->printRet2();

	return 0;
}