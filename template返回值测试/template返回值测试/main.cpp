#include<iostream>
#include <functional>
#include <map>

using Callback = std::function<void()>;

std::map<int, Callback > cbMap;

char sendBuff[10] = { 'H', 'e', 'l', 'l', 'o' };

typedef struct {
	char arg1;
	char arg2;
	char arg3;
	char arg4;
}Arg;

void test()
{
	std::cout << "test" << std::endl;
}

template<typename T>
T& getData()
{
	T a;
	std::cout << "typeid = " << typeid(a).name() << std::endl;
	memset( &a, 0, sizeof( a ) );
	memcpy( &a, sendBuff, sizeof( a ));

	return a;
}

void subscribe(Callback cb)
{
	cbMap.insert( std::make_pair( 1, cb ) );
}

void call()
{
	auto it = cbMap.find(1);
	it->second();
}


class T {
public:
	static void test2()
	{
		std::cout << "test2 ..." << std::endl;
	}
};

int main()
{
	Arg a = getData<Arg>();
	std::cout << "a.arg1 = " << a.arg1<< std::endl;

	subscribe( test );

	call();

	test2();

	return 0;
}