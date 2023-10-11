#pragma once
#include <iostream>

using namespace std;

template<typename T>
class Item
{
public:
	string name;
	T value;

	Item(string name, T value);
	string get_name() const;
	T get_value() const;

};
// Jak widaæ za ka¿dym razem trzeba pisaæ template, nawet jak w danej metodzie nie korzystamy z T
// mo¿na pisaæ to tutaj, ale równie dobrze mo¿na pisaæ to od razu w klasie
// UWAGA jak robi siê klasê z template to trzeba pisaæ wszystko w .h
template<typename T>
Item<T>::Item(string name, T value)
	:name{name}, value{value}
{

}
template<typename T>
string Item<T>::get_name() const
{
	return name;
}
template<typename T>
T Item<T>::get_value() const
{
	return value;
}

// przez to, ¿e robimy to przez template to nie trzeba tworzyæ tablicy przez new
template<typename T, int N>
class my_array
{
private:
	int size = N;
	T values[N];

	friend ostream& operator<<(ostream& os, const my_array<T, N> &arr)
	{
		os << "[ ";
		for (const auto& val : arr.values)
		{
			os << val << " ";
		}
		os << "]\n";
		return os;
	}
public:
	my_array() = default;
	my_array(T init_val)
	{
		for (auto& val : values)
		{
			val = init_val;
		}
	}
	// wype³nianie tablicy podan¹ wartoœci¹
	void fill(T val)
	{
		for (auto& item : values)
		{
			item = val;
		}
	}
	int get_size() const
	{
		return size;
	}
	T& operator[](int index)
	{
		return this->values[index];
	}
};