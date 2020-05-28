#pragma once
#include "Time.h"
#include "Date.h"
#include "Vector.h"

class Booked
{
public:
	Booked() = default;
	Booked(const Booked& other);

	inline Date getDate() const { return date; }
	inline Time getStartTime() const { return start_time; }
	inline Time getEndTime() const { return end_time; }
	inline std::string getName() const { return name; }
	inline std::string getNote() const { return note; }
	void setDate(const Date& _date) { date = _date; }
	void setStartTime(const Time& _start_time) { start_time = _start_time; }
	void setEndTime(const Time& _end_time) { end_time = _end_time; }
	void setName(const std::string _name) { name = _name; }
	void setNote(const std::string _note) { note = _note; }

private:
	Date date;
	Time start_time;
	Time end_time;
	std::string name;
	std::string note;
};
void Insert_and_sort(Vector<Booked> vec, const Booked& obj);