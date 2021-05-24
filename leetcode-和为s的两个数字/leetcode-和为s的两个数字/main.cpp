#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		std::vector<int> ret;
		for (int i = 0; i < nums.size(); i++) {
			for (int j = i; j < nums.size(); j++) {
				if (nums[i] + nums[j] == target) {
					ret.push_back(nums[i]);
					ret.push_back(nums[j]);
					break;
				}
			}
		}
		
		return ret;
	}
};

int main()
{
	std::vector<int> vec = { 2,7,11,15 };

	std::vector<int> ret = Solution().twoSum(vec, 9);

	for (auto it : ret) {
		std::cout << it << std::endl;

	}

	return 0;
}