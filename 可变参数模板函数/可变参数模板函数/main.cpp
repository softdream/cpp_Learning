#include <iostream>
using namespace std;

//递归终止函数   特化的模板函数
void print() {
	cout << "empty" << endl;
}
//展开函数
template <class T, class... Args>
void print(T head, Args... rest) {
//	cout << "parameter " << head << endl;
	std::cout << "length = " << head.length() << std::endl;
	print(rest...);
}

template<typename T>
void test( T a )
{
	std::cout << "length of a = " << a.length() << std::endl;
}

int main()
{
	print<std::string, std::string>( "string", "dudaofeng" );
	//test<std::string>("string");
	return 0;
}
