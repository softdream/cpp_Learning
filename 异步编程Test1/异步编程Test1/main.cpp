#include <iostream>
#include <future>
#include <thread>
#include <chrono>

void test1()
{
	while (1){
		std::cout << "test1 ..." << std::endl;
		std::this_thread::sleep_for( std::chrono::seconds( 1 ) );
	}
}

int main()
{
	
	
	return 0;
}