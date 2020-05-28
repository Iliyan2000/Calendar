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

//...

std::istream& operator>>(std::istream& in, Date& obj)
{
	//...
	return in;
}
std::ostream& operator<<(std::ostream& out, const Date& obj)
{
	//...
	return out;
}