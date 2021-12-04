#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		std::vector<int> ret;
		std::unordered_map<int, int> map;
		/*for (int i = 0; i < nums.size(); i++) {
			for (int j = i; j < nums.size(); j++) {
				if (nums[i] + nums[j] == target) {
					ret.push_back(nums[i]);
					ret.push_back(nums[j]);
					return ret;
				}
			}
		}*/
		for (int i = 0; i < nums.size(); i++) {
			if (map.count(target - nums[i])) {
				ret.push_back(nums[i]);
				ret.push_back(target - nums[i]);
			}
			map[nums[i]] = nums[i];
		}
		
		return ret;
	}
};

int main()
{
	std::vector<int> vec = { 10,26,30,31,47,60 };

	std::vector<int> ret = Solution().twoSum(vec, 40);

	for (auto it : ret) {
		std::cout << it << std::endl;

	}

	return 0;
}