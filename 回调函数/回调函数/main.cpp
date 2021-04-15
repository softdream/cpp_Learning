#include <iostream>
#include <memory>
#include <map>
#include <functional>
#include <windows.h>

typedef std::function<void(void *)> CallBack;
//void(*CALLBACK)(void *arg);

typedef struct {
	CallBack callback;
	void *arg;
}Event;

std::map<int, Event> callbacksMap;

void test1(void *arg)
{
	std::cout << "arg = " << arg << std::endl;
	int a;
	memcpy(&a, arg, sizeof(int));
	std::cout << "a = " << a <<std::endl;
}


void test2(int arg)
{

}

template<typename T>
void test(CallBack callback)
{
	T a;
	Event t1;
	t1.callback = callback;
	t1.arg = &a;
	std::cout << "arg === " << &a << std::endl;
	callbacksMap.insert( std::make_pair( 1, t1 ) );
}

int main()
{
	int b = 100;
	std::cout << "&b = " << &b << std::endl;

	test<int>( test1 );

	while (1) {
		auto it = callbacksMap.find(1);
		it->second.arg = &b;

		it->second.callback(it->second.arg);
	//	std::cout << "arg = " << it->second.arg << std::endl;
		Sleep( 1000 );
	}

	return 0;
}