#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	int countSegments(string s) {
		s += ' ';
		int cnt = 0;
		for (int i = 0; i < s.size() - 1; i++) {
			if (s[i] != ' ' && s[i + 1] == ' ') {
				cnt++;
			}
		}
		return cnt;
	}
};

int main()
{
	std::string str = "";

	int ret = Solution().countSegments( str );
	std::cout << "ret = " << ret << std::endl;

	return 0;

}