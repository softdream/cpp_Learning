#include <iostream>
#include <algorithm>    // std::max

template<typename T>
int maximum(T n)
{
	return n;
}

template<typename T, typename... Args>
int maximum( T n, Args... args )
{
	return std::max( n, maximum( args... ) );
}

int main()
{
	std::cout << maximum(1, 2, 4, 6, 7, 9) << std::endl;
	return 0;
}