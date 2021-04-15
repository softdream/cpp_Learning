#include <iostream>
#include <vector>

class Publisher {

public:

	Publisher()
	{

	}
	~Publisher()
	{

	}

	Publisher(const Publisher &obj):recvCount( obj.recvCount )
	{

	}

	Publisher& operator=(const Publisher &other)
	{
		if (&other == this) return *this;
		recvCount = other.recvCount;
	}

	void test()
	{
		std::cout << "sizeof destInfoMap: " << destInfoMap.size() << std::endl;
		for (int i = 10; i < 100; i += 10) {
			recvCount.push_back( i );
			destInfoMap.push_back(i);
		}
	}

	void printRecvCount()
	{
		for (auto it : recvCount) {
			std::cout << it << std::endl;
		}
	}

	void print();

private:
	std::vector<int> recvCount;
	static std::vector<int> destInfoMap;
};

std::vector<int> Publisher::destInfoMap;

void Publisher::print()
{
	for (auto it : destInfoMap) {
		std::cout << it << std::endl;
	}
}

int main()
{
	Publisher p;
	p.test();
	p.printRecvCount();

	std::cout << "---------------" << std::endl;
	Publisher p2( p );
	p2.printRecvCount();

	return 0;
}