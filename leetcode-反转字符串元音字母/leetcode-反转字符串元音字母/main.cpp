#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
	/*string reverseVowels(string s) {
		std::string str = s;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') {
				std::cout << "str[" << i << "] = " << str[i] << std::endl;

				for (int j = i + 1; j < str.size(); j++) {
					if (str[j] == 'a' || str[j] == 'e' || str[j] == 'i' || str[j] == 'o' || str[j] == 'u') {
						std::cout << "str2[" << j << "] = " << str[j] << std::endl;
						char tmp = str[i];
						std::cout << "tmp = " << tmp << std::endl;
						str[i] = str[j];
	
						str[j] = tmp;

					}
				}
			}
		}
		std::cout << "str = " << str.c_str() << std::endl;

		return str;
	}*/

	 // 采用双指针法
	string reverseVowels(string s) 
	{
		int i = 0, j = s.size() - 1;

		std::string str = "aeiouAEIOU";

		while (str.find(s[i]) == -1 && i < j) {
			++i;
		}

		while (str.find(s[j]) == -1 && i < j) {
			--j;
		}

		if (i < j) {
			std::cout << "i = " << i << "j = " << j << std::endl;
			char tmp = s[i];
			s[i] = s[j];
			s[j] = tmp;
		}
		return s;

	}
};

int main()
{
	std::string s = "hello";

	std::string ret = Solution().reverseVowels(s);
	std::cout << "ret = " << std::endl;
	std::cout<< ret.c_str() << std::endl;

	return 0;
}