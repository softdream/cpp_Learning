#ifndef __TIMESTAMP_H_
#define __TIMESTAMP_H_

#include <time.h>
#include <Windows.h>
#include <stdint.h>

int64_t getCurrentTime_ms()
{
	struct timeval tv;
	time_t clock;
	struct tm tm;
	SYSTEMTIME wtm;
	GetLocalTime( &wtm );
	tm.tm_year = wtm.wYear - 1900;
	tm.tm_mon = wtm.wMonth - 1;
	tm.tm_mday = wtm.wDay;
	tm.tm_hour = wtm.wHour;
	tm.tm_min = wtm.wMinute;
	tm.tm_sec = wtm.wSecond;
	tm.tm_isdst = -1;
	clock = mktime( &tm );
	tv.tv_sec = clock;
	tv.tv_usec = wtm.wMilliseconds * 1000;
	return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}

SYSTEMTIME getCurrentTime()
{
	SYSTEMTIME st = { 0 };
	GetLocalTime(&st);  //获取当前时间 可精确到ms
	std::cout << st.wYear << "-" << st.wMonth << "-" << st.wDay << " " << st.wHour << ":" << st.wMinute << ":" << st.wSecond <<":"<<st.wMilliseconds<< std::endl;
	return st;
}

#endif
