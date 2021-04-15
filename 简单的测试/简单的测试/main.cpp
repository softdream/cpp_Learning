#include <iostream>

typedef struct Node {
	char head1;
	char head2;
	char head3;
	char ipAddr[16];
	int port;
	int type;
}Node;

char sendBuff[64];

int main()
{
	Node  n;
	n.head1 = 'a';
	n.head2 = 'b';
	n.head3 = 'c';

	memset(sendBuff, 0, sizeof sendBuff);
	memcpy( sendBuff, &n, sizeof n );

	std::cout << "sendBuff: " << sendBuff << std::endl;

	return 0;
}