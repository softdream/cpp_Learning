#include "delegate.h"
#include <iostream>
using namespace function_delegate_pri;

class myClass {
public:
	void test(std::string a, int b)
	{
		using type = typename decltype(a);
		std::cout << "a = " << a.data() << std::endl;
		std::cout << "b = " << b << std::endl;
	}
};


int main()
{
	std::string a = "Hello World ...";
	myClass my;
	function_delegate<> d( &my, &myClass::test );

	d( a, 15 );
	return 0;
}

