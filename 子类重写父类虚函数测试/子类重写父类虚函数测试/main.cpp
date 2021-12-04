#include <iostream>

class Base
{
public:
	virtual void test()
	{
		std::cout << "Base::test " << std::endl;
		this->inside();
	}

	void inside()
	{
		std::cout << "inside ..." << std::endl;
	}
};

class Derived: public Base
{
public:
	virtual void test()
	{
		std::cout << "Derived::test " << std::endl;
		this->inside();
	}
};

int main()
{
	std::cout << "-------------- 1 ---------------" << std::endl;
	Derived d;
	d.test();

	std::cout << "-------------- 2 ---------------" << std::endl;
	Base b;
	b.test();

	std::cout << "-------------- 3 ---------------" << std::endl;
	Base c;
	c.Base::test(); // 子类中调用父类的同名函数

	std::cout << "-------------- 4 ---------------" << std::endl;
	Base *e = dynamic_cast<Base *>( &d ); // 子类指针转化为父类指针
	e->test();

	std::cout << "-------------- 5 ---------------" << std::endl;
	Base f = static_cast<Base>( d ); // 子类强制转化为父类
	f.test();

	std::cout << "-------------- 6 ---------------" << std::endl;
	Derived *h = dynamic_cast<Derived *>( &b ); // 父类指针转化为子类，会做类型检查，更安全
	if (h == nullptr) {
		std::cerr << "null ptr ..." << std::endl;
	}
	else {
		h->test();
	}
	

	std::cout << "-------------- 7 ---------------" << std::endl;
	//Derived g = static_cast<Derived>(b); // 父类转化为子类，Error C2440: “static_cast”: 无法从“Base”转换为“Derived”
	//g.test();

	return 0;
}