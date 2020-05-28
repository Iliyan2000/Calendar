#pragma once
#include <iostream>
#include <string>

class Time
{
public:
	Time(size_t _hour = 0, size_t _minute = 0, size_t _second = 0);
	Time(const Time& other);

	inline size_t getHour() const { return hour; }
	inline size_t getMinute() const { return minute; }
	inline size_t getSecond() const { return second; }
	void setHour(const size_t _hour) { hour = _hour; }
	void setMinute(const size_t _minute) { minute = _minute; }
	void setSecond(const size_t _second) { second = _second; }
	bool Check();
	bool operator==(const Time& other);
	bool operator!=(const Time& other);
	bool operator>(const Time& other);
	bool operator>=(const Time& other);
	bool operator<(const Time& other);
	bool operator<=(const Time& other);

private:
	size_t hour;
	size_t minute;
	size_t second;
};
std::istream& operator>>(std::istream& in, Time& obj);
std::ostream& operator<<(std::ostream& out, const Time& obj);