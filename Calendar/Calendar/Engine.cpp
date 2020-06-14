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
	std::cout << "Would you like to save last changes before opening another calendar?[yes/no]\n>";
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
	if (!exiting && !saved)
	{
		std::cout << "Would you like to save last changes before closing the calendar?[yes/no]\n>";
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
	std::cout << "Successfully closed " << ReturnFile_name(file) << '\n';
	saved = false;
}
void Engine::save()
{
	if (saved)
	{
		std::cout << "It is already saved.\n";
		return;
	}
	std::ofstream stream(file);
	if (!stream.is_open())
	{
		std::cout << "Unable to save " << ReturnFile_name(file) << '\n';
		return;
	}
	size_t length = booked.size();
	for (size_t i = 0; i < length; i++)
	{
		stream << "B " << booked[i]->getDate() << ' ' <<
			booked[i]->getStartTime() << ' ' <<
			booked[i]->getEndTime() << ' ' <<
			booked[i]->getName() << '\n';
		if (booked[i]->getNote() == "")
		{
			stream << '-';
		}
		stream << booked[i]->getNote() << '\n';
	}
	length = holiday.size();
	for (size_t i = 0; i < length; i++)
	{
		stream << "H " << *holiday[i] << '\n';
	}
	stream << '$';
	stream.close();
	std::cout << "Successfully saved " << ReturnFile_name(file) << '\n';
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
bool Engine::book(const Booked& B, const bool from_console)
{

	size_t length = holiday.size();
	for (size_t i = 0; i < length; i++)
	{
		if (B.getDate() == *holiday[i])
		{
			if (from_console)
			std::cout << "This date is already a holiday.\n";
			return false;
		}
	}
	std::string answer = "yes";
	bool f = false;
	if (B.getStartTime() > B.getEndTime())
	{
		f = true;
		std::cout << "Would you like your commit to continue to the next date?[yes/no]\n>";
		std::cin >> answer;
		std::cin.ignore(IGNORE_LENGTH, '\n');
		if (answer == "no" || answer == "n")
		{
			std::cout << "The commit not saved.\n";
			return false;
		}
	}
	if (answer == "yes" || answer == "y")
	{
		Vector<Booked> vec;
		vec.push_back(B);
		if (f)
		{
			Booked b;
			vec[0].Split(b);
			vec.push_back(b);
		}
		size_t length_vec = vec.size();
		for (size_t j = 0; j < length_vec; j++)
		{
			length = booked.size();
			for (size_t i = 0; i < length; i++)
			{
				if (vec[j].getDate() == booked[i]->getDate() &&
					(vec[j].getStartTime() >= booked[i]->getStartTime() && B.getStartTime() <= booked[i]->getEndTime()) &&
					(vec[j].getEndTime() >= booked[i]->getStartTime() && B.getEndTime() <= booked[i]->getEndTime()))
				{
					if (from_console)
					std::cout << "This date and time are already commited.\n";
					if (j == 1)
					{
						for (size_t t = 0; t < length; t++)
						{
							if (vec[j] == *booked[t])
							{
								delete booked[t];
								booked.erase(t);
								break;
							}
						}
					}
					return false;
				}
			}
			Insert_and_sort(booked, vec[j]);
		}
		if (from_console)
		std::cout << "Successfully commited.\n";
		saved = false;
		return true;
	}
	else
	{
		std::cout << "unknown command!\n";
		return false;
	}
}
void Engine::unbook()
{
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
void Engine::change(const Date& date, const Time& start_time)
{
	std::string option;
	std::cin >> option;
	size_t length = booked.size();
	for (size_t i = 0; i < length; i++)
	{
		if (booked[i]->getDate() == date &&
			booked[i]->getStartTime() == start_time)
		{
			if (option == "date")
			{
				ForDate fd = *booked[i];
				fd.Change();
				if (book(fd))
				{
					delete booked[i];
					booked.erase(i);
				}
				return;
			}
			else if (option == "starttime")
			{
				std::cout << "Still in progress.\n";
				return;
				ForStartTime fst = *booked[i];
				Booked temp = *booked[i];
				fst.Change();
				delete booked[i];
				booked.erase(i);
				if (!(book(fst)))
				{
					Insert_and_sort(booked, temp);
				}
			}
			else if (option == "endtime")
			{
				std::cout << "Still in progress.\n";
				return;
			}
			else if (option == "name")
			{
				std::string _name;
				std::cin >> _name;
				booked[i]->setName(_name);
				return;
			}
			else if (option == "note")
			{
				std::string _note;
				std::cin >> _note;
				booked[i]->setName(_note);
				return;
			}
			else
			{
				std::cout << "Unknown option.\n";
				return;
			}
		}
	}
	std::cout << "There is no matching commit.\n";
}
void Engine::find()
{
	
}
void Engine::f_holiday(std::istream& in, const bool from_console)
{
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
	while (i < booked.size() && date >= booked[i]->getDate())
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

}
void Engine::findslot()
{

}
void Engine::findslotwith()
{

}
void Engine::merge()
{

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
	std::cout << "Would you like to save last changes before exiting the program?[yes/no]\n>";
	std::string answer;
	std::cin >> answer;
	if (answer == "no" || answer == "n")
	{
		close(true);
		return;
	}
	save();
	close(true);
}
bool Engine::Check_for_file()
{
	if (file[0] == '\0')
	{
		return false;
	}
	return true;
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
			std::cout << "Unable to open " << ReturnFile_name(file) << '\n';
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
			Date date;							   //declaring
			Time start_time;					   //
			Time end_time;						   //and
			std::string name;					   //
			std::string note;					   //
			stream >> date; stream.get();		   //reading
			stream >> start_time; stream.get();    //info about
			stream >> end_time; stream.get();	   //the
			stream >> name; stream.get();		   //commit
			std::getline(stream, note);			   //
			if (note == "-")
			{
				note = "";
			}
			if (!(date.Check() && start_time.Check() && end_time.Check()))
			{
				std::cout << "Incorrect date or time!\n";
				return;
			}
			book(Booked(date, start_time, end_time, name, note), false);
		}
		else//reads holidays from file
		{
			f_holiday(stream, false);
		}
		stream >> type;//reads the type of the next event
	}
	std::cout << "Successfully opened " << ReturnFile_name(file) << '\n';
	stream.close();
}
std::string Engine::ReturnFile_name(const char* file_path)
{
	size_t i = 0;
	size_t index = 0;
	while (file_path[i] != '\0')
	{
		if (file_path[i] == '\\')
		{
			index = i;
		}
		i++;
	}
	std::string file_name = "";
	while (file_path[index] != '\0')
	{
		file_name += file_path[index];
		index++;
	}
	return file_name;
}