#include <iostream>

class Solution {
public:
	int mySqrt(int x) {
		for (int i = 0; i <= x; i++) {
			if (i * i <= x && (i + 1) * (i + 1) > x) {
				return i;
			}
		}
		return -1;
	}
};

int main()
{
	int n = Solution().mySqrt(0);
	std::cout << "n = " << n << std::endl;

	return 0;
}