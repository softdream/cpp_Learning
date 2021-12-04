#include <iostream>
#include <bitset>
#include <algorithm>
#include <vector>

const int question1( const int x )
{
	std::bitset<32> bits = x;

	std::string str = bits.to_string();// 二进制序列转字符串；
	//std::cout << "str = " << str << std::endl;

	std::string str_sub;

	int pose = str.find("1");
	str_sub = str.substr( pose ); // 截取二进制字符串，舍弃高位的 0 ；
	//std::cout << "str_sub = " << str_sub << std::endl;

	int maxCount0 = 0, count0 = 0;// 最大连续 0 的个数，当前连续 0 的个数；
	int maxCount1 = 0, count1 = 0;// 最大连续 1 的个数，当前连续 1 的个数；

	for (int i = 0; i < str_sub.size(); i++) {
		if (str_sub[i] == '1') { // 如果当前元素是1，则当前连续1的个数加上1
			count1++;
		}
		else { // 否则，使用之前的连续 1 的个数更新最大的连续 1 的个数，并将当前的连续 1 的个数清零；
			maxCount1 = std::max( maxCount1, count1 );
			count1 = 0;
		}

		if (str_sub[i] == '0') { // 方法同上；
			count0++;
		}
		else {
			maxCount0 = std::max(maxCount0, count0);
			count0 = 0;
		}
	}

	maxCount0 = std::max(maxCount0, count0); // 更新最大连续 0 的个数；
	//std::cout << "max count 0 = " << maxCount0 << std::endl;

	maxCount1 = std::max(maxCount1, count1); // 更新最大连续 1 的个数；
	//std::cout << "max count 1 = " << maxCount1 << std::endl;

	return std::max( maxCount0, maxCount1 ); // 返回两个中最大的；
}

const std::vector<int> question2(std::vector<int>& nums)
{
	std::vector<int> nums_cpy = nums; // 拷贝一份

	std::vector<int> ret; // 结果数组

	std::sort( nums_cpy.begin(), nums_cpy.end() );// 对备份的数组进行一次升序排序

	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] == nums_cpy[i]) { // 位置对的上的元素就是满足条件的元素
			ret.push_back(nums[i]);
		}
	}

	return ret;
}


class Solution {
public:
	std::vector<int> sortByBits(std::vector<int>& arr) 
	{
		std::sort(arr.begin(), arr.end(),
			[&](int x, int y) { 
			if (bitsSize(x) < bitsSize(y)) {
				return true;
			}
			if (bitsSize(x) > bitsSize(y)) {
				return false;
			}
			return x < y;
			});

		return arr;
	}

private:
	const int bitsSize(const int num)
	{
		std::bitset<32> bits = num;
		return bits.count();
	}

};

int main()
{
	/*int ret = question1(17);
	std::cout << "ret = " << ret << std::endl;

	std::vector<int> nums = { 1, 3, 2, 4, 5 };
	std::vector<int> ans = question2( nums );

	for (auto it : ans) {
		std::cout << it << " ";
	}
	std::cout << std::endl;*/


	std::vector<int> arr = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
	std::vector<int> ret2 = Solution().sortByBits( arr );

	for (auto it : ret2) {
		std::cout << it << " ";
	}
	std::cout << std::endl; 
	return 0;
}