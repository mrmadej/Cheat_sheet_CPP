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
// aby klasa by³a abstrakcyjna musi posiadaæ przynajmniej jedn¹ pure vitrual function
// taka funkcja wygl¹da nastêpuj¹co:
// virtual *zwracany typ* *nazwa*() = 0;
// nie mo¿na stworzyæ obiektu klasy abstrakcyjnej
// aby klasa pochodna z klasy abstrakcyjnej nie by³a abstract tylko concrete MUSIMY override wszystkie pure virtual function
// w przeciwnym wypadku taka klasa dalej bêdzie abstrakcyjna

// To rozwi¹zanie do wyœwietlania bêdzie dzia³aæ na ka¿d¹ klasê jak¹ sobie wymyœlisz