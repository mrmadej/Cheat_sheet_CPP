#pragma once
#include <iostream>

using namespace std;

class klasy_podstawa
{
	//jeœli nie zdefiniujesz czy coœ jest private, public czy protected to z automatu jest private
	//protected dzia³a jak private. Dopiero w dziedziczeniu jest ró¿nica
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
	
	//constructor z regu³y powinien byæ public. Jest jakaœ tam sytuacja co jest private, ale nie ogarniam tego za bardzo
	klasy_podstawa(); // delegating constructor
	klasy_podstawa(int protect); // delegating constructor
	klasy_podstawa(int protect, int pirv); //constructor; initialization list
	klasy_podstawa(int protect, int priv, int pub, int tab[], int len); // counstructor; nazwy mog¹ byæ dowolne
	// mo¿na u¿yæ te¿ defoultowych wartoœci zamiast kilku kontruktorów. Wtedy piszesz:
	// klasy_podstawa(int protect = -1, int priv = -1, int pub = -1);
	klasy_podstawa(const klasy_podstawa& source); // copy constructor. WAZNE musi byc przez referencje & 
	// bo inaczej robiona by³aby kopia czyli wo³ano by caly czas copy constructor bez koñca
	// const po to ¿eby nic nie zmieniæ w Ÿródle

	~klasy_podstawa(); //destructor w zasadzie potrzebny tylko jak robisz coœ z new czy coœ otwierasz otwierasz, normalnie wystarczy defoultowy 

	void get_values() const; // const po to aby zagwarantowaæ, ¿e nie zmieniamy wartoœci t¹ metod¹, aby móg³ jej u¿yæ obiekt const
	void set_values(int pub, int priv, int protect);
	static int get_count();
};