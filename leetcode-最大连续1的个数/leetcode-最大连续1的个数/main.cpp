#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int findMaxConsecutiveOnes(vector<int>& nums) {
		int maxCount = 0, count = 0;
		int n = nums.size();
		for (int i = 0; i < n; i++) {
			if (nums[i] == 1) {
				count++;
			}
			else {
				maxCount = max(maxCount, count);
				count = 0;
			}
		}
		maxCount = max(maxCount, count);
		return maxCount;
	}
};

int main()
{
	std::vector<int> num = { 1,1,0,1,1,1 };

	std::cout << "max " << Solution().findMaxConsecutiveOnes(num) << std::endl;

	return 0;
}