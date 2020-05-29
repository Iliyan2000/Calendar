#include "Booked.h"

Booked::Booked(const Date& _date,
	const Time& _start_time,
	const Time& _end_time,
	const std::string _name,
	const std::string _note,
	const bool _fromFile)
	:date(_date), start_time(_start_time), end_time(_end_time),
	name(_name), note(_note), fromFile(_fromFile)
{

}
Booked::Booked(const Booked& other)
{
	date = other.date;
	start_time = other.start_time;
	end_time = other.end_time;
	name = other.name;
	note = other.note;
	fromFile = other.fromFile;
}

void Insert_and_sort(Vector<Booked*>& vec, const Booked& obj)
{
	size_t i = 0;
	size_t length = vec.size();
	Booked* pobj = new Booked;
	*pobj = obj;
	for (i = 0; i < length; i++)
	{
		if (obj.getDate() < vec[i]->getDate())
		{
			vec.insert(i, pobj);
			return;
		}
		else if (obj.getDate() == vec[i]->getDate() &&
			obj.getStartTime() < vec[i]->getStartTime())
		{
			vec.insert(i, pobj);
			return;
		}
	}
	vec.push_back(pobj);
}