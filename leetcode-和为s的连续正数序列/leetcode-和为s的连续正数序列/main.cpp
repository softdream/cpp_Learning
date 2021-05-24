#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int>> findContinuousSequence(int target) {
		std::vector<std::vector<int>> ret;
		std::vector<int> vec1;

		int sum = 0, limit = (target - 1) / 2;
		for (int i = 1; i <= limit; i++) {
			for (int j = i; ; j++) {
				sum += j;
				if (sum > target) {
					sum = 0;
					break;
				}
				else if (sum == target) {
					vec1.clear();
					for (int k = i; k <= j; k++) {
						vec1.push_back( k );
					}
					ret.push_back( vec1 );
					sum = 0;
					break;
				}
			}
		}

		return ret;
	}
};

int main()
{
	std::vector<std::vector<int>> vec = Solution().findContinuousSequence( 9 );

	for (auto it : vec) {
		std::cout << "==========================" << std::endl;
		for (auto item : it) {
			std::cout << "\t" << item << std::endl;
			std::cout << "------------------" << std::endl;
		}
	}

	return 0;
}