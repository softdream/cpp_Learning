#include <iostream>
#include <vector>

using namespace std;
/*
	解法：双指针法
*/

class Solution {
public:
	int removeElement(vector<int>& nums, int val)
	{
		int slow = 0, fast = 0;

		while (fast < nums.size()) {
			if (nums[fast] != val  ) {
				nums[slow] = nums[fast];
				slow++;
			}

			fast++;
		}
		return slow;
	}
};

int main()
{
	std::vector<int> vec = { 1, 2, 2, 3, 5, 2, 3 };
	std::cout << "origin vec = " << std::endl;
	for (auto it : vec) {
		std::cout << it << "\t";
	}
	std::cout << std::endl;
	std::cout << "---------------------------------" << std::endl;

	int length = Solution().removeElement(vec, 2);
	std::cout << "after removed value: " << std::endl;
	for (int i = 0; i < length; i++) {
		std::cout << vec[i] << "\t" ;
	}
	std::cout << std::endl;

	return 0;
}