#include <iostream>
#include "Overloading.h"

using namespace std;

Overloading::Overloading(double zmienna_double, bool zmienna_bool, int* tablica, int n, int arr_len)
{
	this->zmienna_double = zmienna_double;
	this->zmienna_bool = zmienna_bool;
	this->n = n;
	this->arr_len = arr_len;
	this->tablica = new int[arr_len]; // tworzenie nowej tablicy przez new aby nie nadpisywaæ orygina³u
	for (int i = 0; i < arr_len; i++)
	{
		this->tablica[i] = tablica[i]; // kopiowanie wartoœci z oryginalnej tablicy
	}
}
Overloading::Overloading(const Overloading& source)
	:zmienna_double{ source.zmienna_double }, zmienna_bool{source.zmienna_bool}, n{source.n}, arr_len{source.arr_len}
{
	this->tablica = new int[arr_len]; // WAZNE maja byc takie [] nawiasy nie takie () XD
	for (int i = 0; i < arr_len; i++)
	{
		this->tablica[i] = source.tablica[i];
	}
}
Overloading::~Overloading()
{
	delete[]tablica;
}
Overloading Overloading::operator+(const Overloading& rhs)
{
	Overloading temp ((this->zmienna_double) + rhs.zmienna_double, rhs.zmienna_bool, rhs.tablica, (this->n) + rhs.n, arr_len);
	return temp;
}
Overloading Overloading::operator-(const Overloading& rhs)
{
	Overloading temp((this->zmienna_double) - rhs.zmienna_double, rhs.zmienna_bool, rhs.tablica, (this->n) - rhs.n, arr_len);
	return temp;
}
Overloading Overloading::operator*(const Overloading& rhs)
{
	Overloading temp((this->zmienna_double) * rhs.zmienna_double, rhs.zmienna_bool, rhs.tablica, (this->n) * rhs.n, arr_len);
	return temp;
}
Overloading Overloading::operator/(const Overloading& rhs)
{
	Overloading temp((this->zmienna_double) / rhs.zmienna_double, rhs.zmienna_bool, rhs.tablica, (this->n) / rhs.n, arr_len);
	return temp;
}

Overloading& Overloading::operator++()
{
	this->zmienna_double++;
	n++;
	return *this;
}
Overloading Overloading::operator++(int)
{
	Overloading temp = *this;
	++* this;
	return temp;
}
ostream& operator<<(ostream& os, const Overloading& obj)
{
	os << "Zmienna double: " << obj.zmienna_double << endl << "Zmienna bool: " << obj.zmienna_bool << endl << "Tablica: { ";
	for (int i = 0; i < obj.arr_len; i++)
	{
		os << obj.tablica[i] << "; ";
	}
	os << "}\n" << "Zmienna n: " << obj.n << endl;
	return os;
}
Overloading Overloading::operator=(const Overloading& rhs)
{
	this->arr_len = rhs.arr_len;
	this->zmienna_double = rhs.zmienna_double;
	this->zmienna_bool = rhs.zmienna_bool;
	this->tablica = new int[rhs.arr_len];
	for (int i = 0; i < rhs.arr_len; i++)
	{
		this->tablica[i] = rhs.tablica[i];
	}
	this->n = rhs.n;

	return *this;
}
Overloading Overloading::operator+=(const Overloading& rhs)
{
	*this = *this + rhs;
	return *this;
}
bool Overloading::operator&&(const Overloading& rhs)
{
	return ((this->zmienna_bool) && rhs.zmienna_bool);
}
bool Overloading::operator||(const Overloading& rhs)
{
	return ((this->zmienna_bool) || rhs.zmienna_bool);
}
bool Overloading::operator!()
{
	return !(this->zmienna_bool);
}
int& Overloading::operator[](int index)
{
	if (index <= (this->arr_len) && index >= 0)
	{
		return this->tablica[index];
	}
	else
	{
		cout << "Index invalid\n";
		exit(0);
	}
}
void Overloading::operator()()
{
	cout << "Nie mam pojecia co robie\n";
}
bool Overloading::operator<(const Overloading& rhs)
{
	return (this->n) < rhs.n;
}
bool Overloading::operator>(const Overloading& rhs)
{
	return (this->n) > rhs.n;
}
bool Overloading::operator==(const Overloading& rhs)
{
	return (this->n) == rhs.n;
}