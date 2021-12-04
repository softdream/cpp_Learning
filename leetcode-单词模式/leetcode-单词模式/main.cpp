#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
	bool wordPattern(string pattern, string s) {
		std::unordered_map<string, char> str2char;
		std::unordered_map<char, string> char2str;

		int m = s.length();
		int i = 0;
		
		for (auto it : pattern) {
			if (i >= m) {
				return false;
			}

			int j = i;
			while (j < m && s[j] != ' ') {
				j++;
			}

			const string &tmp = s.substr( i, j - i );

			if (str2char.count(tmp) && str2char[tmp] != it) {
				return false;
			}

			if (char2str.count(it) && char2str[it] != tmp) {
				return false;
			}

			str2char[tmp] = it;
			char2str[it] = tmp;

			i = j + 1;

		}

		return i >= m;
	}

};

int main()
{
	

	return 0;
}