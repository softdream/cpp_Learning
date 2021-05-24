#include <iostream>

class Test {
public:
	Test(int x_, int y_) : x(x_), y(y_)
	{

	}

	bool operator==(Test &rhs) 
	{
		return ( (x == rhs.x) && ( y == rhs.y ) );
	}
private:
	int x;
	int y;
};

int main()
{
	Test t1(10, 20);
	Test t2(10, 20);
	Test t3( 10, 30 );

	if (t1 == t2) {
		std::cout << "equal" << std::endl;
	}

	if (!(t1 == t3)) {
		std::cout << "not equal " << std::endl;
	}

	return 0;
}