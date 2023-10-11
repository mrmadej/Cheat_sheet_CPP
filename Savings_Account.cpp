#include <iostream>
#include "Savings_Account.h"

using namespace std;

// konstruktor klasy podstawowej jest zawsze wywo�ywany przed konstruktorem klasy pochodnej
// je�li nie sprecyzujemy kt�ry jak tutaj Account(balance, name) to zostanie wywo�any podstawowy konstruktor bez argument�w
// je�li nie ma takiego to jest problem
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
void Savings_Account::withdraw(double ammount) // w�a�ciwie nic nie dodajemy nowego do tej metody, wi�c nie trzeba jej nawet implementowa�
{
	Account::withdraw(ammount);
}
Savings_Account& Savings_Account::operator=(const Savings_Account& rhs)
{

	if (this != &rhs) //sprawdzamy czy nie s� to te same obiekty
	{
		Account::operator=(rhs); // slicing, z racji, �e Account::operator=() oczekuje referencji na obiekt typu Account
		// wycinana jest cz�� Account z Savings_Account.
		this->interest_rate = rhs.interest_rate;
	}
	return *this;
}
void Savings_Account::print(ostream& os)const
{
	os << "Account: " << name << ", has a balance: " << balance << ", with interest rate: " << interest_rate << endl;
}