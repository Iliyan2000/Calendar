#include "Engine.h"

int main()
{
	std::string comand = "";
	Engine E;

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
			E.close();
			continue;
		}
		else if (!comand.compare("save"))
		{
			E.save();
			continue;
		}
		else if (!comand.compare("saveas"))
		{
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
			E.book();
			continue;
		}
		else if (!comand.compare("unbook"))
		{
			E.unbook();
			continue;
		}
		else if (!comand.compare("agenda"))
		{
			E.agenda();
			continue;
		}
		else if (!comand.compare("change"))
		{
			E.change();
			continue;
		}
		else if (!comand.compare("find"))
		{
			E.find();
			continue;
		}
		else if (!comand.compare("holiday"))
		{
			E.f_holiday();
			continue;
		}
		else if (!comand.compare("busydays"))
		{
			E.busydays();
			continue;
		}
		else if (!comand.compare("findslot"))
		{
			E.findslot();
			continue;
		}
		else if (!comand.compare("findslotwith"))
		{
			E.findslotwith();
			continue;
		}
		else if (comand.compare("exit"))
		{
			E.unknown();
		}
	}
	std::cout << "Exiting the program...\n";

	return 0;
}