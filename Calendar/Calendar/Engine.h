#pragma once
#include "Booked.h"
#include "Holiday.h"

class Engine
{
public:
	Engine(const Vector<Booked*> &vec_b = Vector<Booked*>(),
		const Vector<Holiday*> &vec_h = Vector<Holiday*>(),
		const char first_sym = '\0');

	void open();
	void close();
	void save();
	void saveas();
	void help();
	void book();
	void unbook();
	void agenda();
	void change();
	void find();
	void f_holiday();
	void busydays();
	void findslot();
	void findslotwith();
	void unknown();

private:
	static const size_t FILENAME_LENGTH = 128;
	static const size_t IGNORE_LENGTH = 128;

	Vector<Booked*> booked;
	Vector<Holiday*> holiday;
	char file[FILENAME_LENGTH];
};