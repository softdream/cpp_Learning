#include <iostream>
#include <thread> 
#include <windows.h>
#include <array>
#include <mutex>
#include <vector>

std::mutex mtx;

void funtion(int i)
{
	//std::lock_guard<std::mutex> mtx_locker(mtx);
	for (;;) {
		std::cout << "i = " << i << std::endl;
		Sleep(500);
	}

}

std::array<std::thread, 5> threadArray;
std::vector<std::thread> threadVec;

int main()
{
	for (int i = 0; i < 5; i++) {
		//threadArray[i] = std::thread( funtion, i );
		threadVec.push_back(std::thread(funtion, i));
	}
	
	/*for (int i = 0; i < 5; i++) {
		threadArray[i].join();
	}*/

	for (auto it = threadVec.begin(); it != threadVec.end(); it++) {
		it->join();
	}

	return 0;
}