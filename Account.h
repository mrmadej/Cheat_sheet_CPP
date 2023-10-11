#pragma once
#include <iostream>
#include "Printable.h"

using namespace std;

class Account:public Printable // concrete class
{
public:
	double balance;
	string name;

	virtual void print(ostream& os)const override;
	virtual void deposit(double ammount);
	virtual void withdraw(double ammount);

	Account();
	Account(double balance, string name);
	virtual ~Account(); // je�li mamy funkcje wirtualne w klasie to MUSIMY zapewni� wirtualny destruktor

	Account& operator=(const Account& rhs);

};