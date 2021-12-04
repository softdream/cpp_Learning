#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int thirdMax(vector<int>& nums) {
		std::sort(nums.begin(), nums.end(), [](int a, int b) {return a < b; });

		nums.erase( std::unique( nums.begin(), nums.end() ), nums.end() );

		for (auto it : nums) {
			std::cout << it << std::endl;
		}

		if (nums.size() < 3)
			return nums[ nums.size() - 1 ];

		return nums[ nums.size() - 3 ];
	}
};

int main()
{
	std::vector<int> vec = { 8, 1, 3, 2, 4, 6, 5, 9, 7, 7 };

	std::cout<<"ret: " << Solution().thirdMax( vec )<<std::endl;

	return 0;
}