//部分背包的贪婪算法
#include<stdio.h>

int main()
{
	int n, i, j;//假设有n件物品
	double c, value; //假设一个背包能够承载的总重量是c,最大价值是value
	double w[20], v[20];//假设第i件物品的重量是w[i],价值是v[i]
	double p[20], x[20], temp, k;//假设第i件物品的单位价值是p[i],被选中的比例是x[i]


	for (i = 0; i<20; i++) {
		w[i] = 0; v[i] = 0; p[i] = 0; x[i] = 0;
	}//数组初始化

	printf("请输入物品的数量和背包的承载量（数量和承载量用逗号分开）：\n");
	scanf_s("%d,%lf", &n, &c);
	if (n <= 0 || c <= 0) {
		printf("请输入正数。");
		return 0;
	}


	printf("请依次输入每个物品的重量和价值（重量和价值用逗号分开）：\n");
	for (i = 1; i <= n; i++) {
		scanf_s("%lf,%lf", &w[i], &v[i]);
		if (w[i] <= 0 || v[i] <= 0) {
			printf("请输入正数。");
			return 0;
		}
		p[i] = v[i] / w[i];//得到物品的单位价值
	}


	for (i = 1; i<n; i++)//从大到小冒泡排序
		for (j = i + 1; j <= n; j++)
			if (p[i]<p[j]) {
				temp = p[i];
				p[i] = p[j];
				p[j] = temp;

				temp = w[i];
				w[i] = w[j];
				w[j] = temp;

				temp = v[i];
				v[i] = v[j];
				v[j] = temp;
			}


	i = 1; k = c; value = 0;
	while (i <= n&&k>0)//优先选择单位价值大的物品，直到背包装满
	{
		if (k >= w[i])//能装下一整个物品
		{
			x[i] = 1;
			value = value + v[i];
			k = k - w[i];
			i++;
		}

		else {
			x[i] = k / w[i];//只能装下一部分物品
			value = value + x[i] * v[i];
			break;
		}
	}

	printf("\n最大价值是:%.2lf \n", value);//输出最大价值

	printf("被选中的物品有：\n");
	for (i = 1; i <= n; i++)
		if (x[i]>0)
			printf("重量为%.2lf,价值为%.2lf的物品,比例为%.4lf%;\n", w[i], v[i], x[i]); //输出被选中的物品
}