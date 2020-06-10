#pragma once
#include "Booked.h"

class Engine
{
public:
	Engine(const Vector<Booked*> &vec_b = Vector<Booked*>(),
		const Vector<Date*> &vec_h = Vector<Date*>(),
		const char first_sym = '\0');

	void open();
	void close();
	void save();
	void saveas();
	void help();
	void book();//check
	void unbook();//check
	void agenda();//check
	void change();
	void find();
	void f_holiday();//check
	void busydays();
	void findslot();
	void findslotwith();
	void merge();
	void unknown();//check

private:
	static const size_t FILENAME_LENGTH = 128;
	static const size_t IGNORE_LENGTH = 128;

	Vector<Booked*> booked;
	Vector<Date*> holiday;
	char file[FILENAME_LENGTH];
};