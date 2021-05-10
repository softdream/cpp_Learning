#include <iostream>
#include <vector>
#include <unordered_map>
#include <math.h>

using namespace std;

class Solution {
public:
	int majorityElement(vector<int>& nums) {
		std::unordered_map<int, int> map;
		int n = floor( nums.size() / 2 );
		//std::cout << "n = " << n << std::endl;

		for (int i = 0; i < nums.size(); i++) {
			++map[nums[i]];
			if (map[nums[i]] > n) {
				return nums[i];
			}
		}

		return 0;
	}
};

int main()
{
	vector<int>  vec = { 2,2,1,1,1,2,2 };

	int n = Solution().majorityElement( vec );

	std::cout <<  n << std::endl;

	return 0;
}