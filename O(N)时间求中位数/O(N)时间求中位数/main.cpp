#include <iostream>
#include <algorithm> 

int partition(int a[], int l, int r) {
	int x = a[l];
	while (l < r) {
		while (l < r && a[r] >= x) {
			r--;
		}
		if (l < r) {
			a[l] = a[r];
			l++;
		}
		while (l < r && a[l] < x) {
			l++;
		}
		if (l < r) {
			a[r] = a[l];
			r--;
		}
	}
	a[l] = x;
	return l;
}

int getMidNumber(int a[], int l, int r, int pos) {
	while (true) {
		int index = partition(a, l, r); // 获得基准数的位置
		if (index == pos) {
			return a[index];
		}
		else if (index > pos) { // 只需要在[l, index-1]区间内找pos位置即可
			r = index - 1;
		}
		else { // 只需要在[index, r]区间内找pos位置即可
			l = index + 1;
		}
	}
	return -1; // 一般程序不会到这里
}

 //				0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11
int test[12] = { 3, 6, 2, 1, 9, 8, 0, 4, 5, 7, 10, 11 };

int main()
{
	int ret = getMidNumber( test, 0, 11, 6 );
	std::cout << "ret = " << ret << std::endl;

	return 0;
}