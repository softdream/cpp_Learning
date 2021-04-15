#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>

template<typename... A> class Test {};  // 变长模板的声明

template<> class Test<> {};  // 边界条件

template<typename Head, typename... Tail>  // 递归的偏特化定义
class Test<Head, Tail...> : public Test<Tail...>
{
	typedef Test<Tail...> inherited;

protected:
	Head m_head;
	std::queue<Head> q;

public:
	Test()
	{
		printf("type: %s\n", typeid(Head).name());
	}
	Test(Head v, Tail... vtails) : m_head(v), inherited(vtails...)
	{
		std::cout << "constructor ..." << std::endl;
	}

	Head head()
	{
		return m_head;
	}

	inherited& tail()
	{
		return *this;
	}
};


int main()
{
	Test<int, char, float> car;

	Test<int, std::string, float> t1(10, "dudaofeng", 20.1);

	std::cout << t1.head() << std::endl;
	std::cout << t1.tail().head() << std::endl;
	std::cout << t1.tail().tail().head() << std::endl;

	system("pause");
	return 0;
}