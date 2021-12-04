#include <iostream>

template<int Size>
struct Type
{
public:
	Type()
	{
		std::cout << "sizeof range[] = " << sizeof(range) << std::endl;
		memset( range, 0, sizeof( range ) );
	}
	
	~Type()
	{

	}

	int size() const
	{
		std::cout << "²»´øconst" << std::endl;
		return Size;
	}

	const int size() const
	{
		std::cout << "´øconst" << std::endl;
		return Size;
	}

private:

	float range[Size];
};

int main()
{
	Type<10> t;

	int size = t.size();
	std::cout << "size = " << size << std::endl;

	
	std::cout << "size = " << t.size() << std::endl;

	return 0;
}