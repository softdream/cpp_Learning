#include <iostream>
#include <deque>

/*
	模板模板参数
*/
template<typename T, 
			template<class ELEM, typename = std::allocator<ELEM>>
			class CONT = std::deque>
class Stack
{
private:
	CONT<T> elems;

public:
	void push( T const& );
	void pop();
	T top() const;

	bool empty() const
	{
		return elems.empty();
	}
};

template<typename T, template<typename, typename> class CONT>
void Stack<T, CONT>::push( T const& elem )
{
	elems.push_back( elem );
}

int main()
{
	Stack<int> s;
	s.push( 5 );
	return 0;
}