#include <chrono>
#include <iostream>
#include <thread>
#include <vector>
#include <functional>
#include <algorithm>
#include <map>

int main()
{
	//std::chrono::system_clock::time_point now = std::chrono::system_clock::now();

	std::chrono::steady_clock::time_point currentTime;
	currentTime = std::chrono::steady_clock::now();
	
	for (int i = 0; i < 100000; i++) {

	}

	std::this_thread::sleep_for( std::chrono::milliseconds(100) );

	std::chrono::steady_clock::time_point now = std::chrono::steady_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>( now - currentTime );
	std::cout << "duration: " << duration.count() << std::endl;
	std::cout << "type of duration.count(): " << typeid(duration.count()).name() << std::endl;
	/*std::vector<int> vec;
	vec.resize(10);
	std::cout << "sizeof vec = " << vec.size() << std::endl;
	
	for (int i = 0; i < 10; i++) {
		vec[i] = i;
	}

	int i = 0;
	for (auto it = vec.begin(); it != vec.end(); it++, i ++) {
		std::cout << "vec[" << i << "] = " << vec[i] << std::endl;
		//*it = i;
	}

	std::cout << "---------------------" << std::endl;
	//vec.erase( vec.begin() );

	//vec.erase( std::find( vec.begin(), vec.end(), 4 ) );
	vec.erase( vec.begin() + 4 );
	std::cout << "sizeof vec = " << vec.size() << std::endl;
	
	vec.resize(11);
	std::cout << "sizeof vec = " << vec.size() << std::endl;
	i = 0;
	for (auto it = vec.begin(); it != vec.end(); it++, i++) {
		std::cout << "vec[" << i << "] = " << vec[i] << std::endl;
		//*it = i;
	}*/
	

	std::vector<int> vec;
	vec.resize(1);
	std::cout << "sizeof vec = " << vec.size() << std::endl;

	vec[0] = 100;
	int i = 0;
	for (auto it = vec.begin(); it != vec.end(); it++, i++) {
		std::cout << "vec[" << i << "] = " << vec[i] << std::endl;
		//*it = i;
	}

	std::cout << "-----------------------" << std::endl;
	vec.resize(2);

	i = 0;
	for (auto it = vec.begin(); it != vec.end(); it++, i++) {
		std::cout << "vec[" << i << "] = " << vec[i] << std::endl;
		//*it = i;
	}

	/*std::map<int, std::string> map{ {1,"aaa"}, {2, "bbb"}, {3, "ccc"}, {4, "ddd"} };
	for (auto it = map.begin(); it != map.end(); it++) {
		std::cout << it->first<<", "<<it->second.c_str()<<std::endl;
	}
	
	std::cout << "------------------------------" << std::endl;
	int count = 0; 
	for (auto it = map.begin(); it != map.end(); it ++, count ++) {
		if (count == 2) {
			map.erase( it );
			//std::cout << it->first << ", " << it->second.c_str() << std::endl;
		}
	}*/



	return 0;
}