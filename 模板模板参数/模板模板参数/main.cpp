#include <iostream>
#include <list>

/*
	template template parameter
	即模板的模板参数
*/

template<typename T, 
		template<typename T>
		class Container  //这就是一个模板中的模板参数，传入一个模板容器
		>
class XCLs
{
private:
	Container<T> c;

public:

};

template<typename T>
using Lst = std::list<T, std::allocator<T>>;

int main()
{
	XCLs<std::string, Lst> mylst;

	return 0;
}