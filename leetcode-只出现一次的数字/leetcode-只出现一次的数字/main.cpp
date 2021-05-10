#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		std::unordered_map<int, int> map;

		for (auto it : nums) {
			++map[it];
		}

		for (auto it : nums) {
			if (map[it] == 1)
				return it;
		}

		return -1;
	}
};

int main()
{
	vector<int> vec = { 2, 2, 1 };
	int n = Solution().singleNumber( vec );
	std::cout << "n = " << n << std::endl;

	return 0;
}