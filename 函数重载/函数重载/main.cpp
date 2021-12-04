#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

// 函数重载
void test()
{
	std::cout << "test1" << std::endl;
}

void test( int a ) // 形参列表不一样，名字一样，就叫函数重载
{
	std::cout << "test1 : " << a << std::endl;
}

void test(int a, int b) // 形参列表不一样，名字一样，就叫函数重载
{
	std::cout << "test1 : " << a <<", "<<b<< std::endl;
}

//int test(int a, int b)
//{

//}

void test(float a, float b)
{

}

// 操作符重载 +, - , *, /, +=, -=, *=, !=, [], *
// 向量加法
std::vector<int> operator+(std::vector<int> &a, std::vector<int> &b)
{
	std::vector<int> ret;
	//ret.resize( 5 );

	ret[0] = a[0] + b[1];
	ret[1] = a[1] + b[1];
	
	return ret;
}


int main()
{
	std::vector<int> a = { 1, 2 };
	std::vector<int> b = a; // copy assignment

	for (std::vector<int>::const_iterator it = a.begin(); it != a.end(); it++) {
		std::cout << *it << std::endl;

	}

	for (int it : a){
		//std::cout << "type of it: " << typeid(it).name() << std::endl;
		std::cout << it << std::endl;
	}

	for (int i = 0; i < a.size(); i++) {
		std::cout << a[i] << std::endl;
	}

	//std::for_each(a.begin(), a.end(), []() {});

	return 0;
}