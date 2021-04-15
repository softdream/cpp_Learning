#include <iostream>
#include <string>
#include <map>
#include <queue>
#include "head.h"

int count = 0;

template<typename... A> class Test {};  // 变长模板的声明

template<> class Test<> {};  // 边界条件

template<typename Head, typename... Tail>  // 递归的偏特化定义
class Test<Head, Tail...> : private Test<Tail...>
{
	typedef Test<Tail...> inherited;

protected:
	std::map<int, std::queue<Head>> queueMap;
	std::queue<Head> queue;

public:
	Test():nameCount(0)
	{
		count++;
	//	std::cout << "count = " << count << std::endl;		
		queueMap.insert( std::make_pair( count, queue) );
		//std::cout << "typename : " << typeid(queueMap).name() << std::endl;
	}

	void setData()
	{
		for (int i = 0; i < count; i++) {
			auto it = queueMap.find(count);
			for (int j = 1; j <= 10; j++) {
				it->second.push( j );
			}
		}
	}

	void getData()
	{
		for (int i = 0; i < count; i++) {
			auto it = queueMap.find(count);
			for (int j = 1; j <= 10; j++) {
				std::cout << "value = " << it->second.front() << std::endl;
				it->second.pop();
			}
			std::cout << "------------------------" << std::endl;
		}
	}

	inline void test()
	{

	}

	template<typename First, typename... Other>
	inline void test(First first, Other... other)
	{
		memset(topicName_[nameCount], 0, 30);
		std::cout << "name count = " << nameCount << std::endl;
		std::cout << "length: " <<first.length()<< std::endl;
		first.copy(topicName_[nameCount], first.length(), 0);
		nameCount++;
		test(other...);
	}

	void printName()
	{
		for (int i = 0; i < nameCount; i++) {
			std::cout << "topicName = " << topicName_[i] << std::endl;
		}
	}

	void test2()
	{
		auto it = queueMap.find(3);
		std::cout << "type of === " << typeid(it->second.front()).name() << std::endl;
		using myType = decltype( it->second.front() );
		std::cout << "type of my type = " << typeid(myType).name() << std::endl;
		
		//myType c = 19;
	//	std::cout << "c = " << c << std::endl;
	}
private:
	int nameCount;
	char topicName_[10][30];
};



int main()
{
	Test<char, int, int> t1;

	//t1.setData();
	//t1.getData();

	t1.test2();
	//t1.test<std::string, std::string>( "dudaofeng", "string" );
	//t1.printName();
	return 0;
}