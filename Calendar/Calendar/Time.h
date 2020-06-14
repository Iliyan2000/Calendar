#pragma once
#include <iostream>
#include <string>

class Time
{
public:
	/**
	*коструктор по подразбиране/с параметри
	*/
	Time(size_t _hour = 0, size_t _minute = 0, size_t _second = 0);
	/**
	*копи конструктор
	*/
	Time(const Time& other);

	/**
	*селектор за час
	*/
	inline size_t getHour() const { return hour; }
	/**
	*селектор за минута/и
	*/
	inline size_t getMinute() const { return minute; }
	/**
	*селектор за секунда/и
	*/
	inline size_t getSecond() const { return second; }
	/**
	*мутатор за час
	*/
	void setHour(const size_t _hour) { hour = _hour; }
	/**
	*мутатор за минута/и
	*/
	void setMinute(const size_t _minute) { minute = _minute; }
	/**
	*мутатор за секунда/и
	*/
	void setSecond(const size_t _second) { second = _second; }
	/**
	*проверява дали времето е валидно
	*/
	bool Check();
	/**
	*сарвнява две времена дали са равни
	*/
	bool operator==(const Time& other);
	/**
	*сарвнява две времена дали не са равни
	*/
	bool operator!=(const Time& other);
	/**
	*сарвнява две времена дали първото е по-напред във времето от второто
	*/
	bool operator>(const Time& other);
	/**
	*сарвнява две времена дали първото е по-напред във времето или е равно на второто
	*/
	bool operator>=(const Time& other);
	/**
	*сарвнява две времена дали първото е по-назад във времето от второто
	*/
	bool operator<(const Time& other);
	/**
	*сарвнява две времена дали първото е по-назад във времето или е равно на второто
	*/
	bool operator<=(const Time& other);

private:
	size_t hour;
	size_t minute;
	size_t second;
};
/**
*оператор за въвеждане
*/
std::istream& operator>>(std::istream& in, Time& obj);
/**
*оператор за извеждане
*/
std::ostream& operator<<(std::ostream& out, const Time& obj);