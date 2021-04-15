#include <stdio.h>
#include <string.h>
#include <iostream>


char recvBuff[124];
int main()
{
	recvBuff[0] = 'h';
	recvBuff[1] = 'e';
	recvBuff[2] = 'l';
	recvBuff[3] = 'l';
	recvBuff[4] = 'o';
	recvBuff[5] = '\r';
	recvBuff[6] = '\n';
	std::cout<<strcmp(recvBuff, "hello")<<std::endl;
	return 0;
}