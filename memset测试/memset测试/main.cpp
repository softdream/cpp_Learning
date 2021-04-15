#include <iostream>
#include <string.h>

#define min( a, b, c ) ( (a)<(b)?( a<c?a:c ):( b<c?b:c ) )  
#define max( a, b, c ) ( (a)>(b)?( a>c?a:c ):( b>c?b:c ) )


int a = 30;

void a2b(int a, int *b)
{
	*b = a - 10;
}

void b2a( int *b, int a )
{
	a = *b + 10;
}

void test()
{
	int b;
	a2b( a, &b );
	b2a( &b, a );
}

int main()
{
	//std::cout << "sizeof(a) = " << sizeof(a) << std::endl;
	test();
	std::cout << "a = " << a << std::endl;
	return 0;
}
