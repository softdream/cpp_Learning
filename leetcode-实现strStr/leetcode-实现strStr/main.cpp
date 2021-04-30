#include <iostream>
#include <string>

using namespace std;

/*
	解法一：暴力匹配
*/
class Solution {
public:
	int strStr(string haystack, string needle) 
	{
		
		for (int i = 0; i + needle.size() <= haystack.size(); i++) {

			bool flag = true;
			for (int j = 0; j < needle.size(); j++) {
				if (needle[j] != haystack[i + j]) {
					flag = false;
					break;
				}
			}
			if (flag) return i;
		}
		return -1;
	}
};

int main()
{
	std::string s1 = "";
	std::string s2 = "";

	int len = Solution().strStr( s1, s2 );
	std::cout << "position = " << len << std::endl;

	return 0;
}