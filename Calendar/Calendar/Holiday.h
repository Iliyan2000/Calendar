#pragma once
#include "Date.h"
#include "Vector.h"

class Holiday
{
public:
	Holiday(const Date& _date = Date(), const bool _fromFile = false);
	Holiday(const Holiday& other);

	inline Date getDate() const { return date; }
	inline bool getFromFile() const { return fromFile; }
	void setDate(const Date& _date) { date = _date; }
	void setFromFile(const bool _fromFile) { fromFile = _fromFile; }

private:
	Date date;
	bool fromFile;
};
void Insert_and_sort(Vector<Holiday*>& vec, const Holiday& obj);