#include "Engine.h"

int main()
{
	std::string comand = "";
	Engine E;

	std::cout << "To start working, first you need to open calendar.\n";
	while (comand.compare("exit"))
	{
		std::cout << '>';
		std::cin >> comand;
		if (!comand.compare("open"))
		{
			E.open();
			continue;
		}
		else if (!comand.compare("close"))
		{
			std::cin.ignore(IGNORE_LENGTH, '\n');
			if (!E.Check_for_file())
			{
				std::cout << "There is no open file.\n";
				continue;
			}
			E.close();
			continue;
		}
		else if (!comand.compare("save"))
		{
			std::cin.ignore(IGNORE_LENGTH, '\n');
			if (!E.Check_for_file())
			{
				std::cout << "There is no open file.\n";
				continue;
			}
			E.save();
			continue;
		}
		else if (!comand.compare("saveas"))
		{
			if (!E.Check_for_file())
			{
				std::cin.ignore(IGNORE_LENGTH, '\n');
				std::cout << "There is no open file.\n";
				continue;
			}
			E.saveas();
			continue;
		}
		else if (!comand.compare("help"))
		{
			E.help();
			continue;
		}
		else if (!comand.compare("book"))
		{
			Date date;							   //declaring
			Time start_time;					   //
			Time end_time;						   //and
			std::string name;					   //
			std::string note;					   //
			std::cin >> date; std::cin.get();	   //reading
			std::cin >> start_time; std::cin.get();//info about
			std::cin >> end_time; std::cin.get();  //the
			std::cin >> name; std::cin.get();	   //commit
			std::getline(std::cin, note);		   //
			if (note == "-")
			{
				note = "";
			}
			if (!(date.Check() && start_time.Check() && end_time.Check()))
			{
				std::cout << "Incorrect date or time!\n";
				continue;
			}
			if (!E.Check_for_file())
			{
				std::cin.ignore(IGNORE_LENGTH, '\n');
				std::cout << "There is no open file.\n";
				continue;
			}
			E.book(Booked(date, start_time, end_time, name, note));
			continue;
		}
		else if (!comand.compare("unbook"))
		{
			if (!E.Check_for_file())
			{
				std::cin.ignore(IGNORE_LENGTH, '\n');
				std::cout << "There is no open file.\n";
				continue;
			}
			E.unbook();
			continue;
		}
		else if (!comand.compare("agenda"))
		{
			if (!E.Check_for_file())
			{
				std::cin.ignore(IGNORE_LENGTH, '\n');
				std::cout << "There is no open file.\n";
				continue;
			}
			E.agenda();
			continue;
		}
		else if (!comand.compare("change"))
		{
			if (!E.Check_for_file())
			{
				std::cin.ignore(IGNORE_LENGTH, '\n');
				std::cout << "There is no open file.\n";
				continue;
			}
			Date date;
			Time start_time;
			std::cin >> date >> start_time;
			if (!(date.Check() && start_time.Check()))
			{
				std::cout << "Incorrect date or time!\n";
				continue;
			}
			E.change(date, start_time);
			continue;
		}
		else if (!comand.compare("find"))
		{
			if (!E.Check_for_file())
			{
				std::cin.ignore(IGNORE_LENGTH, '\n');
				std::cout << "There is no open file.\n";
				continue;
			}
			E.find();
			continue;
		}
		else if (!comand.compare("holiday"))
		{
			if (!E.Check_for_file())
			{
				std::cin.ignore(IGNORE_LENGTH, '\n');
				std::cout << "There is no open file.\n";
				continue;
			}
			E.f_holiday();
			continue;
		}
		else if (!comand.compare("busydays"))
		{
			if (!E.Check_for_file())
			{
				std::cin.ignore(IGNORE_LENGTH, '\n');
				std::cout << "There is no open file.\n";
				continue;
			}
			E.busydays();
			continue;
		}
		else if (!comand.compare("findslot"))
		{
		if (!E.Check_for_file())
			{
				std::cin.ignore(IGNORE_LENGTH, '\n');
				std::cout << "There is no open file.\n";
				continue;
			}
			E.findslot();
			continue;
		}
		else if (!comand.compare("findslotwith"))
		{
			if (!E.Check_for_file())
			{
				std::cin.ignore(IGNORE_LENGTH, '\n');
				std::cout << "There is no open file.\n";
				continue;
			}
			E.findslotwith();
			continue;
		}
		else if (!comand.compare("merge"))
		{
			if (!E.Check_for_file())
			{
				std::cin.ignore(IGNORE_LENGTH, '\n');
				std::cout << "There is no open file.\n";
				continue;
			}
			E.merge();
			continue;
		}
		else if (comand.compare("exit"))
		{
			E.unknown();
		}
	}
	E.if_saved();
	std::cout << "Exiting the program...\n";

	return 0;
}