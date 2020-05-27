#pragma once

const size_t DEF_C = 4;
const size_t DEF_S = 0;

template <typename T>
class Vector
{
public:
	Vector(const size_t _capacity = DEF_C, const size_t _size = DEF_S);
	Vector(const Vector<T>&);
	Vector<T>& operator=(const Vector<T>&);
	~Vector();

	inline size_t size() const { return m_size; }
	inline size_t capacity() const { return m_capacity; }
	void reserve(const size_t _capacity);
	inline T& operator[](const size_t index) const { return obj[index]; }
	void push_back(const T&);
	inline void pop_back() { m_size--; }
	//void
	//void 

private:
	T* obj;
	size_t m_capacity;
	size_t m_size;
	void copy(const Vector<T>&);
	void clear();
};

//public methods
//Big four
template <typename T>
Vector<T>::Vector(const size_t _capacity, const size_t _size)
	:m_capacity(_capacity),
	m_size(_size),
	obj(new T[_capacity])
{}
template <typename T>
Vector<T>::Vector(const Vector<T>& other)
{
	copy(other);
}
template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other)
{
	if (this != &other)
	{
		clear();
		copy(other);
	}
	return *this;
}
template <typename T>
Vector<T>::~Vector()
{
	clear();
}
//other public methods
template <typename T>
void Vector<T>::reserve(const size_t _capacity)
{
	if (_capacity > m_capacity)
	{
		Vector temp(*this);
		clear();
		m_capacity = _capacity;
		obj = new T[m_capacity];
		for (size_t i = 0; i < m_size; i++)
		{
			obj[i] = temp.obj[i];
		}
	}
}
template <typename T>
void Vector<T>::push_back(const T& _obj)
{
	m_size++;
	obj[m_size - 1] = _obj;
	if (m_size == m_capacity)
	{
		reserve(2 * m_capacity);
	}
}
//private methods
template <typename T>
void Vector<T>::copy(const Vector<T>& other)
{
	m_capacity = other.m_capacity;
	m_size = other.m_size;
	obj = new T[m_capacity];
	for (size_t i = 0; i < m_size; i++)
	{
		obj[i] = other.obj[i];
	}
}
template <typename T>
void Vector<T>::clear()
{
	delete[]obj;
}