#include <iostream>
#include <vector>

#include <algorithm>

typedef struct{
        char ipAddr[ 16 ];
        int port;
        int type;
}nodeInfo;

std::vector<nodeInfo> linkTable;

void print(std::vector<nodeInfo> &linkTable)
{
	int i = 0;
	for (auto it = linkTable.begin(); it != linkTable.end(); it++, i++) {
		std::cout << "linkTable[" << i << "].ipAddr = " << it->ipAddr << std::endl;
		std::cout << "linkTable[" << i << "].port = " << it->port << std::endl;
		std::cout << "linkTable[" << i << "].type = " << it->type << std::endl;
		std::cout << "-------------------------------" << std::endl << std::endl;
	}
}

int main()
{
	nodeInfo ni1;
	char *a1 = "111111";
	strcpy_s( ni1.ipAddr, a1 );
	ni1.port = 1;
	ni1.type = 2;
	linkTable.push_back( ni1 );

	nodeInfo ni2;
	char *a2 = "222222";
	strcpy_s(ni2.ipAddr, a2);
	ni2.port = 3;
	ni2.type = 2;
	linkTable.push_back(ni2);

	nodeInfo ni3;
	char *a3 = "333333";
	strcpy_s(ni3.ipAddr, a3);
	ni3.port = 3;
	ni3.type = 2;
	linkTable.push_back(ni3);

	nodeInfo ni4;
	char *a4 = "444444";
	strcpy_s(ni4.ipAddr, a4);
	ni4.port = 3;
	ni4.type = 2;
	linkTable.push_back(ni4);

	nodeInfo ni5;
	char *a5 = "555555";
	strcpy_s(ni5.ipAddr, a5);
	ni5.port = 3;
	ni5.type = 3;
	linkTable.push_back(ni5);

	print( linkTable);

	std::cout << "***************************************************************" << std::endl;

	// É¾³ý½Úµã

	auto it = linkTable.begin();
	for (; it != linkTable.end(); ) {
		if (it->port == 3 && it->type == 2) {
			it = linkTable.erase( it );
		}
		else it++;
	}

	print( linkTable );
	return 0;
}