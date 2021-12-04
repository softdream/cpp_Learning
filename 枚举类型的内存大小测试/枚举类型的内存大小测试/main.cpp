#include <iostream>

typedef enum {
	forward = 1,
	backward,
	turnleft,
	turnright,
	stop
}Command;

template<typename T>
void fun( T a )
{
	std::cout << "a = " << a << std::endl;
}

int main()
{

	std::cout << "c = " << backward << std::endl;
	std::cout << "size of Command class : " << sizeof(Command) << std::endl;

	fun<Command>(backward);

	return 0;
}