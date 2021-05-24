#include <iostream>

class T1 {
public:
	T1():x1(10), y1(10)
	{

	}
	T1(int x1_, int y1_) :x1(x1_), y1(y1_)
	{

	}
	void print()
	{
		std::cout << "T1" << std::endl;
	}
protected:
	int x1;
	int y1;
};

class T2 {
public:
	T2() :x2(20), y2(20)
	{

	}
	T2(int x2_, int y2_) : x2(x2_), y2(y2_)
	{

	}

	void print()
	{
		std::cout << "T2" << std::endl;
	}
protected:
	int x2;
	int y2;
};

template<typename T>
class Test : public T
{
public:
	Test() :T(50, 50)
	{

	}
	void test()
	{
		print();
	}
};

int main()
{
	Test<T2> t1;
	t1.test();

	return 0;
}