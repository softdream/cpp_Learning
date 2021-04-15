#include <iostream>
#include <functional>
#include <map>
#include <memory>
#include <typeinfo>
#include <vector>

template<typename T>
struct function_traits;

// R为返回类型
// ...Args 为输入参数类型，个数不限
template<typename R, typename ...Args>
struct function_traits<std::function<R(Args...)>>
{
	static const size_t nargs = sizeof...(Args);
	// 返回类型
	typedef R result_type;

	// 输入参数类型,i为从0开始的参数类型索引
	template <size_t i>
	struct arg
	{
		typedef typename std::tuple_element<i, std::tuple<Args...>>::type type;
	};
};

void testCB(int a)
{
	std::cout << "a = " << a << std::endl;
}

int main()
{
	function_traits<decltype(testCB)>::args<0>::type;
	return 0;
}