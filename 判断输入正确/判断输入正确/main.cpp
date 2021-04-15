#include <iostream>

int main()
{
	int count = 0;
	int number;
	std::cin >> number;
	std::cout << "number = " << number << std::endl;
	char name[100];
	std::string n;
	for (int i = 0; i < number; i++) {
		std::cin.getline( name, 100 );
		n = name;
		if (n.length() <= 10) count++;
	}

	std::cout << "有效问卷个数：" << count << std::endl;
	return 0;
}