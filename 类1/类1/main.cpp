#include <iostream>

#include <vector>
#include <algorithm>

// c with class
// c with stl

// standard template library
// 1. 容器
// 2. 适配器 Adapter
// 3. 仿函数
// 4. 迭代器--算法和容器的沟通桥梁
// 5. 算法
// 1. vector 2. map 3. list 4. deque 5. stack

// 关键点
// 1. 构造函数和析构函数的概念--注意构造函数初始化列表的写法，以及构造函数的重载
// 2. 拷贝构造函数和拷贝赋值函数的概念--重载
// 3. 深拷贝和浅拷贝--主要针对动态分配的资源
// 额外：
// 1. public, protected, private三者的区别；
class Base
{
public:
	Base(): a(10), b(10) // 构造函数， 用来做初始化, 构造函数初始化列表
	{
		std::cout << "constructor ..." << std::endl;	

		init();
	}

	Base( int a_, int b_ ) : a(a_), b(b_) // 重载构造函数
	{
		std::cout << "constructor2 ..." << std::endl;
		init();
	}

	// 有个默认的拷贝构造函数,深拷贝的时候要重写它
	Base(const Base &rhs) : a(rhs.a), b(rhs.b)
	{
		std::cout << "default copy constructor ..." << std::endl;

		init();
		memcpy( source, rhs.source, 10 * sizeof( int ) ); // memcpy形参：目的地址，源地址，要拷贝的长度（大小）
	}

	// 拷贝赋值函数
	const Base& operator=(const Base &rhs)
	{
		std::cout << "copy assignment  ..." << std::endl;

		if (this == &rhs) return *this; // 防止自赋值；

		init();
		a = rhs.a;
		b = rhs.b;
		memcpy(source, rhs.source, 10 * sizeof(int)); // memcpy形参：目的地址，源地址，要拷贝的长度（大小）
	
		return *this;
	}

	~Base() // 析构函数, 用来释放资源, 不能重载
	{
		std::cout << "deConstructor ..." << std::endl;

		delete[] source;// 释放一段内存
	}

	void printAB()
	{
		std::cout << "a = " << a << ", b = " << b << std::endl;
	}

	void printSource()
	{
		for (int i = 0; i < 10; i++) {
			std::cout << "source[" << i << "] = " << source[i] << std::endl;
		}
	}

private:
	void init()
	{
		source = new int[10]; // 申请一段内存
		if (source == nullptr) {//NULL
			exit(-1);
		}

		for (int i = 0; i < 10; i++) {
			source[i] = i;
		}

	}

private:
	int a;
	int b;

	int *source;
};

int main()
{
	/*Base base;

	base.printAB();

	Base base2(100, 200);
	base2.printAB();

	Base base3 = Base( 100, 400 ); 
	base3.printAB();


	Base base4( 1000, 2000 );
	Base base4_cpy = base4;
	base4_cpy.printAB();*/

	Base base5( 100, 200 );
	base5.printSource();

	std::cout << "------------------------" << std::endl;
	Base base5_cpy = base5;// 这里拷贝用的是拷贝构造函数
	base5_cpy.printAB();
	base5_cpy.printSource(); 

	Base base5_cpy2( base5 );// 这里拷贝用的是拷贝构造函数
	base5_cpy2.printAB();
	base5_cpy2.printSource();

	Base base5_cpy3; // 先执行自身的构造函数

	base5_cpy3 = base5; // 这里就会调用拷贝赋值
	base5_cpy3.printAB();
	base5_cpy3.printSource();

	return 0;
}