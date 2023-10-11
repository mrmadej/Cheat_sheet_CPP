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
	// Ogólnie to pod³¹czamy jakby nasz wyj¹tek pod wyj¹tki wbudowane w c++
	// dzidziczymy publicznie z klasy exception (hierarchia tej klasy jest w Exception.jpg)
	// kontstruktor i destruktor = default to znaczy ¿e bierzemy defaultowy
	// noexcept znaczy, ¿e nie wolno wywo³ywaæ wyj¹tków z tych rzeczy

	// disclaimer
	// mo¿na to zrobiæ tak jak dwie klasy powy¿ej w poprzednich przyk³adach
	// to nie jest jakaœ zasada, ¿e tak siê robi przy konstruktorach
	// po prostu chcia³em pokazaæ ten sposób
};

// te klasy powy¿ej s¹ tylko po to ¿eby wyj¹tki by³y czytelniejsze
// taki jest zwyczaj