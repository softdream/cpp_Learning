#include <iostream>
#include <Windows.h>

#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" )


int main()
{
	int count = 0;
	while (1) {
		count ++;
		std::cout << "----------------------------------- " << count << std::endl;
		if (count > 65535) count = 0;
		Sleep(1000);
	}
}
