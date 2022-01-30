//C++ Program to implement Vector Data Structure
#pragma once
#include<iostream>
using namespace std;
template<typename T>
class vector
{
	unsigned int capacity;
	unsigned int size;
	T* theData;

public:
	vector();
	vector(int capactiy);
	vector(const vector& d);
	vector& operator=(const vector& d);
	~vector();
	void push_back(T data);
	void erase(int index);
	T operator[](int index);
	unsigned int getSize();
	unsigned int getMaxCapacity();
	T* getData();
};

template<typename T>
inline vector<T>::vector()
{
	capacity = 1;
	size = 0;
	theData = new T[capacity];
}

template<typename T>
inline vector<T>::vector(int capactiy)
{
	size = 0;
	this->capacity = capactiy;
	theData = new T[capacity];
}

template<typename T>
inline vector<T>::vector(const vector& d)
{
	this->capacity = d.capacity;
	this->size = d.size;
	theData = nullptr;
	theData = new T[capacity];
	for (int i = 0; i < size; i++)
	{
		theData[i] = d.theData[i];
	}
}

template<typename T>
inline vector<T>& vector<T>::operator=(const vector<T>& d)
{
	this->capacity = d.capacity;
	this->size = d.size;
	delete[] theData;
	theData = new T[capacity];
	for (int i = 0; i < size; i++)
	{
		theData[i] = d.theData[i];
	}
	return *this;
}

template<typename T>
inline vector<T>::~vector()
{
	delete[] theData;
}

template<typename T>
inline void vector<T>::push_back(T data)
{
	if (size == capacity)
	{
		T* tempArray = new T[capacity * 2];
		for (unsigned int i = 0; i < size; i++)
		{
			tempArray[i] = theData[i];
		}
		delete[] theData;
		theData = tempArray;
		capacity *= 2;
	}
	theData[size] = data;
	size++;
}

template<typename T>
inline void vector<T>::erase(int index)
{

	T* tempArray = new T[size - 1];
	for (unsigned int i = 0; i < index; i++)
	{
		tempArray[i] = theData[i];
	}
	for (unsigned int i = index+1; i < size; i++)
	{
		tempArray[i-1] = theData[i];
	}
	delete[] theData;
	theData = tempArray;
	size--;
	if (size * 2 < capacity)
	{
		capacity /= 2;
	}
}

template<typename T>
inline T vector<T>::operator[](int index)
{
	return theData[index];
}

template<typename T>
inline unsigned int vector<T>::getSize()
{
	return size;
}

template<typename T>
inline unsigned int vector<T>::getMaxCapacity()
{
	return capacity;
}

template<typename T>
inline T* vector<T>::getData()
{
	return theData;
}

int main() {
	vector<int> test;
	test.push_back(1);
	test.push_back(2);
	test.push_back(3);
	test.push_back(4);
	test.push_back(5);
	test.push_back(6);

	for (int i = 0; i < test.getSize(); i++)
	{
		cout << test[i] << endl;
	}

	test.erase(0);
	test.erase(2);

	for (int i = 0; i < test.getSize(); i++)
	{
		cout << test[i] << endl;
	}


	return 0;
}