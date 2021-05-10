#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	int lengthOfLastWord(string s) {
		int len = s.length() - 1;

		int res = 0;
		while (len >= 0 && s[len] == ' ') {
			len--;
		}
		while (len >= 0 && s[len] != ' ') {
			res++;
			len--;
		}
		return res;
	}
};


int main()
{
	string s = " a ";

	int length = Solution().lengthOfLastWord(s);
	std::cout << "length = " << length << std::endl;

	return 0;
}