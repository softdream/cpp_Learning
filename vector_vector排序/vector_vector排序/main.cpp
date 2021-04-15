#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::vector<std::vector<std::string>> serverInfo;

struct {
	bool operator()(std::vector<std::string>& v1, std::vector<std::string>& v2) {
		if (stoi( v1[1] ) > stoi( v2[1] )) {
			return true;
		}
		else return false;
	}
}Compare;

/*bool Compare(std::vector<std::string>& v1, std::vector<std::string>& v2)
{
	if (stoi(v1[1]) > stoi(v2[1])) {
		return true;
	}
	else return false;
}*/

int main()
{
	serverInfo = { { "server1", "1000", "ddd" },{ "server1", "2000", "ddd" },{ "server1", "3000", "ddd" } };
	std::sort(serverInfo.begin(), serverInfo.end(), Compare );

	/* 打印出来看结果 */
	for (auto it : serverInfo) {
		std::cout << std::endl;
		for (int i = 0; i < it.size(); i++) {
			std::cout << it.at(i) << " ";
		}
	}

	return 0;
}
