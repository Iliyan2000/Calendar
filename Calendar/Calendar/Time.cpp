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

std::istream& operator>>(std::istream& in, Time& obj)
{
	std::string str = "";
	in >> str;
	size_t length = 0;
	size_t cnt = 0;
	while (str[length] != '\0')
	{
		if (str[length] == ':')
		{
			cnt++;
		}
		length++;
	}
	size_t i = length - 1;
	switch (cnt)
	{
	case 2:
	{
		size_t temp = 1;
		size_t sec = 0;
		while (str[i] != ':')
		{
			sec += (str[i] - '0') * temp;
			temp *= 10;
			i--;
		}
		obj.setSecond(sec);
		i--;
	}
	case 1:
	{
		size_t temp = 1;
		size_t min = 0;
		while (str[i] != ':')
		{
			min += (str[i] - '0') * temp;
			temp *= 10;
			i--;
		}
		obj.setMinute(min);
		i--;
	}
	case 0:
		size_t temp = 1;
		size_t hou = 0;
		while (i < length)
		{
			hou += (str[i] - '0') * temp;
			temp *= 10;
			i--;
		}
		obj.setHour(hou);
	}
	return in;
}
std::ostream& operator<<(std::ostream& out, const Time& obj)
{
	if (obj.getHour() < 10)
	{
		out << '0' << obj.getHour();
	}
	else
	{
		out << obj.getHour();
	}
	out << ':';
	if (obj.getMinute() < 10)
	{
		out << '0' << obj.getMinute();
	}
	else
	{
		out << obj.getMinute();
	}
	out << ':';
	if (obj.getSecond() < 10)
	{
		out << '0' << obj.getSecond();
	}
	else
	{
		out << obj.getSecond();
	}
	return out;
}