#include <iostream>

template< class T >
class A {
public:
	A():a(5)
	{
		
	}
	void test( T &b_ )
	{
		b = b_;
		std::cout << "a = " << a << std::endl;
		std::cout << "b = " << b << std::endl;
	}
private:
	int a;
	T b;
};

template< class T >
class ADD {
private:
	T x;
	T y;

public:
	ADD( T x_, T y_ ) {
		x = x_;
		y = y_;
	}
	T add( );
};

template< class T >
T ADD<T>::add()
{
	return x + y;
}

int main()
{
	A<int> a;
	int b = 10;
	a.test( b );

	ADD<int> n( 10, 10 );
	std::cout << "sum = " << n.add() << std::endl;
 	return 0;
}