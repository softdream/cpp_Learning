#include <iostream>
#include <functional>

template<typename T>
using CallBack = std::function<void(T)>;

template<typename T>
class Subscriber {

	
};

void test(int a)
{
	std::cout << "a = " << a << std::endl;
}

class PCS {
public:
	template<typename T>
	Subscriber<T> subscribe(CallBack<T> cb)
	{
		Subscriber<T> sub;
		int a = 10;
		cb( a );

		return sub;
	}
};

int main()
{
	PCS p;
	Subscriber<int> sub = p.subscribe<int>( test );
	return 0;
}