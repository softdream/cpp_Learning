#include <iostream>
#include <string>

struct Test {
	int t1;
	int t2;
	int t3;
};

int main()
{
	Test t;
	t.t1 = 10;
	t.t2 = 20;
	t.t3 = 30;

	Test b;
	memcpy( &b, &t, sizeof(t) );

	std::cout << "sizeof T=" << sizeof(t) << std::endl;
	std::cout << "b.t1 = " << b.t1 << std::endl;
	std::cout << "b.t2 = " << b.t2 << std::endl;
	std::cout << "b.t3 = " << b.t3 << std::endl;
	return 0;
}