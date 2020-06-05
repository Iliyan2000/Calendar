#pragma once
#include <iostream>

class Date
{
public:
	Date(size_t _year = 0, size_t _month = 0, size_t _day = 0);
	Date(const Date& other);

	inline size_t getYear() const { return year; }
	inline size_t getMonth() const { return month; }
	inline size_t getDay() const { return day; }
	void setYear(const size_t _year) { year = _year; }
	void setMonth(const size_t _month) { month = _month; }
	void setDay(const size_t _day) { day = _day; }
	bool Check();
	bool operator==(const Date& other);
	bool operator!=(const Date& other);
	bool operator>(const Date& other);
	bool operator>=(const Date& other);
	bool operator<(const Date& other);
	bool operator<=(const Date& other);
	void AddYear();
	void AddMonth();
	void AddDay();

private:
	size_t year;
	size_t month;
	size_t day;
};
std::istream& operator>>(std::istream& in, Date& obj);
std::ostream& operator<<(std::ostream& out, const Date& obj);