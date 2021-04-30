#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		for (int i = digits.size() - 1; i >= 0; i--) {
			digits[i]++;
			digits[i] = digits[i] % 10;
			if (digits[i] != 0) return digits;
		}

		vector<int> res(digits.size() + 1);
		res[0] = 1;
		return res;
	}

	void print(vector<int>& digits)
	{
		for (auto it : digits)
			std::cout << it << ", ";
		std::cout << std::endl;
	}
};

int main()
{
	vector<int> vec = { 4, 3, 2, 1 };

	Solution s;
	s.plusOne(vec);
	s.print(vec);
	return 0;
}