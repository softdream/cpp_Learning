#include <iostream>
#include <thread>
#include <Windows.h>

template<typename T>
struct Type {
	typedef void(*Action)(T);
};

template<typename T>
class A {
public:

	void testA()
	{
		while (1) {
			send<T>(a);
			Sleep(1000);
		}
	}

	template<typename T>
	void send(T data)
	{
		std::cout<<"data = "<<std::endl;
	}

private:
	T a;
};


class B {
public:
	template<typename T>
	void subscribe(  )
	{ 
		A<T> a;
		std::thread thread1( &A<T>::testA, &a );
		thread1.detach();
	}
};

int main()
{
	B b;
	b.subscribe<int>();

	while (1) {

	}

	return 0;
 }