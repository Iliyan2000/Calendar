#include "Time.h"

Time::Time(size_t _hour, size_t _minute, size_t _second)
	:hour(_hour), minute(_minute), second(_second)
{

}
Time::Time(const Time& other)
{
	hour = other.hour;
	minute = other.minute;
	second = other.second;
}

bool Time::Check()
{
	if (hour < 24 && minute < 60 && second < 60)
	{
		return true;
	}
	return false;
}