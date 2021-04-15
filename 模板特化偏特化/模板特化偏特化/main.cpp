#include <iostream>

/* 
	模板特化和偏特化
*/

//----------------- 泛化 -----------------//
template<class Key>
struct hash{

};

//-------------- 针对char类型的特化 -----------------//
template<>
struct hash<char>
{
	size_t operator()(char x) const
	{
		return x;
	}
};

//-------------- 针对int类型的特化 -----------------//
template<>
struct hash<int>
{
	size_t operator()(char x) const
	{
		return x;
	}
};

//------------------ 偏特化之个数上的偏 -------------------//
template<typename T1, typename T2, typename T3> //泛化
class Test
{

};

template<typename T2, typename T3>
class Test<int, T2, T3>//偏特化
{

};

template<typename T3>
class Test<int, char, T3> //偏特化
{

};

template<>
class Test<int, int, int>//特化
{

};

//------------------ 偏特化之范围上的偏 -------------------//
template<typename T1, typename T2, typename T3>
class Test<T1*, T2*, T3*> // 针对指针类型的偏特化
{

};


int main()
{
	return 0;
}
