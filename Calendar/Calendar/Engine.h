#pragma once
#include <fstream>
#include "Inheritance_Booked.h"

class Engine
{
public:
	/**
	*коструктор по подразбиране/с параметри
	*/
	Engine(const Vector<Booked*> &vec_b = Vector<Booked*>(),
		const Vector<Date*> &vec_h = Vector<Date*>(),
		const char first_sym = '\0',
		const bool _saved = false);

	/**
	*отваря файл
	*/
	void open();
	/**
	*затваря текущо заредения файл
	*/
	void close(const bool exiting = false);//check
	/**
	*записва текущата информация в текущо отворения файл
	*/
	void save();//check
	/**
	*записва текущата информация в друг файл
	*/
	void saveas();
	/**
	*извежда кратка информация за поддържаните от програмата команди
	*/
	void help();
	/**
	*записва ангажимент в календара
	*/
	bool book(const Booked& B, const bool from_console = true);
	/**
	*отписва ангажимент от календара
	*/
	void unbook();//check
	/**
	*извежда хронологичен списък с всички ангажименти за деня
	*/
	void agenda();//check
	/**
	*променя информацията за ангажимента
	*/
	void change(const Date& date, const Time& start_time);
	/**
	*извеждат се данните за всички срещи, в чието име или бележка се съдържа даден низ
	*/
	void find();
	/**
	*записва даден ден като почивен
	*/
	void f_holiday(std::istream& in = std::cin, const bool from_console = true);
	void busydays();
	void findslot();
	void findslotwith();
	void merge();
	/**
	*метод за непознати команди
	*/
	void unknown();//check
	/**
	*проверява дали текущо отворения файл е запаметен
	*/
	void if_saved();//check
	/**
	*проверява дали е отворен файл
	*/
	bool Check_for_file();//check

private:
	static const size_t FILENAME_LENGTH = 128;

	Vector<Booked*> booked;
	Vector<Date*> holiday;
	char file[FILENAME_LENGTH];
	bool saved;
	/**
	*метод който отваря файл
	*/
	void open_file();
	/**
	*метод който при въведен път на даден файл жруща само неговото име
	*/
	std::string ReturnFile_name(const char* file_path);

};