#include <iostream>
#include <deque>

/*
	设计模式--适配器
*/

//queue的所有功能都是由deque完成的，只是对deque的一层重新封装，给它新的操作
template<class T, class Sequence = deque<T>>
class queue
{
protected:
	Sequence c; // 底层容器

public:
	bool empty() const
	{
		return c.empty();
	}

	size_t size() const
	{
		return c.size();
	}

	T& front()
	{
		return c.front();
	}

	T& back()
	{
		return c.back();
	}

	void push(const T& x)
	{
		c.push_back(x);
	}

	void pop()
	{
		c.pop_front();
	}
};

int main()
{
	return 0;
}