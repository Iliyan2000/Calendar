#pragma once
#include <iostream>
#include "Vector.h"

class Date
{
public:
	/**
	*коструктор по подразбиране/с параметри
	*/
	Date(size_t _year = 0, size_t _month = 0, size_t _day = 0);
	/**
	*копи конструктор
	*/
	Date(const Date& other);

	/**
	*селектор за година
	*/
	inline size_t getYear() const { return year; }
	/**
	*селектор за месец
	*/
	inline size_t getMonth() const { return month; }
	/**
	*селектор за ден
	*/
	inline size_t getDay() const { return day; }
	/**
	*мутатор за година
	*/
	void setYear(const size_t _year) { year = _year; }
	/**
	*мутатор за месец
	*/
	void setMonth(const size_t _month) { month = _month; }
	/**
	*мутатор за ден
	*/
	void setDay(const size_t _day) { day = _day; }
	/**
	*проверява дали датата е валидна
	*/
	bool Check();
	/**
	*сарвнява две дати дали са равни
	*/
	bool operator==(const Date& other);
	/**
	*сарвнява две дати дали не са равни
	*/
	bool operator!=(const Date& other);
	/**
	*сарвнява две дати дали първата е по-напред във времето от втората
	*/
	bool operator>(const Date& other);
	/**
	*сарвнява две дати дали първата е по-напред във времето или е равна на втората
	*/
	bool operator>=(const Date& other);
	/**
	*сарвнява две дати дали първата е по-назад във времето от втората
	*/
	bool operator<(const Date& other);
	/**
	*сарвнява две дати дали първата е по-назад във времето или е равна на втората
	*/
	bool operator<=(const Date& other);
	/**
	*променя датата с един ден напред
	*/
	void AddYear();
	/**
	*променя датата с един месец напред
	*/
	void AddMonth();
	/**
	*променя датата с едина година напред
	*/
	void AddDay();

private:
	size_t year;
	size_t month;
	size_t day;
};
/**
*оператор за въвеждане
*/
std::istream& operator>>(std::istream& in, Date& obj);
/**
*оператор за извеждане
*/
std::ostream& operator<<(std::ostream& out, const Date& obj);
/**
*метод, който вкарва хронологично дадена дата в деден масив от други такива
*/
void Insert_and_sort(Vector<Date*>& vec, const Date& obj);