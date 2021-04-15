#include "function_traits.h"
#include <iostream>
#include <string>
#include <map>

template<typename T = void>
using CallBack = void(*)(T);

std::map<int, void*> cbMap;

void test(int a)
{
	std::cout << "test ..." << a << std::endl;
}

void test2(std::string a)
{
	std::cout << "test2 ..." << a << std::endl;
}

template<typename T>
void subscribe(CallBack<T> cb)
{

	std::cout << "cb: " << cb << std::endl;
	std::cout<<typeid( function_traits<decltype(cb)>::args<0>::type ).name()<<std::endl;

	std::cout << "typeid of cb = " << typeid(cb).name() << std::endl;

	cbMap.insert(std::make_pair(1, reinterpret_cast<void *>(cb)));

}

void call()
{
	auto it = cbMap.find(1);
	std::cout << "it->second = " << it->second << std::endl;
	std::cout << "typeid of it->second = " <<typeid(it->second).name() << std::endl;

}


int main()
{
	//subscribe<int>( test );
	std::cout << "------------------------------------" << std::endl;
	subscribe<std::string>(test2);
	call();
	return 0;
}

