#include "Booked.h"

Booked::Booked(const Booked& other)
{
	date = other.date;
	start_time = other.start_time;
	end_time = other.end_time;
	name = other.name;
	note = other.note;
}

void Insert_and_sort(Vector<Booked> vec, const Booked& obj)
{
	size_t i = 0;
	size_t length = vec.size();
	for (i = 0; i < length; i++)
	{
		if (true)
		{

		}
	}
}