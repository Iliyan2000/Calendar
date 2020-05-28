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

//bool Date::Check();//year -20
//bool Date::operator==(const Date& other);
//bool Date::operator!=(const Date& other);
//bool Date::operator>(const Date& other);
//bool Date::operator>=(const Date& other);
//bool Date::operator<(const Date& other);
//bool Date::operator<=(const Date& other);

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