#pragma once
#include "Booked.h"

const size_t IGNORE_LENGTH = 128;

class ForDate
	:public Booked
{
public:
	ForDate(const Booked& other)
		:Booked(other)
	{ }
	void Change()
	{
		Date _date;
		std::cin >> _date;
		std::cin.ignore(IGNORE_LENGTH, '\n');
		date = _date;
	}
};
class ForStartTime
	:public Booked
{
public:
	ForStartTime(const Booked& other)
		:Booked(other)
	{ }
	void Change()
	{
		Time _start_time;
		std::cin >> _start_time;
		std::cin.ignore(IGNORE_LENGTH, '\n');
		start_time = _start_time;
	}
};