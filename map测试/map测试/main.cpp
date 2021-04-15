#include <iostream>
#include <map>

typedef struct {
	int a;
	int b;
}topicInfo;

std::map<std::string, topicInfo > topicTable;


int main()
{
	topicInfo node1;
	node1.a = 1;
	node1.b = 2;
	topicTable.insert(std::make_pair("node1",node1 ) );

	auto it = topicTable.find( "node1" );
	std::cout << "a = " << it->second.a << std::endl;
	return 0;
}