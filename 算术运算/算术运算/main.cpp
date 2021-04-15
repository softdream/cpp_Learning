#include <iostream>

template<typename T>
class Caculate {
public:
	Caculate(){}
	Caculate(T a_, T b_) : a(a_), b(b_)
	{

	}
	~Caculate(){}
	T max()
	{
		if (a > b) return a;
		else return b;
	}

	T min()
	{
		if (a > b) return b;
		else return a;
	}

	T add()
	{
		return a + b;
	}

	T minus()
	{
		return a - b;
	}

	T multiple()
	{
		return a * b;
	}

	T dive()
	{
		return a / b;
	}

private:
	T a;
	T b;
};

int main()
{
	int a, b;
	std::cin >> a >> b;
//	std::cout << "a = " << a << "b = " << b << std::endl;
	double c, d;
	std::cin >> c >> d;
//	std::cout << "c = " << c << "d = " << d << std::endl;
	
	Caculate<int> c1( a, b );
	std::cout << c1.max() <<" "<< c1.min() <<" "<< c1.add() <<" "<< c1.minus() <<" "<< c1.multiple() <<" "<< c1.dive() << std::endl;

	Caculate<double> c2( c, d );
	std::cout << c2.max() << " " << c2.min() << " " << c2.add() << " " << c2.minus() << " " << c2.multiple() << " " << c2.dive() << std::endl;

	return 0;
}