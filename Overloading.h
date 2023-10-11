#pragma once
#include <iostream>

using namespace std;

class Overloading
{
	friend ostream& operator<<(ostream& os, const Overloading& obj);
public:
	double zmienna_double;
	bool zmienna_bool;
	int* tablica;
	int n;
	int arr_len;

	Overloading(double zmienna_double, bool zmienna_bool, int* tablica, int n, int arr_len);
	~Overloading();
	Overloading(const Overloading& source);

	Overloading operator+(const Overloading& rhs);
	Overloading operator-(const Overloading& rhs);
	Overloading operator*(const Overloading& rhs);
	Overloading operator/(const Overloading& rhs);

	Overloading& operator++();
	Overloading operator++(int);

	Overloading operator=(const Overloading& rhs);
	Overloading operator+=(const Overloading& rhs);

	bool operator&&(const Overloading& rhs);
	bool operator||(const Overloading& rhs);
	bool operator!();

	int& operator[](int index);
	void operator()();

	bool operator<(const Overloading& rhs);
	bool operator>(const Overloading& rhs);
	bool operator==(const Overloading& rhs);
};