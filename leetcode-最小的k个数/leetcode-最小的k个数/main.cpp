#include <iostream>
#include <vector>

#include <algorithm>

using namespace std;

class Solution {
public:
	vector<int> getLeastNumbers(vector<int>& arr, int k) {
		std::sort( arr.begin(), arr.end());
		std::vector<int> ret;
		ret.resize(k);
		
		for (int i = 0; i < k; i++) {
			ret[i] = arr[i];
		}
		return ret;
	}
};

int main()
{
	std::vector<int> source = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };

	std::vector<int> ret = Solution().getLeastNumbers( source, 5 );

	for (auto it : ret) {
		std::cout << it << std::endl;
	}

	return 0;
}