#pragma once
#include <iostream>
#include "Account.h" // trzeba zaincludowa� to z czego chcemy dzidziczy�

using namespace std;

// concrete class
class Savings_Account :public Account // class NAZWA_KLASY: JAK_DZIEDZICZYMY NAZWA_KLASY_Z_KT�REJ_DZIEDZICZYMY
{
public:
	double interest_rate;

	Savings_Account(double interest_rate, double balance, string name);
	virtual ~Savings_Account();
	// nie trzeba pisa� s�owa virtual w klasach pochodnych je�li ju� jest w klasie podstawowej, ale jest to dobry zwyczaj
	virtual void print(ostream& os)const override;
	virtual void deposit(double ammount) override;
	virtual void withdraw(double ammount) override;
	// override sprawdza czy rzeczywi�cie overriden function a nie redefined function
	// je�li zrobimy liter�wke lub np nasza funkcja w klasie podstawowej ma oznaczenie const czyli, �e nic nie zmienia
	// a tutaj w klasie pochodnej zapomnieli�my tego doda� to override wyrzuci nam b��d
	// gdyby�my nie mieli override program uruchomi�by si� normalnie i dzia�a�, przez co trudniej by�oby namierzy� b��d

	Savings_Account& operator=(const Savings_Account& rhs);
};
// mo�na dziedziczy� public, private lub protected

// klasy kt�re dziedzicz� nie dziedzicz� nast�puj�cych rzeczy:
// konstruktora klasy podstawowej
// destruktora klasy podstawowej
// przeci��onych operator�w przypisanania "="
// funkcji zaprzyja�nionych z klas� podstawow�
// ALE mog� si� odwo�ywa� do konstruktor�w, destruktr�w i przeci���nych operator�w przypisania

// Multiple inheritance
// tutaj dziedziczymy tylko z jednej klasy, jednak mo�na dziedziczy� z wielu klas jednocze�nie
// class *Nazwa klasy*: *rodzaj dziedziczenia* *Nazwa klasy podstawowej*, *rodzaj dziedziczenia* *Nazwa klasy podstawowej* ... 

// jak fukncja jest virtual to znaczy, �e jest override, jak nie to redefine
// An overridden function is a method in a descendant class that has a different definition than a virtual function in an ancestor class. 
// The compiler chooses which function is desired based upon the type of the object being used to call the function.

// A redefined function is a method in a descendant class that has a different definition than a non - virtual function in an ancestor class.
// Don't do this. Since the method is not virtual, the compiler chooses which function to call based upon the static type of the 
// object reference rather than the actual type of the object.

// final specifier
// Je�li chcemy zablokowa� mo�liwo�� dalszego dziedziczenia danej klasy u�ywamy s�owa final
// np: class My_class final
// Je�li chcemy zablokowa� overriding funkcji to te� u�ywamy final