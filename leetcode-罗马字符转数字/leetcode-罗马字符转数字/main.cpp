#include <iostream>
#include <string>
#include <map>

using namespace std;

/*class Solution {
public:
	int romanToInt(string s)
	{
		int sum = 0;
		int preNum = convertValue( s[0] );
		for (size_t i = 1; i < s.size(); i ++) {
			int num = convertValue( s[i] );

			if (preNum < num) sum -= preNum;
			else sum += preNum;

			preNum = num;
		}
		sum += preNum;

		return sum;
	}

private:
	int convertValue( char c )
	{
		if (c == 'I') return 1;
		else if (c == 'V') return 5;
		else if (c == 'X') return 10;
		else if (c == 'L') return 50;
		else if (c == 'C') return 100;
		else if (c == 'D') return 500;
		else if (c == 'M') return 1000;
		return 0;
	}
};*/

//------------------- ÐÞ¸Ä ------------------//
class Solution {
public:
	int romanToInt(string s)
	{
		int sum = 0;
		int preNum = table[s[0]];
		for (size_t i = 1; i < s.size(); i++) {
			int num = table[s[i]];

			if (preNum < num) sum -= preNum;
			else sum += preNum;

			preNum = num;
		}
		sum += preNum;

		return sum;
	}
private: 
	std::map<char, int> table = { {'I', 1}, {'V', 5},{ 'X', 10 },{ 'L', 50 },{ 'C', 100 },{ 'D', 500 },{ 'M', 1000 } };
};

int main()
{
	Solution s;

	std::cout << s.romanToInt( "III" ) << std::endl;
	std::cout << s.romanToInt("IV") << std::endl;
	std::cout << s.romanToInt("IX") << std::endl;
	std::cout << s.romanToInt("LVIII") << std::endl;
	std::cout << s.romanToInt("MCMXCIV") << std::endl;

	return 0;
}