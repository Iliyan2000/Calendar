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
bool Time::operator==(const Time& other)
{
	if (hour == other.hour && minute == other.minute && second == other.second)
	{
		return true;
	}
	return false;
}
bool Time::operator!=(const Time& other)
{
	if (*this == other)
	{
		return false;
	}
	return true;
}
bool Time::operator>(const Time& other)
{
	if (hour > other.hour)
	{
		return true;
	}
	else if (hour == other.hour && minute > other.minute)
	{
		return true;
	}
	else if (hour == other.hour && minute == other.minute && second > other.second)
	{
		return true;
	}
	return false;
}
bool Time::operator>=(const Time& other)
{
	if (*this > other || *this == other)
	{
		return true;
	}
	return false;
}
bool Time::operator<(const Time& other)
{
	if (*this >= other)
	{
		return false;
	}
	return true;
}
bool Time::operator<=(const Time& other)
{
	if (*this < other || *this == other)
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

	//counting ':' will show if in the input there seconds or minutes
	
	while (str[length] != '\0')
	{
		if (str[length] == ':')
		{
			cnt++;
		}
		length++;
	}
	size_t i = length - 1;
	
	//depends on the amount of ':', give default value
	
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
		out << '0';
	}
	out << obj.getHour() << ':';
	if (obj.getMinute() < 10)
	{
		out << '0';
	}
	out << obj.getMinute() << ':';
	if (obj.getSecond() < 10)
	{
		out << '0';
	}
	out << obj.getSecond();
	return out;
}