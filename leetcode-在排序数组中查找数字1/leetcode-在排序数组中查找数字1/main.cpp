#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int search(vector<int>& nums, int target) {
		int count = 0;
		for (auto it : nums) {
			if (it == target)
				count++;
		}
		
		return count;
	}
};

int main()
{
	vector<int> vec = { 5,7,7,8,8,10 };

	int  ret = Solution().search( vec, 8 );
	std::cout << "result = " << ret << std::endl;

	return 0;
}