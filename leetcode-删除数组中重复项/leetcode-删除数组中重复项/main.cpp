#include <iostream>
#include <vector>

using namespace std;

/*
	解法：双指针法
*/

class Solution {
public:
	/*int removeDuplicates(vector<int>& nums)
	{
		if (!nums.size()) return 0;

		int slow = 1, fast = 1;
		while ( fast < nums.size() ) {
			if (nums[fast] != nums[fast - 1]) {
				nums[slow] = nums[fast];
				slow++;
			}
			fast++;
		}
		return slow;
	}*/

	int removeDuplicates(vector<int>& nums)
	{
		if (!nums.size()) return 0;

		int fast = 0;
		for (int slow = 1; slow < nums.size(); slow++) {
			if (nums[fast] != nums[slow])
				nums[++fast] = nums[slow];
		}
		return ++fast;
	}
};

int main()
{
	std::vector<int> vec = { 1, 2, 2, 2, 3, 3, 3, 3, 4 };

	int length = Solution().removeDuplicates(vec);

	for (int i = 0; i < length; i ++) {
		std::cout << vec[i] << std::endl;
	}

	return 0;
}