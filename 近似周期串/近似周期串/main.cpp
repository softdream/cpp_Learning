#include <iostream>
#include<string>


int main()
{	
	int T = 0; // 数据的组数
	int EqualCount = 0;

	std::cout << "请输入数据的组数：" << std::endl;
	std::cin >> T;

	for (int i = 0; i < T; i++) {
		std::cout << "输入第 " << i << " 组的字符串：" << std::endl;

		std::string f;
		std::cin>>f;
		std::cout << "输入的字符串为： " << f << "长度是：" << f.length() << std::endl; 

		const char *p = f.data();
		
		/* 判断是否为一个近似周期串 */
		char temp[3]; // 中间变量每次保存三个字符
		for (int j = 0; j < f.length(); j += 3) {
			memset(temp, 0, sizeof(temp));
			memcpy( temp, &p[j], 3 );

			std::cout << "temp = " << temp << std::endl;

			for (int k = 0; k < 3; k++) { // 进行比较，每三个字符只要和后面的字符进行比较就行，
										 // 因为前面的比较过了
				if (temp[k] != p[j + 3]) {
					EqualCount++;
				}
			}
			if (EqualCount > 1) { // 近似周期串最多只能有一个字符是一样的
				std::cout << "这不是一个近似周期串！" << std::endl;
				continue;
			}
			EqualCount = 0;
		}
		std::cout << "这是一个近似周期串！" << std::endl;
	}

	return 0;
}



