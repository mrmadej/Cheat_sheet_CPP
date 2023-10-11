#pragma once
class NegativeValueException
{
};

class DivideByZeroException
{
};

class NegativeBalanceException: public exception
{
public:
	NegativeBalanceException() noexcept = default;
	~NegativeBalanceException() = default;
	virtual const char* what()const noexcept
	{
		return "Illegal balance exception";
	}
	// Og�lnie to pod��czamy jakby nasz wyj�tek pod wyj�tki wbudowane w c++
	// dzidziczymy publicznie z klasy exception (hierarchia tej klasy jest w Exception.jpg)
	// kontstruktor i destruktor = default to znaczy �e bierzemy defaultowy
	// noexcept znaczy, �e nie wolno wywo�ywa� wyj�tk�w z tych rzeczy

	// disclaimer
	// mo�na to zrobi� tak jak dwie klasy powy�ej w poprzednich przyk�adach
	// to nie jest jaka� zasada, �e tak si� robi przy konstruktorach
	// po prostu chcia�em pokaza� ten spos�b
};

// te klasy powy�ej s� tylko po to �eby wyj�tki by�y czytelniejsze
// taki jest zwyczaj