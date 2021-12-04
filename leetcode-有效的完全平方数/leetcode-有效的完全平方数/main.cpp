#include <iostream>

class Solution {
public:
	bool isPerfectSquare(int num) {
		for (int i = 0; i < num / 2; i++) {
			if (i * i == num) {
				return true;
			}
		}
		return false;
	}
};

int main()
{
	std::cout << Solution().isPerfectSquare(16) << std::endl;;

	return 0;
}