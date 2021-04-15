#ifndef __STACK_H_
#define __STACK_H_

#include <iostream>

#define MAXSIZE 10

template<class T>
class Stack {
public:
	Stack();//默认构造函数
	Stack(int stack_size_);//自定义构造函数
	Stack(const Stack &obj);//拷贝构造寒素
	~Stack();// 析构函数

	Stack& operator=(const Stack& other)// 拷贝赋值函数
	{
		if (this == &other) return *this;// 检测自赋值
		delete[] stack;// 删除原有的内存资源
		stack = new T[stack_size];// 申请新的内存资源
		memcpy(stack, other.stack, stack_size * sizeof(T));// 复制过去
		return *this;// 返回左侧对象
	}

	void push(T data);
	bool isFull();
	bool isEmpty();
	T pop();
private:
	T *stack;
	int stack_size;
	int top;// 栈顶指针

	int getMaxsize()
	{
		return stack_size;
	}
};

template< class T >
Stack<T>::Stack() : top(0), stack_size(MAXSIZE)
{
	stack = new T[MAXSIZE];
}

template< class T >
Stack<T>::Stack(int stack_size_) : top(0)
{
	stack_size = stack_size_;
	stack = new T[stack_size];
}

/* 拷贝构造函数 */
template< class T >
Stack<T>::Stack(const Stack &obj)
{
	stack = new T[stack_size];
	//std::cout << "sizeof(stack) = " << sizeof(T) << std::endl;
	memcpy(stack, obj.stack, stack_size * sizeof(T));
}

/* 拷贝赋值函数 */
/*template< class T >
Stack<T>::Stack& Stack<T>::operator=(const Stack& other)
{
if (this == &other) return *this;// 检测自赋值
delete[] stack;// 删除原有的内存资源
stack = new T[ stack_size ];// 申请新的内存资源
memcpy(stack, other.stack, stack_size * sizeof(T));// 复制过去
return *this;// 返回左侧对象
}*/

template< class T >
bool Stack<T>::isFull()
{
	if (top == (getMaxsize() + 1)) {
		std::cout << "栈满了 ..." << std::endl;
		return true;
	}
	return false;
}

template< class T >
bool Stack<T>::isEmpty()
{
	if (top == -1) {
		std::cout << "栈空了 ..." << std::endl;
		return true;
	}
	return false;
}

template< class T >
void Stack<T>::push(T data)
{
	// 判断栈是否为满
	if (isFull() == true) {
		std::cout << "栈满了，不能添加数据 ..." << std::endl;
		exit(-1);
	}
	stack[++top] = data;// 不满才执行这句
}

template< class T >
T Stack<T>::pop()
{
	// 判断栈是否为空
	if (isEmpty() == true) {
		std::cout << "栈是空的，不能出栈 ..." << std::endl;
		exit(-1);
	}
	T temp = stack[top--];
	return temp;
}


template< class T >
Stack<T>::~Stack()
{
	delete[] stack;
}

#endif
