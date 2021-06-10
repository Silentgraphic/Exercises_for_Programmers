#include "getDate.h"
#include <chrono>
int getDate()
{
	const std::chrono::time_point<std::chrono::system_clock> nowTimePoint = std::chrono::system_clock::now();
	struct tm newtime;
	time_t now = std::chrono::system_clock::to_time_t(nowTimePoint);
	localtime_s(&newtime, &now);
	return newtime.tm_year + 1900;
};