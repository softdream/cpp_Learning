#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
	vector<string> findRelativeRanks(vector<int>& nums) {
		vector<int> order;
		for (int i = 0; i<nums.size(); i++)
			order.push_back(i);

		sort(order.begin(), order.end(), [&nums](const int& a, const int& b) {return nums[a]>nums[b]; });
	
		vector<string> res(nums.size());

		for (int i = 0; i<nums.size(); i++){

			if (i == 0) {
				res[order[i]] = "Gold Medal";
			}
			else if (i == 1) {
				res[order[i]] = "Silver Medal";
			}
			else if (i == 2) {
				res[order[i]] = "Bronze Medal";
			}
			else {
				res[order[i]] = to_string(i + 1);
			}

		}

		return res;
	}
};

int main()
{

	std::vector<int> socres = { 10,3,8,9,4 };

	std::vector<std::string> ret = Solution().findRelativeRanks(socres);

	for (auto it : ret) {
		std::cout << it.c_str() << std::endl;
	}

	return 0;
}