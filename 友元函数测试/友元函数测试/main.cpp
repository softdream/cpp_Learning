#include <iostream>

class Test {
public:
	Test( ):a(10){}

	template<typename T>
	friend T& getData( Test &t );

	int getA()
	{
		std::cout << "a ===== " << a << std::endl;
		return a;
	}

private:
	char recvBuff[10];
	int a;
};

template<typename T>
T& getData(Test &t)
{
	T a;
	std::cout << "typeid = " << typeid(a).name() << std::endl;
	memset(&a, 0, sizeof(a));
	memcpy(&a, t.recvBuff, sizeof(a));

	std::cout << "a = " << t.a << std::endl;

	return a;
}

int main()
{
	Test a;
	a.getA(  );
	getData<int>( a );

	int client_fd[2];
	std::cout << "sizeof client_fd = " << sizeof(client_fd) << std::endl;

	return 0;
}