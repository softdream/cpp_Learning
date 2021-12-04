#include <iostream>
#include <string>

class Solution {
public:
	/*int trailingZeroes(int n) {
		int num = n; 
		int count = 0;
		
		for (int i = n - 1; i > 0; i--) {
			num *= i;
		}
		std::cout << "num = " << num << std::endl;

		std::string  numStr = std::to_string(num);
		std::cout << "numStr = " << numStr << std::endl;
		
		for (int i = 0; i < numStr.size(); i++) {
			if (numStr[i] == '0') count++;
		}

		return count;
	}*/

	int trailingZeroes(int n) {
		int count = 0;
		while (n >= 5) {
			count += n / 5;
			n /= 5;
		}
		return count;
	}
};

int main()
{
	int ret = Solution().trailingZeroes( 7 );
	std::cout << "ret = " << ret << std::endl;

	return 0;
}