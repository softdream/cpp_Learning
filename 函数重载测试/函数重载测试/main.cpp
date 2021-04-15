#include <iostream>

template< class T >
class A {
private:
	T x;
	T y;

public:
	A(  )
	{
	
	}
	A( T x_, T y_ )
	{
		x = x_;
		y = y_;
	}
	T add();

	A operator+(const A &t)
	{
		A sum;
		sum.x = this->x + t.x;
		sum.y = this->y + t.y;
		return sum;
	}

	void Print()
	{
		std::cout << "x = " << x << " y = " << y << std::endl;
	}
};

template< class T >
T A<T>::add()
{
	return x + y;
}

class B {
private:
	int x;
	int y;
public:
	B(  ) 
	{

	}
	B(int x_, int y_) {
		x = x_;
		y = y_;
	}

	B operator+(const B &t)
	{
		B sum;
		sum.x = this->x + t.x;
		sum.y = this->y + t.y;
		return sum;
	}
	void Print()
	{
		std::cout << "x = " << x << " y = " << y << std::endl;
	}
};

int main()
{
	A<int> a1( 10, 10 );
	A<int> a2( 20, 20 );
	A<int> a3;

	a3 = a1 + a2;
	a3.Print();

	B b1( 10, 10 );
	B b2( 20, 20 );
	B b3;
	b3 = b1 + b2;
	b3.Print();

	return 0;
}