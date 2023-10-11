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
	count++; // tworzymy obiekt, wiêc zwiêkszamy licznik
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
	count++; // tworzymy obiekt, wiêc zwiêkszamy licznik
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
	count++; // tworzymy obiekt, wiêc zwiêkszamy licznik

	// jest to deep copy. Defoultowy copy constructor u¿ywa shallow copy
	// chodzi o to, ¿e w przypadku shallow copy kopiujemy po wartoœci czyli jak mamy wskaŸnik 
	// to skopiowany obiekt bêdzie wskazywa³ na to samo miejsce w pamiêci co orygina³
	// np jak przekazujemy do metody obiekt poprzez kopiê to po zakoñczeniu dzia³ania metody
	// wo³any jest destruktor, który w takim przypadku zwolni pamiêæ na któr¹ wskazuje kopia
	// a ¿e kopia wskazuje na dok³adnie to samo miejsce co orygina³ to tracimy dostêp w oryginale
	//
	// dlatego jeœli u¿ywamy wskaŸników nale¿y stworzyæ copy constructor robi¹cy deep copy
}
klasy_podstawa::~klasy_podstawa()
{
	if (tab == NULL)
	{
		delete[]tab;
	}
	count--; // niszczymy obiekt, wiêc zmniejszamy licznik
	cout << "Klasy_podstawa Destructor" << endl;
}
void klasy_podstawa::get_values() const
{
	cout << "Len: " << len << "\nPub: " << pub << endl;
	get_private(); // metody wo³ane w metodzie const te¿ musz¹ byæ const
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
int klasy_podstawa::get_count() // statyczna metoda ma tylko dostêp do statycznych danych
{
	return count;
}
// jest jeszcze coœ takiego jak move constructor, ale nie do koñca to ogarniam