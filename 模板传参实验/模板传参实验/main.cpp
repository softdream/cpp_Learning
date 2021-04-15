#include<iostream>

template<typename T>
void test(T t)
{
	std::cout << "t = " << t << std::endl;
}

template<typename T>
struct Type {
	typedef void(*Action)( T  );
};

int main()
{
	Type<double>::Action callback = &test<double>;

	callback( 8.999 );

	return 0;
}