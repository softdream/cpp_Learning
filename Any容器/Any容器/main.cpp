#include "any.h"
#include <map>
#include <iostream>

std::map<int, Any> testMap;
std::map<int, Any> cbMap;

void cb1(int fd)
{
	std::cout << "cb1" << std::endl << fd << std::endl;
}

template<typename T>
void subscribe(T arg)
{
	const std::type_info& t1 = typeid(T);
	std::cout << " " << t1.name() << std::endl;

}

int main()
{
	subscribe<int>( 6 );

	return 0;
}
