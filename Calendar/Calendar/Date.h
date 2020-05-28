#pragma once
#include <iostream>

class Date
{
public:
	Date(size_t _year = 0, size_t _month = 0, size_t _day = 0);
	Date(const Date& other);

	//...

private:
	size_t year;
	size_t month;
	size_t day;
};
std::istream& operator>>(std::istream& in, Date& obj);
std::ostream& operator<<(std::ostream& out, const Date& obj);