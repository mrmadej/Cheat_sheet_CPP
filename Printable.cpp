#include <iostream>
#include"Printable.h"

using namespace std;

ostream& operator<<(ostream& os, const Printable& obj)
{
	obj.print(os);
	return os;
}
Printable::~Printable()
{
	cout << "Printable destructor\n";
}