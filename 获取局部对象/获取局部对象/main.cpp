#include <iostream>
#include <thread>
#include <windows.h>

int count = 0;
class Publisher {
public:
	//static int count;

	Publisher() : i(0), c(10), thread_(std::bind(&Publisher::createAThread, this))
	{
		//thread_.join();
		thread_.detach();
	}

	Publisher(const Publisher &obj):c( obj.c ), i(obj.i)
	{
		std::cout << "copy constructor of the Class Publisher ..." << std::endl;
	}

	~Publisher()
	{

	}

	void createAThread()
	{
		while (1) {
			i++;
			count++;
			if (i > 999) {
				i = 0;
				count = 0;
			}
			//std::cout << " i = " << i << std::endl;
			std::cout << " count ============== " << count << std::endl;
			Sleep( 1000 );
		}
	}

	int getI()
	{
		return i;
	}

private:

	std::thread thread_;
	int i;
	int c;
};

class PCS {
public:
	PCS()
	{
	
	}

	~PCS()
	{

	}

	template<typename T>
	const Publisher advertise(std::string topicName)
	{
		Publisher publisher;
		
		return publisher;
	}

};

//int Publisher::count = 0;

int main()
{
	PCS pcs;
	Publisher pub = pcs.advertise<int>("node1");


	
	while (1) {
		Sleep(100);
		//std::cout << "i = " << pub.getI()<< std::endl;
		std::cout << "count = " << count << std::endl;
	}

	return 0;
}