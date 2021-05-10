#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	string replaceSpace(string s) {
		size_t pose = 0;
		string temp = s;

		while (pose != temp.npos) {
			pose = temp.find(" ");

		}
		return 0;
	}
};

int main()
{
	std::string s = "We are happy.";
	Solution().replaceSpace(s);

	return 0;
}