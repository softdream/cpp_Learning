#include <iostream>

void test( int x )
{
	std::cout << "a = " << x << std::endl;
}

// 指针传参数不安全
void test1(int *x)
{
	std::cout << "*x = " << *x << std::endl;
}

void test2(int &x) 
{
	std::cout << "x = " << x << std::endl;
}

int ar[10];
const int v = 10;

void test3(int *a, int length)  // 这个就是 decay（退化）
{

}

void test6(int *x)
{
	std::cout << "type of x: " << typeid(x).name() << std::endl;
}

void test4(int x[10])
{
	std::cout << "type of x: " << typeid(x).name() << std::endl;
}

void test5(int(&x)[10])
{
	std::cout << "type of x: " << typeid(x).name() << std::endl;
}



int main()
{
	int a = 10;

	int &b = a; // 这里的 b 可以理解成 a 的别名

	test( a );

	test1(&a);

	test2( a );

	test4(ar);

	test5(ar);

	return 0;
}