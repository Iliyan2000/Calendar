#pragma once
#include <fstream>
#include "Booked.h"

class Engine
{
public:
	Engine(const Vector<Booked*> &vec_b = Vector<Booked*>(),
		const Vector<Date*> &vec_h = Vector<Date*>(),
		const char first_sym = '\0',
		const bool _saved = false);

	void open();//check
	void close(const bool exiting = false);//check
	void save();
	void saveas();
	void help();
	void book(std::istream& in = std::cin, const bool from_console = true);//check
	void unbook();//check
	void agenda();//check
	void change();
	void find();
	void f_holiday(std::istream& in = std::cin, const bool from_console = true);//check
	void busydays();
	void findslot();
	void findslotwith();
	void merge();
	void unknown();//check
	void if_saved();//check

private:
	static const size_t FILENAME_LENGTH = 128;
	static const size_t IGNORE_LENGTH = 128;

	Vector<Booked*> booked;
	Vector<Date*> holiday;
	char file[FILENAME_LENGTH];
	bool saved;
	void open_file();

};