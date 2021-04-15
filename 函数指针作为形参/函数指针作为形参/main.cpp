#include <iostream>
#include <functional>
#include <map>
#include <memory>
#include <typeinfo>
#include "any.h"


template<typename T>
T arg;

template<typename T = void>
using CallBack = void(*)(T);

template<typename T>
using CB = std::function<void(T)>;

std::map<int, void*> cbMap;

void test( int a )
{
	std::cout << "test ..." <<a<< std::endl;
}

template<typename T>
void subscribe(CallBack<T> cb)
{
	T a;
	cbMap.insert( std::make_pair( 1, reinterpret_cast<void *>(cb)) );
}

void call()
{
	auto it = cbMap.find(1);
	using type = typename decltype(arg<int>);
	CallBack<type> c = reinterpret_cast<CallBack<type>>(it->second);
	c( 5 );
}


int main()
{
	subscribe<int>(test);

	call();

	return 0;
}