/*
* function_traits用来获取所有函数语义类型的信息，
*      (函数类型、返回类型、参数个数和参数的具体类型)。
*
* 函数语义类型包括
*  普通函数
*  函数指针
*  function/lambda
*  成员函数
*  函数对象
*
* 实现function_traits的关键技术
*  要通过模板特化和可变参数模板来获取函数类型和返回类型。
*  先定义一个基本的function_traits的模板类：
*     template<typename T>
*     struct function_traits;
*  再通过特化，将返回类型和可变参数模板作为模板参数，就可以获取函数类型、函数返回值和参数的个数了。
*
* 如:
*  int func(int a, string b);
* ## 获取函数类型
*      function_traits<decltype(func)>::function_type; // int __cdecl(int, string)
* # 获取函数返回值
*      function_traits<decltype(func)>::return_type;   // int
* # 获取函数的参数个数
*      function_traits<decltype(func)>::arity;         // 2
* # 获取函数第一个入参类型
*      function_traits<decltype(func)>::args<0>::type; // int
* # 获取函数第二个入参类型
*      function_traits<decltype(func)>::args<1>::type; // string
*/

#ifndef __FUNCTION_TRAITS_H__
#define __FUNCTION_TRAITS_H__

#include <functional>

// 原型
template<typename T>
struct function_traits;

// 普通函数
template<typename ReturnType, typename... Args>
struct function_traits<ReturnType(Args...)>
{
	enum { arity = sizeof...(Args) };
	using return_type = ReturnType;
	using function_type = ReturnType(Args...);
	using stl_function_type = std::function<function_type>;
	using pointer = ReturnType(*)(Args...);

	template<size_t I>
	struct args
	{
		static_assert(I < arity, "index is out of range, index must less than sizeof Args");
		using type = typename std::tuple_element<I, std::tuple<Args...>>::type;
	};

	using tuple_type = std::tuple<std::remove_cv_t<std::remove_reference_t<Args>>...>;
	using bare_tuple_type = std::tuple<std::remove_const_t<std::remove_reference_t<Args>>...>;
};

// 函数指针
template<typename ReturnType, typename... Args>
struct function_traits<ReturnType(*)(Args...)> : function_traits<ReturnType(Args...)> {};

// std::function
template<typename ReturnType, typename... Args>
struct function_traits<std::function<ReturnType(Args...)>> : function_traits<ReturnType(Args...)> {};

// 成员函数
#define FUNCTION_TRAITS(...)\
template <typename ReturnType, typename ClassType, typename... Args>\
struct function_traits<ReturnType(ClassType::*)(Args...) __VA_ARGS__> : function_traits<ReturnType(Args...)>{};\

FUNCTION_TRAITS()
FUNCTION_TRAITS(const)
FUNCTION_TRAITS(volatile)
FUNCTION_TRAITS(const volatile)

// 函数对象
template<typename Callable>
struct function_traits : function_traits<decltype(&Callable::operator())> {};

template<typename Function>
typename function_traits<Function>::stl_function_type to_function(const Function& lambda)
{
	return static_cast<typename function_traits<Function>::stl_function_type>(lambda);
}

template<typename Function>
typename function_traits<Function>::stl_function_type to_function(Function&& lambda)
{
	return static_cast<typename function_traits<Function>::stl_function_type>(std::forward<Function>(lambda));
}

template<typename Function>
typename function_traits<Function>::pointer to_function_pointer(const Function& lambda)
{
	return static_cast<typename function_traits<Function>::pointer>(lambda);
}

#endif
