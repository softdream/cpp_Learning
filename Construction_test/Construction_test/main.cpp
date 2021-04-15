#include <iostream>
//#define USE_TAG

/* 一、继承的构造函数原理 */
class ParentA
{
public:
	ParentA():a(5)
	{
		std::cout << "this is parent's construction function ..." << std::endl;
	}
	ParentA( int a_ )
	{
		a = a_;
		std::cout << "this is parent's parameter construction function ..." << a << std::endl;
	}
	~ParentA()
	{
		std::cout << "this is parent's deconstruction function ..." << std::endl;
	}

	void test()
	{
		std::cout << "a = " << a << std::endl;
	}

private:
	int a;
};

// 1. 子类可以继承父类中的所有成员和方法，除了构造函数
// 2. 创建子类对象时，为了初始化从父类继承来的数据成员，系统需要调用其父类的构造函数、
// 3. 如果子类中没有构造方法，则调用父类的无参构造方法
// 4. 如果子类中定义了构造方法，无论是带参的还是不带参的，再定义子类对象时，首先执行父类无参的构造方法，然后执行自己的构造方法
// 5. 在创建子类对象时，如果子类的构造函数没有显式调用父类的构造方法，则会调用父类默认的无参构造方法
// 6. 在创建子类对象时，如果子类的构造函数没有显式调用父类的构造方法且父类自己定义了无参构造方法，则会调用父类自己的无参构造方法
// 7. 在创建子类对象时，如果子类的构造函数没有显示调用父类的构造方法且父类自己没有定义无参构造方法，只定义了
//有参构造函数，这时会出错
// 8. 如果子类调用父类的有参构造函数，需要用初始化父类成员对象的方式，如下：
class childA :public ParentA
{
public:
	childA():ParentA( 5 ) // 这种初始化方式，还常用来对类中的常量（const）成员进行初始化
	{
		std::cout << "this is child's construction ..." << std::endl;
	}
	/*child() // 父类中只有带参构造函数，这时会报错
	{
		std::cout << "this is child's construction ..." << std::endl;
	}*/
	~childA()
	{
		std::cout << "this is child's deconstruction ..." << std::endl;
	}

};

/* 二、拷贝构造函数 */
class ClassA {
public:
	// 1. new 开辟的内存一般在堆上，而普通的变量声明在栈上
	// 2. new 出来的是一段地址空间的首地址，所以一般用指针来存放这段地址
	// 3. 
	ClassA()
	{
		a = new int[8];
		std::cout << "address of a is: " << a << std::endl;
	}

	ClassA(const ClassA& A_)
	{
		a = new int[8];
		*a = *(A_.a);
		std::cout << "address of  copy of a is: " << a << std::endl;
	}

	~ClassA()
	{
		delete[] a;
	}

private:
	int *a;

};

/* 三、 */

int main()
{
	ClassA a;
	ClassA b(a);

#ifdef USE_TAG
	std::cout << "use tag ..." << std::endl;
#endif
	return 0;
}