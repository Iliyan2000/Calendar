#pragma once
class Time
{
public:
	Time(size_t _hour = 0, size_t _minute = 0, size_t second = 0);
	Time(const Time&);

	bool Check();

private:
	size_t hour;
	size_t minute;
	size_t second;
};

