#include <iostream>
#include "Account.h"
#include "Exceptions.h"

using namespace std;

Account::Account()
	:Account(0.0, "Defoult Name")
{
	cout << "Account 0 args constructor\n";
}
Account::Account(double balance, string name)
	:balance{balance}, name{name}
{
	if (balance < 0)
	{
		throw NegativeBalanceException();
	}
	cout << "Account 2 args constructor\n";
}
Account::~Account()
{
	cout << "Account destructor for object named: " << this->name << endl;
}

void Account::deposit(double ammount)
{
	balance += ammount;
	cout << "Current balance is: " << balance << endl;
}
void Account::withdraw(double ammount)
{
	if ((balance - ammount) >= 0)
	{
		balance -= ammount;
		cout << "Current balance is: " << balance << endl;
	}
	else
	{
		cout << "Not enough money\n";
	}
}
Account& Account::operator=(const Account& rhs)
{
	if (this != &rhs) //sprawdzamy czy nie s¹ to te same obiekty
	{
		this->balance = rhs.balance;
		this->name = rhs.name;
	}
	return *this;
}
void Account::print(ostream& os)const
{
	os << "Account: " << name << ", has a balance: " << balance << endl;
}