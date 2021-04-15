#include <iostream>
/*
	Pointer-Like Classes 又叫做智能指针
*/

template<typename T>
class shared_ptr
{
public:
	T& operator*() const
	{
		return *px;
	}

	T* operator->() const
	{
		return px;
	}

	shared_ptr(T* p) : px(p)
	{

	}

	operator long() const
	{
		return (long)(px);
	}

private:
	T* px;
	long* pn;
};

int main()
{
	int a = 100;
	shared_ptr<int> p( &a );
	std::cout << "a = " << *p << std::endl;

	shared_ptr<int> p2( new int );
	*p2 = 200;
	std::cout << "address of p2 = " << p2 << std::endl;
	std::cout << "value of p2 = " << *p2 << std::endl;
	return 0;
}