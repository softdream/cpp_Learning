#include <iostream>
#include <functional>
#include "ThreadPool.h"
#include <array>
#include <mutex>

std::mutex mtx;

template<typename T>
class Subsciber {
public:
	Subsciber() 
	{
		std::cout << "init of a = " << a << std::endl;
	}
	void setA( int a_ )
	{
		Subsciber::a = a_;
	}
	void createASubscriber()
	{
		while (1) {
			Subsciber::a++;
			//std::cout << "type of a = " << typeid(a).name() << std::endl;
			std::cout << "thread ..." << Subsciber::a << std::endl;
			//std::cout << "thread id: " << std::this_thread::get_id() << std::endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
		}
	}

	void printA()
	{
		std::cout << "a = " << this->a << std::endl;
	}

private:
	T message;
	static int a;
};

int Subsciber<int>::a = 0;

class PCS {
public:
	PCS()
	{

	}

	template<typename T>
	void subscribe()
	{
		Subsciber<T> sub;
		sub.setA(100);
		Subsciber<T> sub2;
		sub2.setA(1000);

		std::cout << "type of T = " << typeid(T).name() << std::endl;
		std::thread t1(std::bind( &Subsciber<T>::createASubscriber, &sub));
		std::thread t2(std::bind(&Subsciber<T>::createASubscriber, &sub2));

		threadArray[0] = std::move(t1);
		threadArray[1] = std::move(t2);
		spin();
	}

	void spin()
	{
		for (int i = 0; i < 2; i++) {
			threadArray[i].join();
		}
	}

	std::array<std::thread, 10> threadArray;
};

int main()
{
	PCS pcs;
	pcs.subscribe<int>();
	//pcs.spin();

	while (1) {
		std::cout << "main ..." << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}
	return 0;
}