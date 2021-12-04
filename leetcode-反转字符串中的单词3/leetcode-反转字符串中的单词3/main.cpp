#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	string reverseWords(string s) {
		int pose = s.find( " " );
		
		std::vector<std::string> strVec;

		std::string subStr = s;

		while (pose != s.npos) {
			std::string tmp = subStr.substr( 0, pose );
			std::cout << "tmp = " << tmp.c_str() << std::endl;

			strVec.push_back( tmp );

			subStr = subStr.substr( pose + 1 );
			std::cout << "substr = " << subStr.c_str() << std::endl;
			pose = subStr.find( " " );
		}
		strVec.push_back( subStr );


		std::string ret = "";
		for (auto it = strVec.begin(); it != strVec.end(); it++) {
			std::cout << "strVec: " << it->c_str()<< std::endl;
			std::reverse( it->begin(), it->end() );
			std::cout << "reverse: " << it->c_str() << std::endl;

			if (it != strVec.end() - 1) {
				ret += *it + " ";
			}
			else {
				ret += *it;
			}
		}

		return ret;
	}
};

int main()
{
	std::string str = "Let's take LeetCode contest";

	std::string s = Solution().reverseWords( str );

	std::cout << "s = " << s.c_str() << std::endl;

	return 0;
}