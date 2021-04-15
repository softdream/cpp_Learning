#include <iostream>
#include <functional>
#include <map>

// 模板函数指针的定义 Type<T>::Action(T)
// 可以把这个函数指针放到类或者结构体里.
template <class T>
struct Type
{
	typedef void(*Action)(T);
};
// 也可以把这个函数指针放到一个模板方法里.
template <class T> void Func(void(*Action)(T), T val) {
	Action(val);
}


template<typename T>
struct Event{
	Type<T> callback;
 	T arg;
};

void callback( int a )
{
	std::cout << "a = " <<a<< std::endl;
}

void trigger()
{

}

template<typename T>
void setCb(Type<T>::Action cb )
{

}

int main()
{
	//setCb<int>(callback);


	return 0;
}
