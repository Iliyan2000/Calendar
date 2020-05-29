#include "Holiday.h"

Holiday::Holiday(const Date& _date, const bool _fromFile)
	:date(_date), fromFile(_fromFile)
{

}
Holiday::Holiday(const Holiday& other)
{
	date = other.date;
	fromFile = other.fromFile;
}

void Insert_and_sort(Vector<Holiday*>& vec, const Holiday& obj)
{
	size_t i = 0;
	size_t length = vec.size();
	Holiday* pobj = new Holiday;
	*pobj = obj;
	for (size_t i = 0; i < length; i++)
	{
		if (obj.getDate() < vec[i]->getDate())
		{
			vec.insert(i, pobj);
			return;
		}
	}
	vec.push_back(pobj);
}