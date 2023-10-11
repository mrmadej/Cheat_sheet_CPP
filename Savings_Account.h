#pragma once
#include <iostream>
#include "Account.h" // trzeba zaincludowaæ to z czego chcemy dzidziczyæ

using namespace std;

// concrete class
class Savings_Account :public Account // class NAZWA_KLASY: JAK_DZIEDZICZYMY NAZWA_KLASY_Z_KTÓREJ_DZIEDZICZYMY
{
public:
	double interest_rate;

	Savings_Account(double interest_rate, double balance, string name);
	virtual ~Savings_Account();
	// nie trzeba pisaæ s³owa virtual w klasach pochodnych jeœli ju¿ jest w klasie podstawowej, ale jest to dobry zwyczaj
	virtual void print(ostream& os)const override;
	virtual void deposit(double ammount) override;
	virtual void withdraw(double ammount) override;
	// override sprawdza czy rzeczywiœcie overriden function a nie redefined function
	// jeœli zrobimy literówke lub np nasza funkcja w klasie podstawowej ma oznaczenie const czyli, ¿e nic nie zmienia
	// a tutaj w klasie pochodnej zapomnieliœmy tego dodaæ to override wyrzuci nam b³¹d
	// gdybyœmy nie mieli override program uruchomi³by siê normalnie i dzia³a³, przez co trudniej by³oby namierzyæ b³¹d

	Savings_Account& operator=(const Savings_Account& rhs);
};
// mo¿na dziedziczyæ public, private lub protected

// klasy które dziedzicz¹ nie dziedzicz¹ nastêpuj¹cych rzeczy:
// konstruktora klasy podstawowej
// destruktora klasy podstawowej
// przeci¹¿onych operatorów przypisanania "="
// funkcji zaprzyjaŸnionych z klas¹ podstawow¹
// ALE mog¹ siê odwo³ywaæ do konstruktorów, destruktrów i przeci¹¿¹nych operatorów przypisania

// Multiple inheritance
// tutaj dziedziczymy tylko z jednej klasy, jednak mo¿na dziedziczyæ z wielu klas jednoczeœnie
// class *Nazwa klasy*: *rodzaj dziedziczenia* *Nazwa klasy podstawowej*, *rodzaj dziedziczenia* *Nazwa klasy podstawowej* ... 

// jak fukncja jest virtual to znaczy, ¿e jest override, jak nie to redefine
// An overridden function is a method in a descendant class that has a different definition than a virtual function in an ancestor class. 
// The compiler chooses which function is desired based upon the type of the object being used to call the function.

// A redefined function is a method in a descendant class that has a different definition than a non - virtual function in an ancestor class.
// Don't do this. Since the method is not virtual, the compiler chooses which function to call based upon the static type of the 
// object reference rather than the actual type of the object.

// final specifier
// Jeœli chcemy zablokowaæ mo¿liwoœæ dalszego dziedziczenia danej klasy u¿ywamy s³owa final
// np: class My_class final
// Jeœli chcemy zablokowaæ overriding funkcji to te¿ u¿ywamy final