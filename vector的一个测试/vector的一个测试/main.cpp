#include <iostream>
#include <vector>
#include <Eigen/Dense>

int main()
{
	int size = 10;
	std::vector<Eigen::Vector2f> vec(size, Eigen::Vector2f(0.0f, 0.0f));


	/*std::vector<int> vec(size, 0);

	for (int i = 0; i < 10; i++) {
		vec[i] = i;
	}

	for (auto it : vec) {
		std::cout << it << std::endl;
	}*/

	return 0;
}