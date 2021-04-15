#include <iostream>

class Fraction
{
public:
	//---------- Non-explicit-one-argument ctr ---------//
	Fraction(int num, int den = 1):numerator(num), denominator(den)
	{

	}

	// 重载运算符
	Fraction operator+(const Fraction& f)
	{
		return Fraction( numerator + f.numerator, denominator + f.denominator );
	}

	//------------ 转换函数 -------------//
	/*operator double() const
	{
		std::cout << "Conversion Function ..." << std::endl;
		return (double)(numerator / denominator);
	}*/

	void print() const
	{
		std::cout << "numerator = " << numerator << ", denominator = " << denominator << std::endl;
	}

private:
	int numerator;
	int denominator;
};

int main()
{
	Fraction f(3, 5);

	//double d = 8.0f + f; // 调用conversion function将 f 转化为double
	//std::cout << "d = " << d << std::endl;
	
	Fraction d2 = f + 4; // 非显式构造函数不能与转换函数共存，
						//将构造函数声明为显示的可以避免这种情况,可避免隐式转换
	d2.print();

	return 0;
}