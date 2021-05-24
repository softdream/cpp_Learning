#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Solution {
public:
	vector<int> printNumbers(int n) {
		std::vector<int> vec;

		for (int i = 1; i < std::pow(10, n); i++) {
			vec.push_back(i);
		}
		
		return vec;
	}
};

int main()
{
	std::vector<int> ret = Solution().printNumbers(3);

	for (auto it : ret) {
		std::cout << it << std::endl;
	}
	
	return 0;
}