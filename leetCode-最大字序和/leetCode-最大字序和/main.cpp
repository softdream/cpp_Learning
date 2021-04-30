#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
	解法：动态规划：
		1. 求max{f(i)}, i = 0, 1, 2, ...
		2. f(i) = max{ nums[i] + f(i - 1), nums[i] }
*/

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int pre = 0;
		int maxSum = nums[0];

		for (auto it : nums) {
			pre = std::max( pre + it, it );
			maxSum = std::max( pre, maxSum );
		}
		return maxSum;
	}
};

int main()
{
	std::vector<int> vec = { -2,1,-3,4,-1,2,1,-5,4 };

	std::cout<<Solution().maxSubArray(  vec )<<std::endl;

	return 0;
}