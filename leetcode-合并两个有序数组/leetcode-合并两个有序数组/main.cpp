#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		for (int i = 0; i < n; i++) {
			nums1[m + i] = nums2[i];
		}

		std::sort( nums1.begin(), nums1.end() );
	}
};

int main()
{
	vector<int> num1 = { 1,2,3,0,0,0 };
	vector<int> num2 = { 2,5,6 };

	Solution().merge( num1, 3, num2, 3 );

	for (auto it : num1)
		std::cout << it << std::endl;

	return 0;
}