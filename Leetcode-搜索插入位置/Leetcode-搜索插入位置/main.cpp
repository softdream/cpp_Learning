#include <iostream>
#include <vector>

using namespace std;

/* 
	解法一：暴力法
*/
/*class Solution {
public:
	int searchInsert(vector<int>& nums, int target) 
	{
		if (target < nums[0]) return 0;
		if (target == nums[nums.size() - 1]) return nums.size() - 1;
		for (int i = 0; i < nums.size() - 1; i++) {
			if (target == nums[i]) return i;
			else if (target > nums[i] && target < nums[i + 1]) return i + 1;
		}
		return nums.size();
	}
};*/

/*
	解法二：二分法
*/
class Solution {
public:
	int searchInsert(vector<int>& nums, int target)
	{
		int left = 0, right = nums.size() - 1;
		while (left <= right) {
			int mid = left + (right - left) / 2;
			if (nums[mid] >= target) right = mid - 1;
			else left = mid + 1;
 		}
		return left;
	}
};

int main()
{
	std::vector<int> a1 = { 1,3,5,6 };
	std::cout << Solution().searchInsert(a1, 6) << std::endl;

	return 0;
}