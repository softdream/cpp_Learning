#include <iostream>
#include <algorithm>
#include <vector>

struct T{
	T(){}
	bool operator()(T *p)
	{
		return (age == p->age);
	}
	int age;
};


struct nodeInfo{
        nodeInfo(){}
        ~nodeInfo(){}

        bool operator()( nodeInfo &p )
        {
                std::string s1 = ipAddr;
                std::string s2 = p.ipAddr;
                if( !s1.compare( s2 ) && port == p.port ) return true;
                else return false;
        }
		nodeInfo& operator=(nodeInfo &p)
		{
			port = p.port;
			strcpy_s( ipAddr, p.ipAddr );
			type = p.type;
			timeOfClient = p.timeOfClient;
			return *this;
		}

        char ipAddr[ 16 ];
        int port;
        int type;
        int timeOfClient;
};

struct nodeInfo2 {

	char ipAddr[16];
	int port;
	int type;
	int timeOfClient;
};


std::vector<nodeInfo> nodeTable;

char sendBuff[20];

void PrintVector(std::vector<nodeInfo> &p)
{
	for (auto it = p.begin() + 1; it != p.end(); it++) {
		std::cout << "---------------------------------------" << std::endl;
		std::cout << "ipAddr = " << it->ipAddr << std::endl;
		std::cout << "port = " << it->port << std::endl;
		std::cout << "type = " << it->type << std::endl;
		
	}
	std::cout << "---------------------------------------" << std::endl << std::endl;
}

bool findx(nodeInfo &f, nodeInfo &p)
{
	if (strcmp(f.ipAddr, p.ipAddr) == 0 && f.port == p.port)
		return true;
	else return false;
}

int main()
{
	struct nodeInfo n;
	char *s = "192.168.1.100";
	strcpy_s( n.ipAddr, s );
	n.port = 1111;
	n.type = 2;
	nodeTable.push_back( n );
	std::cout << "sizeof nodeInfo = " << sizeof(n) << std::endl;
	
	struct nodeInfo n2;
	char *s2 = "192.168.1.200";
	strcpy_s(n2.ipAddr, s2);
	n2.port = 2222;
	n2.type = 2;
	nodeTable.push_back(n2);

	struct nodeInfo n3;
	char *s3 = "192.168.1.300";
	strcpy_s(n3.ipAddr, s3);
	n3.port = 3333;
	n3.type = 1;
	nodeTable.push_back(n3);

	PrintVector( nodeTable );

	//std::vector<nodeInfo>::iterator item = nodeTable.begin();
	/*auto item = nodeTable.begin();

	for (auto it = nodeTable.begin(); it != nodeTable.end(); it++) {
		if (it->port == 3333 && !strcmp( it->ipAddr, "192.168.1.300" ) ) {
			std::cout << "found ..." << std::endl;
			item = find_if(nodeTable.begin(), nodeTable.end(), 
				[ it ](nodeInfo found){
					return found.port == it->port && !strcmp( it->ipAddr, found.ipAddr );
				});
		}
	}
	if (item != nodeTable.end() && item != nodeTable.begin() ) {
		std::cout << "item->port = " << item->port << std::endl;
		nodeTable.erase(item);
	}

	PrintVector(nodeTable);*/
	return 0;
}