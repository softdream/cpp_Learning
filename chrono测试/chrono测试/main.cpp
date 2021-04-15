#include <iostream>
#include <thread>

int main()
{
	int count = 0;
	while (1) {
		std::cout << "count = " << count++ << std::endl;
		std::this_thread::sleep_for( std::chrono::milliseconds(100) );
	}
	return 0;
}
