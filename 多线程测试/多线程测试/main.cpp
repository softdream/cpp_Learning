#include <iostream>
#include <thread>
#include <Windows.h>
#include <vector>

struct C {
	int a;
	int b;
};
typedef struct C C;

class A {
public:
	A():a(1000)
	{
		std::cout << "constructor function for class A " << a <<std::endl;
		for (int i = 1; i < 5; i++)
			list.push_back( i );
	}


	void test( std::vector<C> &l )
	{
		while (1) {
			std::cout << "thread1 ..." <<std::endl;
			Sleep(1000);
		}

	}

	void print()
	{
		std::cout << "a === " << a << std::endl;
	}

	void printList()
	{
		int i = 1;
		for (auto it = list.begin(); it != list.end(); it++, i++) {
			std::cout << "list[" << i << "] = " << *it << std::endl;
		}
	}

private:
	int a;
	std::vector<int> list;
};

std::vector<C > b;

class B {
public:
	A advertise()
	{
		
		A a;
		std::thread thread1( &A::test, &a, b );
		thread1.detach();
		return a;
	}
};

void t( std::string name )
{
	std::cout << "name = " << name.data() << std::endl;
}

int main()
{
	B b;

	A a = b.advertise();

	while (1) {
		std::cout << "main thread ..." << std::endl;
		a.print();
		a.printList();
		Sleep( 500 );

		t( "node1" );
	}

	return 0;
}