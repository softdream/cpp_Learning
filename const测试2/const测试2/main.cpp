#include <iostream>

void test( int& const a ) // 这样写const不起作用，等价于 int& a; 编译有warning ： qualifiers on reference are ignored
{
	std::cout << "a type = " << typeid(a).name() << std::endl;
	a++;// 这是可以的，
	std::cout << "a ++ = " << a << std::endl;
	// 结果是 5
}

void test2(const int& a) // 这里 const修饰的a是传进来的参数的一个别名，在函数内不能更改其值
{
	std::cout << "a type = " << typeid(a).name() << std::endl;
	// a ++; // error

}

void test3(int* const a)// 这里const修饰的是a, 表明指针不能变, 但是指针所指的内容可以变
{
	std::cout << "a type = " << typeid(a).name() << std::endl;
	(*a) ++;// 指针指的东西可以变
	// a++; // error: 不能修改的左值
	std::cout << "a = " << (*a)++ << std::endl;
}

void test4(const int *a) // 这里const修饰的是int，表明指针所指的内容不能变， 即*a不能变
{
	std::cout << "a type = " << typeid(a).name() << std::endl;
	// (*a) ++; // error：不能修改的左值
	a++;// 可以， 地址可以变
	std::cout << "a = " << a++ <<std::endl;
}

int main()
{
	int a = 4;
	test(a);

	test2(a);

	test3(&a);

	test4(&a);

	return 0;
}