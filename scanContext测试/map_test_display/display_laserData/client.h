#ifndef __CLIENT_H_
#define __CLIENT_H_

#include <iostream>
#include <string>
#include <winsock.h>

#pragma comment(lib, "ws2_32.lib")

class UDPClient 
{
public:
	UDPClient()
	{
		if (!WSAStartup(MAKEWORD(2, 2), &WSAdata)){
			std::cout << "初始化成功" << std::endl;
		}
		else{
			std::cout << "初始化失败！" << std::endl;
			exit(1);
		}
	}

	~UDPClient()
	{
		closesocket(sockFd);
		WSACleanup();
	}

	void initUDPClient()
	{
		sockFd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

		if (sockFd == INVALID_SOCKET){
			std::cout << "socket fail" << std::endl;
			exit(1);
		}

		std::cout << "sock: " << sockFd << std::endl;
	}

	void setDestAddr( const std::string ip, const int port )
	{
		dest.sin_family = AF_INET;
		dest.sin_port = htons(port);
		//dest.sin_addr.S_un.S_addr = inet_addr("192.168.22.69");
		dest.sin_addr.S_un.S_addr = inet_addr(ip.c_str());

		isDestAddrSetted = true;
	}

	void sendFrame( const unsigned char *image, const int length )
	{
		if (isDestAddrSetted) {

			memset(sendBuff, 0, sizeof(sendBuff));
			memcpy(sendBuff, image, length);

			int ret = sendto(sockFd, (char *)sendBuff, length, 0, (sockaddr *)&dest, sizeof dest);
			if (ret > 0) {
				std::cerr << "Send A Frame of Image : " << ret << std::endl;
			}
			else {
				std::cerr << "Send Image Failed : " << ret << std::endl;
			}
		}
	}

private:
	WSADATA WSAdata;

	SOCKET sockFd;

	SOCKADDR_IN dest;

	unsigned char sendBuff[1024];

	bool isDestAddrSetted = false;
};



#endif