#pragma once
#include "Time.h"
#include "Date.h"
#include "Vector.h"

class Booked
{
public:
	/**
	*коструктор по подразбиране/с параметри
	*/
	Booked(const Date& _date = Date(),
		const Time& _start_time = Time(),
		const Time& _end_time = Time(),
		const std::string _name = "",
		const std::string _note = "");
	/**
	*копи конструктор
	*/
	Booked(const Booked& other);
	/**
	*оператор за присвояване
	*/
	Booked& operator=(const Booked& other) = default;

	/**
	*селектор за дата
	*/
	inline Date getDate() const { return date; }
	/**
	*селектор за начален час
	*/
	inline Time getStartTime() const { return start_time; }
	/**
	*селектор за краен час
	*/
	inline Time getEndTime() const { return end_time; }
	/**
	*селектор за име
	*/
	inline std::string getName() const { return name; }
	/**
	*селектор за коментар
	*/
	inline std::string getNote() const { return note; }
	/**
	*мутатор за дата
	*/
	void setDate(const Date& _date) { date = _date; }
	/**
	*мутатор за начален час
	*/
	void setStartTime(const Time& _start_time) { start_time = _start_time; }
	/**
	*мутатор за краен час
	*/
	void setEndTime(const Time& _end_time) { end_time = _end_time; }
	/**
	*мутатор за име
	*/
	void setName(const std::string _name) { name = _name; }
	/**
	*мутатор за коментар
	*/
	void setNote(const std::string _note) { note = _note; }
	/**
	*метод за разделяне на среща на две части, с помоща на допулнителна среща
	*/
	void Split(Booked& other);
	/**
	*метод за променяне на член данните
	*/
	virtual void Change();
	/**
	*сравнява две срещи дали са идентични
	*/
	bool operator==(const Booked& other);

protected:
	Date date;
	Time start_time;
	Time end_time;
	std::string name;
	std::string note;
};
/**
*метод, който вкарва хронологично дадена среща в деден масив от други такива
*/
void Insert_and_sort(Vector<Booked*>& vec, const Booked& obj);