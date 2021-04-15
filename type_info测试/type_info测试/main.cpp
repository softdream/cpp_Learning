#include <iostream>
#include <typeinfo>
#include <string>

std::type_info &type ;

template<typename T>
void test( T a )
{
	type = typeid(T);
	std::cout << "a = " << a << std::endl;
}

uint8_t recvBuff[10] = {1, 1, 1, 1, 1, 1, 1,1,1};

int main()
{
/*	int a = 15;

	using type1 = typename decltype(a);
	test<type1>(4);
	*/

	std::cout<<"typename = "<<type.name()<<std::endl;
	return 0;
}