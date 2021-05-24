#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	string replaceSpace(string s) {
		std::string ret;
		for (auto it : s) {
			if (it == ' ') {
				ret.push_back('%');
				ret.push_back('2');
				ret.push_back('0');
			}
			else {
				ret.push_back(it);
			}
		}
		return ret;
	}
};

int main()
{
	std::string s = "We are happy.";
	std::string ret = Solution().replaceSpace(s);
	std::cout << "ret = " << ret << std::endl;

	return 0;
}