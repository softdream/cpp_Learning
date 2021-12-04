#include <iostream>
#include <initializer_list>

class MyType
{
public:
	MyType() : a(0), b(0), c(0)
	{
		std::cout << "default constructor ... " << std::endl;
	}

	MyType(const int a_, const int b_, const int c_) : a(a_), b(b_), c(c_)
	{
		std::cout << "overload constructor ... " << std::endl;
	}

	MyType( const std::initializer_list<int>& tmp )
	{
		std::cout << "initializer_list overload constructor ... " << std::endl;
		a = *tmp.begin();
		b = *tmp.begin() + 1;
		c = *tmp.begin() + 2;
	}

	const MyType& operator=( const MyType& rhs )
	{
		std::cout << "copy assignemnt constructor ... " << std::endl;
		if (this == &rhs) return *this;

		a = rhs.a;
		b = rhs.b;
		c = rhs.c;

		return *this;
	}

	MyType( const MyType& rhs ):a(rhs.a), b(rhs.b), c(rhs.c)
	{
		std::cout << "copy constructor ... " << std::endl;
	}

	void print() const
	{
		std::cout << "a = " << a << std::endl;
		std::cout << "b = " << b << std::endl;
		std::cout << "c = " << c << std::endl;
	}

public:
	int a;
	int b;
	int c;
};

MyType ret;
const MyType operator+=(const MyType& x1, const MyType& x2)
{
	ret = MyType(x1.a + x2.a, x1.b + x2.b, x1.c + x2.c);

	std::cout << "ret = " << std::endl;
	ret.print();

	return ret;
}

int main()
{
	MyType a({1,2,4});
	a.print();

	/*MyType b[3] = { {1, 3, 4}, {1, 3, 4}, {1, 3, 4} };

	for (int i = 0; i < 3; i++) {
		b[i].print();
	}*/

	MyType sum( a );
	sum += a;
	sum.print();

	return 0;
}