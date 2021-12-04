#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<vector<int>> C(rowIndex + 1);

		for (int i = 0; i <= rowIndex; ++i) {
			C[i].resize(i + 1);
			C[i][0] = C[i][i] = 1;

			for (int j = 1; j < i; ++j) {
				C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
			}
		}
		return C[rowIndex];
	}
};


int main()
{
	std::vector<int> ret = Solution().getRow(4);
	
	for (auto it : ret) {
		std::cout << "\t" << it << std::endl;
	}

	return 0;
}