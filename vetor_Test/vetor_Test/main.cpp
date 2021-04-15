#include <iostream>
#include <vector>

int main()
{
	std::vector<int> v;
	for (int i = 0; i < 5; i++) {
		v.push_back(i);
	}

	int i = 0;
	for ( auto it = v.begin(); it != v.end(); it++, i ++) {
		std::cout << "v[" << i << "] = " << *it << std::endl;
	}

	auto iter = std::find( v.begin(),v.end(), 6 );
	if (iter != v.end())
		v.erase(iter);

	std::cout << "----------------------------" << std::endl;

	int j = 0;
	for (auto it = v.begin(); it != v.end(); it++, j++) {
		std::cout << "v[" << j << "] = " << *it << std::endl;
	}

	return 0;
}