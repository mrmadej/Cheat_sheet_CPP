#include <iostream>
#include "Savings_Account.h"

using namespace std;

// konstruktor klasy podstawowej jest zawsze wywo³ywany przed konstruktorem klasy pochodnej
// jeœli nie sprecyzujemy który jak tutaj Account(balance, name) to zostanie wywo³any podstawowy konstruktor bez argumentów
// jeœli nie ma takiego to jest problem
Savings_Account::Savings_Account(double interest_rate, double balance, string name)
	:Account(balance, name), interest_rate{interest_rate}
{
	cout << "Savings_Account 3 args constructor\n";
}
Savings_Account::~Savings_Account()
{
	cout << "Savings_Account destructor for object named: " << this->name << endl;
}

void Savings_Account::deposit(double ammount)
{
	ammount += (ammount * interest_rate / 100);
	Account::deposit(ammount);
}
void Savings_Account::withdraw(double ammount) // w³aœciwie nic nie dodajemy nowego do tej metody, wiêc nie trzeba jej nawet implementowaæ
{
	Account::withdraw(ammount);
}
Savings_Account& Savings_Account::operator=(const Savings_Account& rhs)
{

	if (this != &rhs) //sprawdzamy czy nie s¹ to te same obiekty
	{
		Account::operator=(rhs); // slicing, z racji, ¿e Account::operator=() oczekuje referencji na obiekt typu Account
		// wycinana jest czêœæ Account z Savings_Account.
		this->interest_rate = rhs.interest_rate;
	}
	return *this;
}
void Savings_Account::print(ostream& os)const
{
	os << "Account: " << name << ", has a balance: " << balance << ", with interest rate: " << interest_rate << endl;
}