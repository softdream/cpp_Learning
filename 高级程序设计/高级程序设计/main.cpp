#include <iostream>
#include <string>
#include <deque>

int main()
{
	int frequency = 10;

	float temp = static_cast<float>(1.0/frequency);
	std::cout << "temp = " << temp << std::endl;

	int period = static_cast<int>( temp * 1000000);
	std::cout << "period = " << period << std::endl;

	return 0;
}

