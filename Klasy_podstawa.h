#pragma once
#include <iostream>

using namespace std;

class klasy_podstawa
{
	//je�li nie zdefiniujesz czy co� jest private, public czy protected to z automatu jest private
	//protected dzia�a jak private. Dopiero w dziedziczeniu jest r�nica
protected:
	int protect;
private:
	static int count;
	int priv;
	void get_private() const;
public:
	int pub;
	int* tab;
	int len;
	
	//constructor z regu�y powinien by� public. Jest jaka� tam sytuacja co jest private, ale nie ogarniam tego za bardzo
	klasy_podstawa(); // delegating constructor
	klasy_podstawa(int protect); // delegating constructor
	klasy_podstawa(int protect, int pirv); //constructor; initialization list
	klasy_podstawa(int protect, int priv, int pub, int tab[], int len); // counstructor; nazwy mog� by� dowolne
	// mo�na u�y� te� defoultowych warto�ci zamiast kilku kontruktor�w. Wtedy piszesz:
	// klasy_podstawa(int protect = -1, int priv = -1, int pub = -1);
	klasy_podstawa(const klasy_podstawa& source); // copy constructor. WAZNE musi byc przez referencje & 
	// bo inaczej robiona by�aby kopia czyli wo�ano by caly czas copy constructor bez ko�ca
	// const po to �eby nic nie zmieni� w �r�dle

	~klasy_podstawa(); //destructor w zasadzie potrzebny tylko jak robisz co� z new czy co� otwierasz otwierasz, normalnie wystarczy defoultowy 

	void get_values() const; // const po to aby zagwarantowa�, �e nie zmieniamy warto�ci t� metod�, aby m�g� jej u�y� obiekt const
	void set_values(int pub, int priv, int protect);
	static int get_count();
};