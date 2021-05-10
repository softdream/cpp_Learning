#include <iostream>
#include <vector>

using namespace std;

/*
	解法：双指针法
*/

class Solution {
public:
	void moveZeroes(vector<int>& nums) 
	{
		int right = 0, left = 0;
		while (right < nums.size()) {
			if (nums[right] != 0) {
				nums[left++] = nums[right];
			}
			++right;
		}

		for (int i = left; i < nums.size(); i++) {
			nums[i] = 0;
		}
	}
};

int main()
{
	vector<int> a = { 0,1,0,3,12 };

	Solution().moveZeroes(a);

	for (auto it : a) {
		std::cout << it << std::endl;
	}

	return 0;
}