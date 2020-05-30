#include "Engine.h"

Engine::Engine(const Vector<Booked*> &vec_b,
	const Vector<Holiday*> &vec_h,
	const char first_sym)
	:booked(vec_b), holiday(vec_h)
{
	file[0] = first_sym;
}

void Engine::open()
{

}
void Engine::close()
{

}
void Engine::save()
{

}
void Engine::saveas()
{

}
void Engine::help()
{

}
void Engine::book()
{
	Date date;
	Time start_time;
	Time end_time;
	std::string name;
	std::string note;
	std::cin >> date >> start_time >> end_time >> name;
	std::getline(std::cin, note);
	if (!(date.Check() && start_time.Check() && end_time.Check()))
	{
		std::cout << "Incorrect date or time!\n";
		return;
	}
	size_t length = holiday.size();
	for (size_t i = 0; i < length; i++)
	{
		if (date == holiday[i]->getDate())
		{
			std::cout << "This date is already a holiday.\n";
			return;
		}
	}
	length = booked.size();
	for (size_t i = 0; i < length; i++)
	{
		if (date == booked[i]->getDate() &&
			(start_time >= booked[i]->getStartTime() && start_time <= booked[i]->getEndTime()) &&
			(end_time >= booked[i]->getStartTime() && end_time <= booked[i]->getEndTime()))
		{
			std::cout << "This date and time are booked.\n";
			return;
		}
	}
	Insert_and_sort(booked, Booked(date, start_time, end_time, name, note));
}
void Engine::unbook()
{

}
void Engine::agenda()
{

}
void Engine::change()
{

}
void Engine::find()
{

}
void Engine::f_holiday()
{

}
void Engine::busydays()
{

}
void Engine::findslot()
{

}
void Engine::findslotwith()
{

}
void Engine::unknown()
{
	std::cin.ignore(IGNORE_LENGTH, '\n');
	std::cout << "Unknown command!\n";
}