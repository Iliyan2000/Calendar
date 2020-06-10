#include "Date.h"

Date::Date(size_t _year, size_t _month, size_t _day)
	:year(_year), month(_month), day(_day)
{

}
Date::Date(const Date& other)
{
	year = other.year;
	month = other.month;
	day = other.day;
}

bool Date::Check()
{
	if ((month == 1 || month == 3 || month == 5 ||
		month == 7 || month == 8 || month == 10 ||
		month == 12) && (day > 0 && day < 32))
	{
		return true;
	}
	else if ((month == 4 || month == 6 ||
		month == 9 || month == 11) &&
		(day > 0 && day < 31))
	{
		return true;
	}
	else if (year % 4 == 0 && month == 2 &&
		(day > 0 && day < 30))
	{
		return true;
	}
	else if (year % 4 != 0 && month == 2 &&
		(day > 0 && day < 29))
	{
		return true;
	}
	return false;
}
bool Date::operator==(const Date& other)
{
	if (year == other.year && month == other.month && day == other.day)
	{
		return true;
	}
	return false;
}
bool Date::operator!=(const Date& other)
{
	if (*this == other)
	{
		return false;
	}
	return true;
}
bool Date::operator>(const Date& other)
{
	if (year > other.year)
	{
		return true;
	}
	else if (year == other.year && month > other.month)
	{
		return true;
	}
	else if (year == other.year && month == other.month && day > other.day)
	{
		return true;
	}
	return false;
}
bool Date::operator>=(const Date& other)
{
	if (*this > other || *this == other)
	{
		return true;
	}
	return false;
}
bool Date::operator<(const Date& other)
{
	if (*this >= other)
	{
		return false;
	}
	return true;
}
bool Date::operator<=(const Date& other)
{
	if (*this < other || *this == other)
	{
		return true;
	}
	return false;
}
void Date::AddYear()
{
	year++;
}
void Date::AddMonth()
{
	month++;
	if (!Check())
	{
		month = 1;
		AddYear();
	}
}
void Date::AddDay()
{
	day++;
	if (!Check())
	{
		day = 1;
		AddMonth();
	}
}

std::istream& operator>>(std::istream& in, Date& obj)
{
	size_t year, month, day;
	in >> year; in.get();
	in >> month; in.get();
	in >> day;
	obj.setYear(year); obj.setMonth(month); obj.setDay(day);
	return in;
}
std::ostream& operator<<(std::ostream& out, const Date& obj)
{
	out << obj.getYear() << '-';
	if (obj.getMonth() < 10)
	{
		out << '0';
	}
	out << obj.getMonth() << '-';
	if (obj.getDay() < 10)
	{
		out << '0';
	}
	out << obj.getDay();
	return out;
}
void Insert_and_sort(Vector<Date*>& vec, const Date& obj)
{
	size_t i = 0;
	size_t length = vec.size();
	Date* pobj = new Date;
	*pobj = obj;
	for (size_t i = 0; i < length; i++)
	{
		if (*pobj < *vec[i])
		{
			vec.insert(i, pobj);
			return;
		}
	}
	vec.push_back(pobj);
}