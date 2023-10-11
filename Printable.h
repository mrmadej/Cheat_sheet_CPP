#pragma once
#include <iostream>

using namespace std;

class Printable // abstract class
{
	friend ostream& operator<<(ostream& os, const Printable& obj);
public:
	virtual void print(ostream& os)const = 0; // pure virutal function
	virtual ~Printable();
};


// Jest to klasa abstrakcyjna
// aby klasa by�a abstrakcyjna musi posiada� przynajmniej jedn� pure vitrual function
// taka funkcja wygl�da nast�puj�co:
// virtual *zwracany typ* *nazwa*() = 0;
// nie mo�na stworzy� obiektu klasy abstrakcyjnej
// aby klasa pochodna z klasy abstrakcyjnej nie by�a abstract tylko concrete MUSIMY override wszystkie pure virtual function
// w przeciwnym wypadku taka klasa dalej b�dzie abstrakcyjna

// To rozwi�zanie do wy�wietlania b�dzie dzia�a� na ka�d� klas� jak� sobie wymy�lisz