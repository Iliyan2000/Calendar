#include "Engine.h"

Engine::Engine(const Vector<Booked*> &vec_b,
	const Vector<Date*> &vec_h,
	const char first_sym,
	const bool _saved)
	:booked(vec_b), holiday(vec_h), saved(_saved)
{
	file[0] = first_sym;
}

void Engine::open()
{
	if (file[0] == '\0')//check if there is open file
	{
		std::cin.get();
		std::cin.getline(file, FILENAME_LENGTH);
		open_file();
		saved = true;
		return;
	}
	char temp_file_name[FILENAME_LENGTH];
	std::cin.get();
	std::cin.getline(temp_file_name, FILENAME_LENGTH);
	if (saved)
	{
		close();
		file[0] = '\0';
		strcpy(file, temp_file_name);
		open_file();
		saved = true;
		return;
	}
	std::string answer;
	std::cout << "Would you like to save the changes before opening another calendar?[yes/no]\n>";
	std::cin >> answer;
	std::cin.ignore(IGNORE_LENGTH, '\n');
	if (answer == "yes" || answer == "y")
	{
		save();
	}
	else if (answer == "no" || answer == "n")
	{ }
	else
	{
		std::cout << "Unknown comand. Unable to open new calendar.\n";
		return;
	}
	close();
	file[0] = '\0';
	strcpy(file, temp_file_name);
	open_file();
	saved = true;
}
void Engine::close(const bool exiting)
{
	std::cin.ignore(IGNORE_LENGTH, '\n');
	if (file[0] == '\0')
	{
		std::cout << "There is no open file.\n";
		return;
	}
	if (!exiting && !saved)
	{
		std::cout << "Would you like to save the changes before closing the calendar?[yes/no]\n>";
		std::string answer;
		std::cin >> answer;
		std::cin.ignore(IGNORE_LENGTH, '\n');
		if (answer == "no" || answer == "n")
		{ }
		else
		{
			save();
		}
	}
	file[0] = '\0';
	size_t length = booked.size();
	for (size_t i = 0; i < length; i++)
	{
		booked.pop_back();
	}
	length = holiday.size();
	for (size_t i = 0; i < length; i++)
	{
		holiday.pop_back();
	}
	if (!exiting)
	std::cout << "File successfully closed.\n";
	saved = false;
}
void Engine::save()
{
	if (file[0] == '\0')
	{
		std::cin.ignore(IGNORE_LENGTH, '\n');
		std::cout << "There is no open file.\n";
		return;
	}
	saved = true;
}
void Engine::saveas()
{
	if (file[0] == '\0')
	{
		std::cin.ignore(IGNORE_LENGTH, '\n');
		std::cout << "There is no open file.\n";
		return;
	}
	saved = true;
}
void Engine::help()
{
	std::cout << "The following commands are supported:\n" <<
		"open <file>						opens <file>\n" <<
		"close							closes currently opened file\n" <<
		"save							saves the currently open file\n" <<
		"saveas <file>						saves the currently open file in <file>\n" <<
		"help							prints this information\n" <<
		"book <date> <starttime> <endtime> <name> <note>		saves the information to the calendar\n" <<
		"unbook <date> <starttime> <endtime>			delete the commit from the calendar\n" <<
		"exit							exists the program\n";
}
void Engine::book(std::istream& in, const bool from_console)
{
	if (file[0] == '\0')
	{
		std::cin.ignore(IGNORE_LENGTH, '\n');
		std::cout << "There is no open file.\n";
		return;
	}
	Date date;
	Time start_time;
	Time end_time;
	std::string name;
	std::string note;
	in >> date >> start_time >> end_time >> name;
	in.get();
	std::getline(in, note);
	if (!(date.Check() && start_time.Check() && end_time.Check()))
	{
		std::cout << "Incorrect date or time!\n";
		return;
	}
	size_t length = holiday.size();
	for (size_t i = 0; i < length; i++)
	{
		if (date == *holiday[i])
		{
			if (from_console)
			std::cout << "This date is already a holiday.\n";
			return;
		}
	}
	std::string answer = "yes";
	bool f = false;
	if (start_time > end_time)
	{
		f = true;
		std::cout << "Would you like your commit to continue to the next date?[yes/no]\n>";
		std::cin >> answer;
		std::cin.ignore(IGNORE_LENGTH, '\n');
		if (answer == "no" || answer == "n")
		{
			std::cout << "The commit not saved.\n";
			return;
		}
	}
	if (answer == "yes" || answer == "y")
	{
		Vector<Booked> B;
		B.push_back(Booked(date, start_time, end_time, name, note));
		if (f)
		{
			Booked b;
			B[0].Split(b);
			B.push_back(b);
		}
		size_t length_B = B.size();
		for (size_t j = 0; j < length_B; j++)
		{
			length = booked.size();
			for (size_t i = 0; i < length; i++)
			{
				if (B[j].getDate() == booked[i]->getDate() &&
					(B[j].getStartTime() >= booked[i]->getStartTime() && start_time <= booked[i]->getEndTime()) &&
					(B[j].getEndTime() >= booked[i]->getStartTime() && end_time <= booked[i]->getEndTime()))
				{
					if (from_console)
					std::cout << "This date and time are already commited.\n";
					if (j == 1)
					{
						for (size_t t = 0; t < length; t++)
						{
							if (B[j] == *booked[t])
							{
								delete booked[t];
								booked.erase(t);
								break;
							}
						}
					}
					return;
				}
			}
			Insert_and_sort(booked, B[j]);
		}
		if (from_console)
		std::cout << "Successfully commited.\n";
		saved = false;
	}
	else
	{
		std::cout << "unknown command!\n";
	}
}
void Engine::unbook()
{
	if (file[0] == '\0')
	{
		std::cin.ignore(IGNORE_LENGTH, '\n');
		std::cout << "There is no open file.\n";
		return;
	}
	Date date;
	Time start_time;
	Time end_time;
	std::cin >> date >> start_time >> end_time;
	if (!(date.Check() && start_time.Check() && end_time.Check()))
	{
		std::cout << "Incorrect date or time!\n";
		return;
	}
	size_t length = booked.size();
	if (start_time <= end_time)
	{
		for (size_t i = 0; i < length; i++)
		{
			if (date == booked[i]->getDate() &&
				start_time == booked[i]->getStartTime() &&
				end_time == booked[i]->getEndTime())
			{
				delete booked[i];
				booked.erase(i);
				std::cout << "Successfully deleted the commit.\n";
				saved = false;
				return;
			}
		}
		std::cout << "Not found commit on these date and time.\n";
	}
	else
	{
		Date next_date = date;
		next_date.AddDay();
		for (size_t i = 0; i < length; i++)
		{
			if (date == booked[i]->getDate() &&
				start_time == booked[i]->getStartTime() &&
				Time(23, 59, 59) == booked[i]->getEndTime() &&
				next_date == booked[i + 1]->getDate() &&
				Time() == booked[i + 1]->getStartTime() &&
				end_time == booked[i + 1]->getEndTime() &&
				booked[i]->getName() == booked[i + 1]->getName() &&
				booked[i]->getNote() == booked[i + 1]->getNote())
			{
				delete booked[i];
				booked.erase(i);
				delete booked[i];
				booked.erase(i);
				std::cout << "Successfully deleted the commit.\n";
				saved = false;
				return;
			}
		}
		std::cout << "Not found commit on these date and time.\n";
	}
}
void Engine::agenda()
{
	if (file[0] == '\0')
	{
		std::cin.ignore(IGNORE_LENGTH, '\n');
		std::cout << "There is no open file.\n";
		return;
	}
	Date date;
	std::cin >> date;
	if (!date.Check())
	{
		std::cout << "Incorrect date!\n";
		std::cin.ignore(IGNORE_LENGTH, '\n');
		return;
	}
	bool f = false;
	size_t length = booked.size();
	for (size_t i = 0; i < length; i++)
	{
		if (date == booked[i]->getDate())
		{
			std::cout << booked[i]->getStartTime() << '-' <<
				booked[i]->getEndTime() << ' ' << booked[i]->getName() << '\n';
			if (booked[i]->getNote() != "")
			{
				std::cout << booked[i]->getNote() << '\n';
			}
			f = true;
		}
	}
	if (!f)
	{
		std::cout << "There are no commitments for this date.\n";
	}
}
void Engine::change()
{
	if (file[0] == '\0')
	{
		std::cin.ignore(IGNORE_LENGTH, '\n');
		std::cout << "There is no open file.\n";
		return;
	}
	Date date;
	Time start_time;
	std::cin >> date >> start_time;
}
void Engine::find()
{
	if (file[0] == '\0')
	{
		std::cin.ignore(IGNORE_LENGTH, '\n');
		std::cout << "There is no open file.\n";
		return;
	}
}
void Engine::f_holiday(std::istream& in, const bool from_console)
{
	if (file[0] == '\0')
	{
		std::cin.ignore(IGNORE_LENGTH, '\n');
		std::cout << "There is no open file.\n";
		return;
	}
	Date date;
	in >> date;
	if (!date.Check())
	{
		std::cout << "Incorrect date!\n";
		return;
	}
	Insert_and_sort(holiday, date);
	if (from_console)
	std::cout << "Successfully saved the date as holiday.\n";
	saved = false;
	if (booked.size() == 0)
	{
		return;
	}
	size_t i = 0;
	while (date >= booked[i]->getDate())
	{
		if (date == booked[i]->getDate())
		{
			if (Time(23, 59, 59) == booked[i]->getEndTime() &&
				Time() == booked[i + 1]->getStartTime() &&
				booked[i]->getName() == booked[i + 1]->getName() &&
				booked[i]->getNote() == booked[i + 1]->getNote())
			{
				delete booked[i];
				booked.erase(i);
				delete booked[i];
				booked.erase(i);
			}
			else
			{
				delete booked[i];
				booked.erase(i);
			}
		}
		else
		{
			i++;
		}
	}
}
void Engine::busydays()
{
	if (file[0] == '\0')
	{
		std::cin.ignore(IGNORE_LENGTH, '\n');
		std::cout << "There is no open file.\n";
		return;
	}
}
void Engine::findslot()
{
	if (file[0] == '\0')
	{
		std::cin.ignore(IGNORE_LENGTH, '\n');
		std::cout << "There is no open file.\n";
		return;
	}
}
void Engine::findslotwith()
{
	if (file[0] == '\0')
	{
		std::cin.ignore(IGNORE_LENGTH, '\n');
		std::cout << "There is no open file.\n";
		return;
	}
}
void Engine::merge()
{
	if (file[0] == '\0')
	{
		std::cin.ignore(IGNORE_LENGTH, '\n');
		std::cout << "There is no open file.\n";
		return;
	}
}
void Engine::unknown()
{
	std::cin.ignore(IGNORE_LENGTH, '\n');
	std::cout << "Unknown command!\n";
}
void Engine::if_saved()
{
	if (file[0] == '\0')
	{
		return;
	}
	else if (saved)
	{
		close(true);
		return;
	}
	std::cout << "Would you like to save the changes before exiting the program?[yes/no]\n>";
	std::string answer;
	std::cin >> answer;
	//std::cin.ignore(IGNORE_LENGTH, '\n');
	if (answer == "no" || answer == "n")
	{
		close(true);
		return;
	}
	save();
	close(true);
}

void Engine::open_file()
{
	std::ifstream stream(file);
	if (!stream.is_open())
	{
		std::ofstream openfile(file);
		openfile.close();
		stream.open(file);
		if (!stream.is_open())
		{
			std::cout << "Unable to open this file.\n";
			file[0] = '\0';
			return;
		}
	}
	char type;
	stream >> type;//reads the type of the first event
	while (type == 'B' || type == 'H')
	{
		if (type == 'B')//reads cimmits from file
		{
			book(stream, false);
		}
		else//reads holidays from file
		{
			f_holiday(stream, false);
		}
		stream >> type;//reads the type of the next event
	}
	std::cout << "File successfully opened.\n";
	stream.close();
}