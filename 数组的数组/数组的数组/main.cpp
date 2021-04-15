#include <iostream>
#include <string>
char topicName[2][10];

int main()
{

	char *name = "Hello";

	std::cout << "sizeof array: " << sizeof(topicName) << std::endl;
	memset( topicName, 0, sizeof( topicName ) ) ;

	for (int i = 0; i < 2; i++) {
		memcpy( topicName[i], name, 5 );
	}

	for (int i = 0; i < 2; i++) {
		std::cout << topicName[i] << std::endl;
	}

	return 0;
}