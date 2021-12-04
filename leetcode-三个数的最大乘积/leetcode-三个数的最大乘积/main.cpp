#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maximumProduct(vector<int>& nums) {
		std::sort(nums.begin(), nums.end());

		int n = nums.size();
		
		int ret = std::max(nums[0] * nums[1] * nums[n - 1], nums[n - 3] * nums[n - 2] * nums[n - 1]);
	
		return ret;

	}
};

int main()
{
	std::vector<int> nums = { -1,-2,-3 };

	std::cout << "ret = " << Solution().maximumProduct( nums ) << std::endl;

	return 0;
}

