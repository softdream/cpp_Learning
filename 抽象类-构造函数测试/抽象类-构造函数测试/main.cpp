#include<iostream>
#include <vector>

class A{
public:
	A() {

	}
	virtual ~A()
	{

	}

	virtual void print() = 0;

	virtual void printList() = 0;

};

class B : public A {
public:
	B(): a( 10 ), b( 20 )
	{
		for (int i = 1; i <= 5; i++) {
			list.push_back(i);
		}
	}
	virtual ~B() {

	}

	B(const B &obj):a( obj.a ), b( obj.b ), list( obj.list )
	{
		std::cout << "copy constructor of Class B ..." << std::endl;
	}

	B& operator=(const B &other)
	{
		std::cout << "asignment constructor of Class B ..." << std::endl;
		if (this == &other) return *this;
		a = other.a;
		b = other.b;
		list = other.list;
		return *this;
	}
	
	virtual void print()
	{
		std::cout << "a = " << a << std::endl;
		std::cout << "b = " << b << std:: endl;
	}

	virtual void printList()
	{
		int i = 1;
		for (auto it = list.begin(); it != list.end(); it++,  i ++) {
			std::cout << "list[" << i << "] = " << *it << std::endl;
		}
	}

private:
	int a;
	int b;
	std::vector<int> list;
};


class C {
public:
	C() {
		a = new B;
	}

	C(const C &obj):a( obj.a ), c( obj.c )
	{
		std::cout << "copy constructor of Class C ... " << std::endl;
	}

	~C() {

	}

	void print()
	{
		a->printList();
	}

	void setc( int c_ )
	{
		c = c_;
	}

	int getc()
	{
		return c;
	}

private:
	A *a;

	int c;
};

class D {
public:

	D() 
	{

	}
	~D()
	{

	}

	C getC()
	{
		C c;
		c.setc( 100 );
		return c;
	}
};

int main()
{
	/*A *a = new B;

	a->print();

	std::cout << "---------------------------" << std::endl;


	A *b;

	b = a;

	b->print();
	b->printList();
	std::cout << "---------------------------" << std::endl;

	A *c(b);
	c->printList();*/
	/*B a;
	a.printList();
	std::cout << "---------------------------" << std::endl;
	B b;
	b = a;
	b.printList();
	
	std::cout << "---------------------------" << std::endl;
	B c(b);
	c.printList();*/

	/*C a;
	a.print();

	C b( a );
	b.print();*/

	D d;
	C c = d.getC();
	std::cout << "c = " << c.getc() << std::endl;

	return 0;
}