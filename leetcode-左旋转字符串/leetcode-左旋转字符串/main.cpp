#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	string reverseLeftWords(string s, int n) {
		std::string temp1 = s.substr( 0, n );
		std::cout << "temp1 = " << temp1 << std::endl;

		std::string temp2 = s.substr( n );
		std::cout << "temp2 = " << temp2 << std::endl;

		return temp2 + temp1;
	}
};

int main()
{
	std::string s = "abcdefg";

	std::string ret = Solution().reverseLeftWords( s, 2 );
	std:cout << "ret = " << ret << std::endl;

	return 0;
}