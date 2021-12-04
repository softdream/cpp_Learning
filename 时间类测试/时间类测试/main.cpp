#include <iostream>
#include <chrono>

class Time
{
public:
	static void begin();
	static void end();

	static const double duration_s();
	static const double duration_ms();
	static const double duration_ns();

private:
	static std::chrono::steady_clock::time_point beginTimePoint;
	static std::chrono::steady_clock::time_point endTimePoint;

};

std::chrono::steady_clock::time_point Time::beginTimePoint = std::chrono::steady_clock::time_point();
std::chrono::steady_clock::time_point Time::endTimePoint = std::chrono::steady_clock::time_point();

void Time::begin()
{
	beginTimePoint = std::chrono::steady_clock::now();
}

void Time::end()
{
	endTimePoint = std::chrono::steady_clock::now();
}

const double Time::duration_s()
{
	return std::chrono::duration<double>( endTimePoint - beginTimePoint ).count();
}

const double Time::duration_ms()
{
	return std::chrono::duration<double, std::milli>(endTimePoint - beginTimePoint).count();
}

const double Time::duration_ns()
{
	return std::chrono::duration<double, std::micro>(endTimePoint - beginTimePoint).count();
}


int main()
{

	Time::begin();
	for (int i = 10000; i > 0; i--) {
		for (int j = 10000; j > 0; j--) {

		}
	}
	Time::end();

	std::cout << "time duration s : " << Time::duration_s() << std::endl;
	std::cout << "time duration ms : " << Time::duration_ms() << std::endl;
	std::cout << "time duration ns : " << Time::duration_ns() << std::endl;

	return 0;
}
