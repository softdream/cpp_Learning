#include <iostream>

// 类集成 
// c++14

class Base // Base 是基类（父类）
{
public:
	Base()
	{
		std::cout << " Base Default Constructor ..." << std::endl;
	}

	Base(const int a_, const int b_) : a(a_), b(b_)
	{
		std::cout << " Base Overloaded Constructor ..." << std::endl;
	}

	~Base()
	{
		std::cout << " Base Default DeConstructor ..." << std::endl;
	}

	void setA(const int a_)
	{
		a = a_;
	}

	void setB(const int b_)
	{
		b = b_;
	}

	const int getA() const // 第二个const表明这个函数不能类的成员变量a，即这个函数对变量a只有可读的权限
	{
		return a;
	}

	void printBase()
	{
		std::cout << "a = " << a << std::endl;
		std::cout << "b = " << b << std::endl;
	}

	virtual void test(int a)
	{
		// 父类子类操作不一样
		std::cout << "Base test ..." << std::endl;
	}

protected:

	int a = 10;
	int b = 10;
};

//  Derived 是派生类（继承类）的名字
class Derived : public Base // 一般单继承就可以了
{
public:
	// 子类的默认构造函数写法
	Derived()
	{
		std::cout << " Derived  Default Constructor ..." << std::endl;
	}

	// 子类的重载构造函数
	Derived(const int a_, const int b_, const int c_) : Base(a_, b_), c(c_)
	{
		std::cout << " Derived Overloaded Constructor ..." << std::endl;
	}

	~Derived()
	{
		std::cout << " Derived Default DeConstructor ..." << std::endl;
	}

	void printDerived()
	{
		std::cout << "a = " << a << std::endl;
		std::cout << "b = " << b << std::endl;
		std::cout << "c = " << c << std::endl;
	}

	void test(int a)
	{
		std::cout << "Derived test ..." << std::endl;
	}

private:
	int c = 20;
};

// 虚函数, c++的多态就基于是虚函数实现的，动态函数
// 模板 静态多态 泛型编程

int main()
{
	Derived d( 100, 200, 400 );

	d.printDerived();

	d.Base::test(10);

	return 0;
}