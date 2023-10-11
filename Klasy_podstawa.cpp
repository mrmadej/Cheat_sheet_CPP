#include <iostream>
#include "Klasy_podstawa.h"

int klasy_podstawa::count = 0; // inicjalizacja zmiennej statycznej. Tylko raz i tylko w .cpp

using namespace std;

klasy_podstawa::klasy_podstawa(int protect, int priv, int pub, int tab[], int len)
{
	this->protect = protect;
	this->priv = priv;
	this->pub = pub;
	this->len = len;
	if (len > 0)
	{
		this->tab = new int[len]; // WAZNE maja byc takie [] nawiasy nie takie () XD
		for (int i = 0; i < len; i++)
		{
			this->tab[i] = tab[i];
		}
	}
	else
	{
		this->tab = NULL;
	}
	
	cout << "Konstruktor z 5 argumentami" << endl;
	count++; // tworzymy obiekt, wi�c zwi�kszamy licznik
}
// Konstrukor z initialization list. Efekt jest jest ten sam co wyzej tylko robi to troche inaczej; 
// najpierw jest robione to co w initialization list a potem to co w {}
klasy_podstawa::klasy_podstawa(int protect, int priv)
	:protect{protect}, priv{priv}
{
	pub = -1;
	tab = NULL;
	len = 0;
	cout << "Konstrukor z initialization list, 2 args" << endl;
	count++; // tworzymy obiekt, wi�c zwi�kszamy licznik
}
// delegating constructors aby nie powtarzac kodu wiele razy mozemy oddelegowac zrobienie go do innego konstruktora.
// UWAGA w delegating constructor mozna uzywac tylko initialization list
klasy_podstawa::klasy_podstawa(int protect) // delegating constructor
	:klasy_podstawa{protect, -1, -1, NULL, 0}
{
	cout << "Delegating constructor; 1 argument" << endl;
}
klasy_podstawa::klasy_podstawa() // delegating constructor
	:klasy_podstawa(-1, -1, -1, NULL, 0)
{
	cout << "Delegating constructor; 0 argument" << endl;
}
klasy_podstawa::klasy_podstawa(const klasy_podstawa& source) // copy constructor
	:protect{source.protect}, priv{source.priv}, pub{source.pub}, len{source.len}
{
	if (source.len > 0)
	{
		this->tab = new int[len]; // WAZNE maja byc takie [] nawiasy nie takie () XD
		for (int i = 0; i < len; i++)
		{
			this->tab[i] = source.tab[i];
		}
	}
	else
	{
		this->tab = NULL;
	}
	cout << "copy constructor\n";
	count++; // tworzymy obiekt, wi�c zwi�kszamy licznik

	// jest to deep copy. Defoultowy copy constructor u�ywa shallow copy
	// chodzi o to, �e w przypadku shallow copy kopiujemy po warto�ci czyli jak mamy wska�nik 
	// to skopiowany obiekt b�dzie wskazywa� na to samo miejsce w pami�ci co orygina�
	// np jak przekazujemy do metody obiekt poprzez kopi� to po zako�czeniu dzia�ania metody
	// wo�any jest destruktor, kt�ry w takim przypadku zwolni pami�� na kt�r� wskazuje kopia
	// a �e kopia wskazuje na dok�adnie to samo miejsce co orygina� to tracimy dost�p w oryginale
	//
	// dlatego je�li u�ywamy wska�nik�w nale�y stworzy� copy constructor robi�cy deep copy
}
klasy_podstawa::~klasy_podstawa()
{
	if (tab == NULL)
	{
		delete[]tab;
	}
	count--; // niszczymy obiekt, wi�c zmniejszamy licznik
	cout << "Klasy_podstawa Destructor" << endl;
}
void klasy_podstawa::get_values() const
{
	cout << "Len: " << len << "\nPub: " << pub << endl;
	get_private(); // metody wo�ane w metodzie const te� musz� by� const
}
void klasy_podstawa::get_private()  const
{
	cout << "Priv: " << priv << "\nProtect: " << protect << endl;
}
void klasy_podstawa::set_values(int pub, int priv, int protect)
{
	this->protect = protect;
	this->priv = priv;
	this->pub = pub;
}
int klasy_podstawa::get_count() // statyczna metoda ma tylko dost�p do statycznych danych
{
	return count;
}
// jest jeszcze co� takiego jak move constructor, ale nie do ko�ca to ogarniam