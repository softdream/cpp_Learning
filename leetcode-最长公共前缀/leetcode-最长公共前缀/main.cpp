#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.empty()) {
			return "";
		}

		if (strs.size() == 1) {
			return strs[0];
		}

		string ret = strs[0];
		for (auto it : strs) {
			ret = lcp( ret, it );
		}

		return ret;
	}

private:
	//查找两个字符串的公共最长前缀
	string lcp(string &str1, string &str2)
	{
		size_t length = std::min( str1.size(), str2.size() );
		
		int index = 0;
		while (index <= length && str1[index] == str2[index]) {
			index ++;
		}

		return str1.substr( 0, index );
	}
};

int main()
{
	std::vector<std::string> vecStr = { "flower", "flow", "flight" };

	Solution s;
	std::string ret = s.longestCommonPrefix(vecStr);
	std::cout << ret << std::endl;

	std::vector<std::string> vecStr2 = { "dog","racecar","car" };
	std::string ret2 = s.longestCommonPrefix(vecStr2);
	std::cout << ret2 << std::endl;

	return 0;
}