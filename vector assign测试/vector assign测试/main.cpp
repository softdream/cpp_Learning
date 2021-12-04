#include <iostream>
#include <vector>

void printVector(int i, std::vector<int> &vec)
{
	std::cout << "vec" << i << std::endl;

	for (auto it : vec) {
		std::cout << it << " ";
	}
	std::cout << std::endl << std::endl;
}

int main()
{
	std::vector<int> vec1;
	std::vector<int> vec2;

	for (int i = 0; i < 20; ++ i){
		vec1.push_back(i);
	}
	printVector( 1, vec1 );
	
	for (int i = 0; i < 9; i++) {
		vec2.push_back( i );
	}
	printVector(2, vec2);

	vec1.erase( vec1.begin() + 11, vec1.end() );
	printVector(1, vec1);

	vec1.insert( vec1.end(), vec2.begin(), vec2.end() );

	printVector(1, vec1);

	return 0;
}