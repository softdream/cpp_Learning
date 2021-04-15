#include <iostream>
#include <boost\algorithm\algorithm.hpp>
#include <boost\any.hpp>
#include <map>
#include <type_traits>

boost::any a;

template<typename T = void>
using CallBack = void(*)(T);

std::map<int, void*> cbMap;

void test(int a)
{
	std::cout << "test ..." << a << std::endl;
}

template<typename T>
void subscribe(CallBack<T> cb)
{
	std::cout << "typeid of cb = " << typeid(cb).name() << std::endl;

	a = cb;
	cbMap.insert(std::make_pair(1, reinterpret_cast<void *>(cb)));
}

void test1()
{
	int b = 15;
	//a(15);
}

int main()
{
	subscribe<int>(test);
	std::cout << "-----------------------------" << std::endl;
	std::cout << "typeid of a = " << a.type().name() << std::endl;

	using Type = typename std::remove_reference<a.type()>::type;

	std::cout << "typeid of Type = " << typeid(Type).name() << std::endl;

	return 0;
}