#include <iostream>

class B {
public:
	int b;

	B()
	{
		std::cout << "----- B Constructor -----" << std::endl;
		f();// 构造函数里调用的永远是自身的f()
		// 因为实例化D的时候，父类B的构造函数先执行，这时候D还没有来得及对f（）进行重写
	}

	virtual void f()
	{
		std::cout << "virtual B::f()" << std::endl;
	}

	void g()
	{
		std::cout << "B::g()" << std::endl;
		//B::f();//调用的是自身的f()
		f();//调用的是D的f()
	}
};

class D :public B {
public:
	D()
	{
		std::cout << "----- D Constructor -----" << std::endl;
		f();
	}
	virtual void f()
	{
		std::cout << "virtual D::f()" << std::endl;
	}

	void h()
	{
		std::cout << "non virtual D::h()" << std::endl;
	}
};

int main()
{
	//D d;
	//d.g();

	//B *b = new D();
	//b->g();

	B *b = new B();
	D *d = dynamic_cast<D *>(b);
	d->h();

	return 0;
}