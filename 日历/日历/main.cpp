#include <conio.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
int monthDay[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
int isLeap(int year)
{
	if (year % 4) return 0;//普通年能被4整除且不能被100整除的为闰年
	if (year % 400) return 1;//世纪年能被400整除的是闰年
	if (year % 100) return 0;
	return 1;
}

int getWeek(int year, int month, int day)
{
	int c, y, week;
	if (month == 1 || month == 2) { //判断month是否为1或2　
		year--;
		month += 12;
	}
	c = year / 100;
	y = year - c * 100;
	week = (c / 4) - 2 * c + (y + y / 4) + (13 * (month + 1) / 5) + day - 1;
	while (week < 0) { week += 7; }
	week %= 7;
	return week;
}

void display(int year, int month, int x)
{
	int monthDays, weekFirst, i;
	monthDays = monthDay[month] + (month == 2 ? isLeap(year) : 0);
	weekFirst = getWeek(year, month, 1);
	system("cls");
	time_t t;
	struct tm * lt;
	time(&t);//获取Unix时间戳。
	lt = localtime(&t);//转为时间结构。
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);  //句柄放这里
	SetConsoleTextAttribute(handle, 0x0f);  //默认黑底白字
	printf("%d/%d/%d \n\n", lt->tm_year + 1900, lt->tm_mon + 1, lt->tm_mday);
	printf("1、按wasd键可以上下左右访问当天日期。\n\n2、按↑↓←→可以访问年月。 \n\n3、按c可以查询年月（年和月之间用空格隔开），可以多次查询年月。\n\n");
	printf("             -------%4d年----%2d月-------\n", year, month);
	printf("星期日\t星期一\t星期二\t星期三\t星期四\t星期五\t星期六\n");
	for (i = 0; i<weekFirst; i++) printf("\t");
	for (i = 1; i <= monthDays; i++)
	{
		if ((i == lt->tm_mday + x) && (month == lt->tm_mon + 1) && (year == lt->tm_year + 1900)) {
			SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_BLUE);
		}
		else if (weekFirst == 0 || weekFirst == 6) {   //周6周日设成红色     0,1,2,3,4,5,6  对应星期日到六
			SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED);
		}
		else {
			SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
		}
		printf("%d\t", i);
		weekFirst++;
		if (weekFirst >= 7) { printf("\n"); weekFirst = 0; }
	}
}

int main()
{
	int year, month, chr, i = 0;
	time_t timer;
	struct tm *tblock;
	timer = time(NULL);
	tblock = localtime(&timer);
	year = tblock->tm_year + 1900;
	month = tblock->tm_mon + 1;
	while (1)
	{
		display(year, month, 0);
	A:chr = getch();
		if (chr == 0x4b) {
			month--;
			if (month<1) { month = 12; year--; }
		}
		if (chr == 0x4d) {
			month++;
			if (month>12) { month = 1; year++; }
		}
		if (chr == 0x50) {
			year--;
		}
		if (chr == 0x48) {
			year++;
		}
		if (chr == 'c') {
			HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			printf("\n\n请输入年和月：");
			scanf("%d%d", &year, &month);
		}
		if (chr == 'w') {
			i = i - 7; display(year, month, i); goto A;
		}
		if (chr == 's') {
			i = i + 7; display(year, month, i); goto A;
		}
		if (chr == 'a') {
			i--; display(year, month, i); goto A;
		}
		if (chr == 'd') {
			i++; display(year, month, i); goto A;
		}
	}
	return 0;
}