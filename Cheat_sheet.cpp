// Cheat_sheet.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.

#include <iostream>
#include "Klasy_podstawa.h"
#include "Overloading.h"
#include "Account.h"
#include "Savings_Account.h"
#include "Printable.h"
#include "Exceptions.h"
#include "Template.h"
#include <memory> // biblioteka do smart pointers
#include <vector>
#include <iomanip> // manipulatory
#include <fstream> // pliki
#include <string>
#include <sstream> // string stream
#include <algorithm>
#include <numeric> // accumulate
#include <cctype> //toupper
#include <array>
#include <deque>
#include <list>
#include <forward_list>
#include <set>
#include <map>
#include <utility>
#include <stack>
#include <functional> // do przekazywania lambdy do funkcji

using namespace std;

void display_count_klasy_podstawa();
void custom_deleter(Account* ptr);
double calculate_exceptions(int kiolometers, int liters);
void func_a();
void func_b();
void func_c();
double calculate_exceptions2(int kiolometers, int liters);
void Square_Function(int x);
template<typename T>
void display(T container);
template<typename T>
void display_map(T map);
template<typename T>
void display_stack(stack<T, vector<T>> stack);
// dzięki template możemy mieć w miejscu T dowolny typ
// nie musimy pisać oddzielnych funkcji robiących to samo
// tyle, że z innymi typami
// zamiast "typename" można pisać też "class"
// to jest dokładnie to samo
// można oczywiście też wrzucić do tego napisane przez nas klasy
// tylko uwaga w tym wypadku muszą mieć przeciążąny operator >
template<typename T>
T max_func(T a, T b);

void filter_vector(const vector<int>& vec, function<bool(int)>func);
// function<*co zwraca*(*co przyjmuje*)>*nazwa*
// zamiast tego wyżej można użyć auto UWAGA dopiero od c++20
auto make_lambda()
{
    return []() {cout << "Ta lambde stworzyla funkcja. Dalej nie mam pojecia co robie\n"; };
}
// wychodzi na to że coś takiego nie może być pod mainem tylko musi być tutaj, nwm dlaczego


class B; // tak jak z funkcjami, mówisz programowi, że to jest a reszte piszesz na dole

class A
{
    shared_ptr<B> b_ptr;
public:
    void set_B(shared_ptr<B>& b)
    {
        b_ptr = b;
    }
    A()
    {
        cout << "A constructor\n";
    }
    ~A()
    {
        cout << "A destructor\n";
    }
};
class B
{
    weak_ptr<A> a_ptr; // gdyby nie weak_ptr doszłoby do wycieku pamięci bo wskaźniki nie mogłyby się usunąć 
    // bo wskazują na siebie na wzajem
public:
    void set_A(shared_ptr<A>& a)
    {
        a_ptr = a;
    }
    B()
    {
        cout << "B constructor\n";
    }
    ~B()
    {
        cout << "B destructor\n";
    }
};

struct Square_Functor // obiekt funkcyjny
{
    void operator()(int x)
    {
        cout << x * x << " ";
    }
};
template<typename T>
struct Displayer_Functor // obiekt funkcyjny
{
    void operator()(T x)
    {
        cout << x << " ";
    }
};
class Multiplier // obiekt funkcyjny
{
private:
    int num;
public:
    Multiplier(int num) :num{ num } {};
    int operator()(int n)const
    {
        return n * num;
    }
};

class Person
{
    friend ostream& operator<<(ostream& os, const Person& obj);
private:
    string name;
    int age;
public:
    Person(string name, int age) :name{ name }, age{ age }{};
    ~Person() = default;
    string get_name()const
    {
        return name;
    }
    int get_age()const
    {
        return age;
    }
    // to zwraca lambde
    // używamy this czyli bierzemy name i age przez referencje
    // działałoby tak samo z &
    // nawet z = brałoby przez referencje ale jest to wycofane w c++20
    // więc najlepiej użyć w tym przypadku this
    auto change_person()
    {
        return [this](string new_name, int new_age) {name = new_name; age = new_age; };
    }
};
ostream& operator<<(ostream& os, const Person& obj)
{
    os << "Name: " << obj.name << " Age: " << obj.age << endl;
    return os;
}

int main()
{
    //KLASY PODSTAWA
    cout << "---------------Klasy Podstawa---------------\n\n";

    int tab[5] = { 1,2,3,4,5 };
    klasy_podstawa test1(1, 2, 3, tab, 5);
    klasy_podstawa test2(4, 5);
    klasy_podstawa* test3 = new klasy_podstawa();
    klasy_podstawa test4(test1);

    display_count_klasy_podstawa();

    cout << test2.pub << endl;

    cout << test3->pub << endl;
    test1.pub = 5; // z poza klasy jest dostęp tylko do zmiennych publicznych. 
    //Do zmiennych private i protected można się dostać tylko przez metody
    test4.get_values();
    test4.set_values(21, 37, 6);
    test4.get_values();
    delete test3; // WAZNE bez tego delete obiekt test3 nie zostanie usuniety i dojdzie do wycieku pamieci 
    display_count_klasy_podstawa();

    // Operator Overloading
    cout << "---------------Operator Overloading---------------\n";

    int tab_overloading[] = { 1,2,3 };
    Overloading test1_overloading(5.5, true, tab_overloading, 6, 3);
    Overloading test2_overloading(4.5, false, tab_overloading, 8, 3);
    test1_overloading = test1_overloading + test2_overloading;
    test1_overloading++;
    test1_overloading++;
    ++test1_overloading;
    test1_overloading[1] = 5;
    cout << test1_overloading << endl;
    test1_overloading();
    test1_overloading.zmienna_bool = true;

    cout << (test2_overloading && test1_overloading) << endl;
    cout << (test2_overloading || test1_overloading) << endl;
    cout << (!test2_overloading) << endl;
    cout << "------------" << endl;
    cout << (test1_overloading < test2_overloading) << endl;
    cout << (test1_overloading > test2_overloading) << endl;
    cout << (test1_overloading == test2_overloading) << endl;
    
    // Inheritance
    cout << "---------------Inheritance---------------\n";
    Account account1(450, "Konto");
    Savings_Account savings_account1(5.0, 750, "Konto Oszczednosciowe");

    savings_account1.deposit(250);
    cout << account1 << savings_account1;
    savings_account1.withdraw(500);

    cout << endl << endl;
    Account* acc_ptr = new Savings_Account(2.0, 400, "Savings_ptr");
    acc_ptr->deposit(100);
    cout << *acc_ptr; // gdyby nie klasa Printable zostałby użyty przeciążony operator z klasy Account
    delete acc_ptr;
    cout << endl << endl;

    // gdyby w Account.h metody withdraw i deposit nie były virtual to w takim przypadku
    // zostały by użyte metody z klasy podstawowej, a nie z klasy pochodnej czyli tak zwany
    // static binding a nie dynamic polimorphism


    // Smart Pointers
    cout << "\n\n---------------Smart Pointers---------------\n\n";
    // tak se myśle, że do smart pointerów przydałby się chyba move constructor
    unique_ptr<int> ptr_int_1{ new int {100} }; // można tak
    unique_ptr<int> ptr_int_2 = make_unique<int>(200); // ale tak jest lepiej
    unique_ptr<int> ptr_int_3 = make_unique<int>(300);
    cout << *ptr_int_1 << endl;
    *ptr_int_1 += 100;
    cout << *ptr_int_1 << endl;

    // o wektorach będzie później
    // na razie to tak
    // vector<typ> nazwa
    vector<unique_ptr<int>> unq_vec;

    // .push_back jak sama nazwa wskazuje dodaje na koniec wektora
    // normalnie robi to przez kopie, ale że unique_ptr nie można kopiować
    // to przesuwa je w odpowiednie miejsce funkcją move
    unq_vec.push_back(move(ptr_int_1));
    unq_vec.push_back(move(ptr_int_2));
    unq_vec.push_back(move(ptr_int_3));

    cout << endl << endl;

    // auto to znaczy że program sam ma odgadnąć jakiego typu ma zmienną
    // .begin() i .end() zwraca iterator
    // iteratory działają trochę jak wskaźniki
    // więcej o nich później
    for (auto i = unq_vec.begin(); i != unq_vec.end(); i++)
    {
        cout << *(*i) << endl;
        // dwie * bo wartością wskaźnika jest adres, więc potrzeba drugiej * aby dostać się do tego co trzyma
    }
    cout << ptr_int_3 << endl; // teraz nasze wskaźniki wskazują na NULL 
    // bo wyżej przenieśliśmy własność z tych wskaźników na vector używając move()
    ptr_int_1 = move(*(unq_vec.begin())); // z powrotem przenieśliśmy własność z wektora na wskaźnik
    cout << *ptr_int_1 << endl;

    cout << endl << endl;

    unique_ptr<Account> account_ptr = make_unique<Savings_Account>(4.0, 100, "Savings smart ptr");
    cout << *account_ptr << endl;
    account_ptr->deposit(100);

    ptr_int_1.reset(); // ustawienie wskaźnika na NULL, pamięć na którą wskazywał zostaje zwolniona
    cout << ptr_int_1 << endl << endl;
    // jak zrobisz ptr_int_1. to wyświetlą się inne funkcje jakie można użyć


    shared_ptr<int> shr_ptr_1 = make_shared<int>(100);
    shared_ptr<int> shr_ptr_2{ shr_ptr_1 };
    shared_ptr<int> shr_ptr_3 = make_shared<int>(300);

    cout << shr_ptr_1.use_count() << endl; // .use_count() służy do kontrolowania ile wskaźników wskazuje na to samo
    cout << shr_ptr_2.use_count() << endl;
    shr_ptr_1.reset();
    cout << shr_ptr_1.use_count() << endl;
    cout << shr_ptr_2.use_count() << endl;

    shr_ptr_1 = make_shared<int>(100);
    *shr_ptr_2 += 100;
    cout << *shr_ptr_2 << endl;

    cout << endl << endl;

    cout << shr_ptr_1.use_count() << endl;
    cout << shr_ptr_2.use_count() << endl;
    cout << shr_ptr_3.use_count() << endl;

    vector<shared_ptr<int>> shr_vec;

    shr_vec.push_back(shr_ptr_1);
    shr_vec.push_back(shr_ptr_2);
    shr_vec.push_back(shr_ptr_3);

    cout << endl;

    cout << shr_ptr_1.use_count() << endl;
    cout << shr_ptr_2.use_count() << endl;
    cout << shr_ptr_3.use_count() << endl;

    cout << endl;

    for (auto i : shr_vec) // działa podobnie jak w pythonie
    {
        cout << *i << endl << i.use_count() << endl;
        // auto to żeby program sam się domyślił co to jest
        // pętla przechodzi po wszystkich elementach i je kopiuje do i
        // dlatego nie mogliśmy użyć tego przy smart pointer
        // można by użyć tam wtedy tylko trzebaby było dopisać & przed i że przez referencje
    }

    cout << endl;

    cout << shr_ptr_1.use_count() << endl;
    cout << shr_ptr_2.use_count() << endl;
    cout << shr_ptr_3.use_count() << endl;

    cout << endl << endl;

    // te klasy są do zaprezentowania weak_ptr, patrz na górze
    shared_ptr <A> a = make_shared<A>();
    shared_ptr <B> b = make_shared<B>();

    a->set_B(b);
    b->set_A(a);

    shared_ptr<Account> ptr_deleter_test{ new Savings_Account(1.0, 500, "Saving_ptr_deleter_test"), custom_deleter };
    // jeśli chcemy zapewnić custom deleter to nie możemy stworzyć wskaźnika przez make_shared
    // robimy tak jak w pierwszym sposobie i dopisujemy nazwe naszego custom deleter
    // zamiast przez funkcje można to zrobić przez lambda expression
    // o lambdzie będzie potem
    // wsm nwm po co to, w jakiś szczególnych przypadkach się to używa
    // ale dla porządku zrobiłem

    // smart pointers same się usuwają, więc nie trzeba robić delete

    // Exception Handling
    cout << "\n\n---------------Exception Handling---------------\n\n";
    int kilometers = 123;
    int liters = 0;

    // w try umieszczamy blok programu, który potencjalnie może spowodować błąd
    try
    {
        if (liters == 0)
        {
            throw 0;
            // throw wyrzuca błąd
            // jeśli wykona się linia z throw to nic po niej w bloku try nie zostanie wykonane
        }
        double result = (double)kilometers / liters; 
        cout << result << endl;
        // taka ciekawostka dzielenie przez 0 int wywali program
        // dzielenie double przez 0 zwraca inf (infinity)
        // dzielenie double 0 przez 0 zwraca nan (not a number)
        // oczywiście nic z tych rzeczy nie chcemy
    }
    catch (int& ex) // przez referencje bo to dobry zwyczaj, nazwa nie ma znaczenia
    {
        cerr << "Nie mozna dzielic przez 0\n"; 
        // cerr jest specjalnie do wypisywania błędów
        // wsm wypisuje na ekran jak zwykły cout
    }
    // catch służy do łapania wyjątków wyrzuconych przez throw
    // ogólnie jest to tylko prosty przykład do pokazania jak działa try throw i catch
    // normalnie robi się to inaczej
    
    try
    {
        double result2 = calculate_exceptions(kilometers, liters);
        cout << result2 << endl;
    }
    catch (int& ex)
    {
        cerr << "Nie mozna dzielic przez 0\n";
    }
    catch (string& ex)
    {
        cerr << ex << endl;
    }
    catch (...)
    {
        cerr << "Nieznany wyjatek\n";
        // jeśli żaden z powyższych catch nie złapie wyjątku to ten go przejmie
        // należy go umieszczać na końcu
    }
    try
    {
        func_a();
    }
    catch(...)
    {
        cout << "Visual\n";
    }
    // jak nie ma catch to program się zakończy
    // ale visual nie dopuszcza opcji nie pisania ani jednego catch więc jest tak
    
    try
    {
        double result2 = calculate_exceptions2(kilometers, liters);
        cout << result2 << endl;
    }
    catch (const DivideByZeroException& ex)
    {
        cerr << "Nie mozna dzielic przez 0\n";
    }
    catch (const NegativeValueException& ex)
    {
        cerr << "Ujemne wartosci" << endl;
    }
    catch (...)
    {
        cerr << "Nieznany wyjatek\n";
    }
    // właśnie tak powinno się robić wyjątki
    // const *czytelna nazwa klasy* & *jakaś nazwa*

    try
    {
        unique_ptr<Account> exception_test = make_unique<Account>(-10, "exception_test");
        cout << *exception_test << endl;
    }
    catch (const NegativeBalanceException& ex)
    {
        cerr << ex.what() << endl;
    }
    // Jeśli chodzi o wyjątki w klasach to:
    // NIE WOLNO robić wyjątków w destruktorze
    // w metodach robi się tak jak w normalnych funkcjach
    // a w konstruktorze jest przykład powyżej

    // I/O and Streams
    cout << "\n\n---------------I/O and Streams---------------\n\n";
    // Manipulators
    bool True = true;
    bool False = false;

    cout << boolalpha; 
    // ustawia wyświetlanie bool jako true i false a nie jako 1 i 0
    // UWAGA działa do końca programu
    cout << True << " " << False << endl;
    cout << noboolalpha;
    // można to przywrócić do stanu 1 i 0 używając tego powyżej
    cout << True << " " << False << endl;
    cout.setf(ios::boolalpha); // inny sposób
    cout << True << " " << False << endl;
    cout << True << " " << False << endl;
    //cout.setf(ios::noboolalpha); // powinno działać, ale nie działa nwm czemu
    cout << resetiosflags(ios::boolalpha); 
    // ustawia flagę boolalpha do defoultowej wartości czyli 1 i 0
    cout << True << " " << False << endl;

    cout << "\n\n";
    int num = 123;
    // wyświetlanie w innych systemach
    // jak widać to również działa do końca programu, więc trzeba zmienić z powrotem
    // bez showbase wyświeliłyby się po prostu liczby
    // a trudno powiedzieć czy 173 jest liczbą dec czy oct
    // uppercase jest po to aby litery z liczb wyświetlały się duże
    cout << showbase << uppercase;
    // można to też zrobić tak:
    // cout.setf(ios::showbase);
    // cout.setf(ios::uppercase);
    // cout.setf(ios::showpos);
    cout << dec << num << endl;
    cout << hex << num << endl;
    cout << oct << num << endl;
    cout << num << endl;
    cout << dec;
    cout << num << endl << endl;
    // showpos jest do wyświetlania + przy liczbach dodatnich
    cout << showpos;
    cout << num << endl;
    cout << num << endl;
    // noshowpos przywraca wyświetlanie liczb dodatnich bez +
    cout << noshowpos;
    cout << num << endl;
    cout << resetiosflags(ios::basefield);
    cout << resetiosflags(ios::showpos);
    cout << resetiosflags(ios::showbase);
    cout << resetiosflags(ios::uppercase);

    cout << "\n\n";

    double num_d = 1234.567;

    cout << num_d << endl;
    // defaultowo c++ wyświetla 6 liczb i stosuje zaokrąglenie
    num_d = 123456789.987654321;
    cout << num_d << endl;
    // jeśli nie jest w stanie wyświetlić danej liczby to stosuje notacje naukową
    cout << setprecision(9);
    cout << num_d << endl;
    // ustawiliśmy precyzję na 9
    // zauważ, że nadal zaokrągla
    cout << fixed;
    cout << num_d << endl;
    cout << setprecision(6);
    // fixed ustawia, że dokładność ma być liczona po przecinku
    cout << scientific << uppercase;
    cout << num_d << endl;
    cout << defaultfloat; // resetuje te wszystkie manipulatory
    // scientific ustawia notacje naukową
    // uppercase ustawia duże litery w tym wypadku E
    cout << showpoint; // dopisuje 0 jeśli nie wypełniamy całej precyzji
    cout << 123.45 << endl;
    cout << noshowpoint; // tego widocznie defaultfloat nie resetuje
    cout << 123.45 << endl;

    cout << "\n\n";

    num_d = 123.456;
    int ruler = 1234567890;
    string hello = "hello";

    cout << ruler << ruler << ruler << endl;
    cout << setw(10) << num_d << hello << endl;
    // setw działa tylko na następny element, czyli tylko na num_d
    cout << ruler << ruler << ruler << endl;
    cout << setw(10) << num_d << setw(10) << hello << endl;
    cout << ruler << ruler << ruler << endl;
    cout << setw(10) << left << num_d << hello << endl;
    // left działa na wszystkie elemenety, jest też odpowiednik right
    cout << ruler << ruler << ruler << endl;
    cout << setw(10) << setfill('-') << num_d << setw(10) << hello << endl;
    


    cout << "\n\n";
    // Reading from text file
    cout << setfill('-') << setw(30) << right << "\n";
    cout << setfill(' '); // ustawienie setfill na spacje

    // fstream to połączenie ifstream i ofstream
    // ifstream służy do czytania z pliku, ofstream do zapisywania do pliku
    // fstream in_file {"romeoandjuliet.txt", ios::in}; // tu ustawiamy, że czytamy, zapisywanie to out
    // jeśli chcemy w formie binarnej to robimy tak:
    // fstream in_file {"romeoandjuliet.txt", ios::in | ios::binary};
    // analogicznie robimy z ifstream i ofstream, ale nie trzeba pisać in lub out bo są już domyślnie
    // można jeszcze robić to tak:
    ifstream in_file;
    in_file.open("romeoandjuliet.txt"); // jak chcemy binarnie to po przecinku piszemy ios:binary
    string slowo1, slowo2, slowo3;
    string line;


    if (in_file.is_open())
    {
        cout << "Plik otwarty pomyslnie\n";
    }
    else
    {
        cout << "Nie udalo sie otworzyc pliku\n";
    }
    
    in_file >> slowo1 >> slowo2 >> slowo3; // jak z cin, tyle że z pliku
    cout << slowo1 << " " << slowo2 << " " << slowo3 << endl;
    // getline jest w bibliotece string
    getline(in_file, line);
    getline(in_file, line);
    getline(in_file, line); // te trzy wyżej to są same puste linie w naszym pliku
    getline(in_file, line); // dopiero tu jest tekst
    // zauważ, że zapamiętywane jest ostatnie odczytane miejsce i z tamtą zaczynamy czytać kolejne
    cout << line << endl;

    in_file.close(); // ZAWSZE trzeba zamykać plik

    in_file.open("responses.txt");
    if (!in_file) // tak też można sprawdzić czy plik jest otwarty
    {
        cerr << "Nie udalo sie otworzyc pliku\n";
        return 1;
    }
    while (!in_file.eof()) // do końca pliku, eof() zwraca prawdę jeśli dojdzie do końca pliku więc negacja kończy tą pętle
    {
        getline(in_file, line);
        cout << line << endl;
    }

    /*s
    // można też zrobić tak:
    // getline zwraca prawdę jeśli udało mu się odczytać, więc pętla się zakończy jak dojdziemy do końca pliku
    while (getline(in_file, line)) 
    {
        cout << line << endl;
    }
    */
    in_file.close();

    cout << "\n\n";

    char c;

    in_file.open("responses.txt");
    if (!in_file) // tak też można sprawdzić czy plik jest otwarty
    {
        cerr << "Nie udalo sie otworzyc pliku\n";
        return 1;
    }
    while (in_file.get(c)) // get() pobiera jeden znak (również znak nowej linii), jak się udało to zwraca to co getline
    {
        cout << c;
    }

    in_file.close();

    // Writing to a text file
    cout << "\n\n";
    cout << setfill('-') << setw(30) << right << "\n";
    cout << setfill(' '); // ustawienie setfill na spacje

    ofstream out_file;
    out_file.open("copy.txt");
    // jak chcemy sprecyzować w jakim trybie to dopisujemy po przecinku:
    // ios::ate dopisywanie, domyślnie ustawia na koniec pliku, ale możemy ustawić w dowolnym miejscu w pliku
    // ios::app dopisywanie na końcu pliku
    // ios::trunc nadpisywanie pliku (domyślne)

    in_file.open("inwokacja.txt");

    if (!in_file.is_open() || !out_file.is_open())
    {
        cerr << "Ktorys z plikow nie zostal otwarty\n";
        return 1;
    }

    while (getline(in_file, line))
    {
        out_file << line << endl; // jak z cout, tyle że do pliku
    }
    // można też po jednym znaku czytając get(c) i wpisując put(c)

    in_file.close();
    out_file.close();

    // String stream

    // ogólnie stringstreamy to takie stringi z których można czytać i zapisywać jak do plików
    // tak jak w plikach jest podział na istingstream i ostringstream, a stringstream to połączenie obu

    double total;
    string name;

    string info = "Jan 100 1234.5"; // zwykły string
    istringstream iss = (istringstream)info; // przypisanie wartości info to stringstreama

    iss >> name >> num >> total; // pobranie wartości z stringstreama i wpisanie ich do zmiennych
    cout << setw(10) << left << name << setw(5) << num << setw(10) << total << endl;

    cout << "\n---------------------------------------" << endl;

    ostringstream oss;
    oss << setw(10) << left << name << setw(5) << num << setw(10) << total << endl;
    cout << oss.str() << endl; // .str służy do wypisania

    // to na dole zakomentowałem żeby nie musieć wpisywać czegoś za każdym odpaleniem programu
    /*
    cout << "\n--- Data validation ------------------------------------" << endl;

    int value;
    string entry;
    bool done = false;
    do 
    {
        cout << "Please enter an integer: ";
        cin >> entry;
        istringstream validator = (istringstream)entry;
        if (validator >> value)
        {
            done = true;
        }
        else
        {
            cout << "Sorry, that's not an integer" << endl;
        }           

        // usuwa to co zostało
        // np użytkownik poda 10 mam kota
        // to value przyjmnie 10 a w środku zostanie jeszcze "mam kota"
        cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
    } while (!done);

    cout << "You entered the integer: " << value << endl;
    */

    cout << "\n\n---------------Standard Template Library---------------\n\n";

    // template
    cout << "--template--\n";
    cout << max_func<int>(2, 3) << endl;
    cout << max_func<char>('b', 'c') << endl;
    // jak widać wywołujemy funkcje tak jak zwykłą tylko dodajemy po nazwie <typ>

    Item<int> item1("item1", 5);
    cout << item1.get_name() << " " << item1.get_value() << endl;

    Item<Item<double>> item2("item2", { "subitem", 2.2 }); // typem może też być klasa, w tym wypadku ta sama
    cout << item2.get_name() << " " << item2.get_value().get_name() << " " << item2.get_value().get_value() << endl;

    my_array<string, 5> arr;
    arr.fill("X");
    cout << arr;
    arr[0] = "Ala";
    arr[1] = "ma";
    arr[2] = "kota";
    cout << arr;

    cout << "\n\n--Iterators--" <<endl << endl;
    vector<int> v = { 4, 2, 5, 1, 3 };

    display(v);

    sort(v.begin(), v.end());
    // sortuje elementy

    display(v);

    reverse(v.begin(), v.end());
    // odwrotna kolejność
    display(v);

    int sum = accumulate(v.begin(), v.end(), 0);
    // accumulate dodaje do siebie elementy z podanego zakresu, ostatni parametr to od czego zacząć sumować
    cout << sum << endl << endl;

    vector<int>::iterator it_v; 
    // tak się robi iteratory
    // containe<typ>::iterator nazwa
    // ale łatwiej jest robić przez auto tak jak w przykładzie ze smartpointerami np:
    // auto nazwa = nazwa_container.begin()
    // UWAGA .end() to element PO ostatnim elemencie
    it_v = v.begin();

    cout << *it_v << endl;
    // iteratory działają podobnie do wskaźników, ale nimi nie są

    it_v++;
    cout << *it_v << endl;
    it_v += 2;
    cout << *it_v << endl;
    it_v--;
    cout << *it_v << endl;
    it_v -= 2;
    cout << *it_v << endl << endl;
    
    auto it_v2 = v.cbegin();
    // nie można tak zrobić ponieważ it_v2 to const iterator
    // *it_v2 = 5;
    for (; it_v2 != v.end(); it_v2++)
    {
        cout << *it_v2 << " ";
    }
    cout << endl;

    auto it_v3 = v.rbegin();
    // jest to reverse iterator
    // jest też const reverse iterator
    // .crbegin() .crend()
    for (; it_v3 != v.rend(); it_v3++)
    {
        cout << *it_v3 << " ";
        // zauważ, że mimo że iterujemy od tyłu dalej it_v3++ idzemy do przodu jak chcemy
        // nie musimy zmieniać na --
    }
    cout << endl;
    // iteratory działają tak samo na innych "kontenerach"
    

    cout << "Algorytmy\n\n";
    // algorytmy
    // find zwraca iterator do pierwszego znalezionego elementu
    // lub jeśli nie znajdzie to do .end()
    // find musi mieć możliwość korzystaniaz operatora ==
    // więc jeśli chcemy szukać w obiektach naszej klasy musimy zapewnić
    // przeciążąny operator ==
    auto location = find(v.begin(), v.end(), 3);

    // algorytm for_each
    // używa "funkcji" na każdym elemencie w sekwencji iterowania
    // "funkcja" ma być zapewniona poprzez:
    // funktor (obiekt funkcyjny)
    // wskaźnik na funkcje
    // lambda

    Square_Functor square;

    for_each(v.begin(), v.end(), square);
    cout << endl;
    // begin(v), end(v) to jest to samo co v.begin(), v.end()
    for_each(begin(v), end(v), Square_Function);
    cout << endl;
    for_each(v.begin(), v.end(), [](int x) {cout << x * x << " "; }); // to po przecinku to lambda, więcej o lambdzie potem
    cout << endl << endl;

    v.push_back(1);
    v.push_back(2);
    v.push_back(1);

    // jak sama nazwa wskazuje count zlicza ilość wystąpień
    int count_v = count(v.begin(), v.end(), 1);
    cout << count_v << endl << endl;

    // count_if jak sama nazwa wskazuje zlicza elementy spełnijące dany warunek
    count_v = count_if(v.begin(), v.end(), [](int x) {return x % 2 == 0; }); // to po przecinku na końcu to jest lambda
    cout << count_v << endl << endl;

    display(v);

    // jak sama nazwa wskazuje replace zamienia jeden element na drugi
    replace(v.begin(), v.end(), 1, 6);
    display(v);
    cout << endl;

    // all_of zwraca prawdę, jeśli wszyskie elementy spełniają dany warunek
    if (all_of(v.begin(), v.end(), [](int x) {return x < 10; }))
    {
        cout << "Wszystkie elementy sa mniejsze od 10\n";
    }
    else
    {
        cout << "Nie wszystkie elementy sa mniejsze od 10\n";
    }

    // wsm widać co robi
    // to drugie begin jest do tego gdzie zacząć wpisywać przetransformowane
    string transform_test = "Nie mam pojecia co robie";
    cout << "\nPrzed transform: " << transform_test << endl;
    transform(transform_test.begin(), transform_test.end(), transform_test.begin(), ::toupper);
    cout << "Po transform: " << transform_test << endl << endl;

    // array
    // lepiej jest używać tych tablic
    // używaj zwykłych tylko jeśli to konieczne
    array<int, 5> arr2 = { 1, 2, 3, 4, 5 };
    array<int, 5> arr3 = { 10, 20, 30, 40, 50 };
    
    cout << arr2.size() << endl;
    cout << arr2.at(0) << endl;// robi to samo co arr2[0], ale bezpieczniej
    cout << arr2[1] << endl;
    cout << arr2.front() << endl;
    cout << arr2.back() << endl << endl;

    cout << arr2.empty() << endl; // czy pusta
    cout << arr2.max_size() << endl << endl;
    
    arr2.swap(arr3); // zamiana
    cout << arr2.at(0) << endl;
    cout << arr3.at(0) << endl << endl;

    int* data = arr2.data(); // adres

    cout << *min_element(arr2.begin(), arr2.end()) << endl; // * bo zwraca iterator
    cout << *max_element(arr2.begin(), arr2.end()) << endl;

    // vector
    cout << "\n--Vector--\n\n";
    vector<int> vctr = { 1, 2, 3, 4, 5 };
    vector<int> vctr2{ 10, 20, 30, 40, 50 };
    // vector<int> vctr(10, 100); // stworzy vector który ma 10 liczb 100 czyli wygląda tak:
    // [ 100, 100, 100, 100, 100, 100, 100, 100, 100, 100 ]
    cout << "Size: " << vctr.size() << endl;
    cout << "Capacity: " << vctr.capacity() << endl;
    vctr.push_back(1);
    cout << "Size: " << vctr.size() << endl;
    cout << "Capacity: " << vctr.capacity() << endl;
    vctr.pop_back(); // usuwa element z końca
    cout << "Size: " << vctr.size() << endl;
    cout << "Capacity: " << vctr.capacity() << endl;
    // jak wrzucamy coś nowego do wektora to zostaje alokowana nowa pamięć
    // zazwyczaj więcej niż potrzeba
    // po jakimś czasie capacity może być absurdalnie większe niż ilość
    // elementów w wektorze
    // dla tego jest specjalna funkcja shrink_to_fit()
    // która dopasowuje capacity do size
    vctr.shrink_to_fit();
    cout << "Po shrink_to_fit\n";
    cout << "Size: " << vctr.size() << endl;
    cout << "Capacity: " << vctr.capacity() << endl;
    // jest też funkcja reserve(), która rezerwuje podaną ilość miejsca
    // capacity nie zwiększy się wtedy, aż do wypełnienia całego zarezerwowanego miejsca


    // vctr.emplace();
    // emplace przydaje się do obiektów
    // tworzy od razu na końcu vectora nowy obiekt
    // a nie kopiuje
    // .swap() przy vectorach musi być ten sam typ, ale nie musi być ta sama wielkość

    // można również wpisywać wartości w dowolne miejsce wektora
    auto it_vctr = find(vctr.begin(), vctr.end(), 3);
    vctr.insert(it_vctr, 11);
    display(vctr);
    // można wpisywać w dowolone miejszcze cały wektor
    it_vctr = find(vctr.begin(), vctr.end(), 4);
    vctr.insert(it_vctr, vctr2.begin(), vctr2.end());
    display(vctr);
    // back_inserter wpakowałby wszystko na koniec

    // erase usuwa konkretny zakres elementów z wektora
    // clear wyczyściłby cały wektor
    vctr.erase(vctr.begin() + 2, vctr.begin() + 9);
    display(vctr);

    cout << "\n--Deque--\n\n";
    // deque
    // deque działa podobnie jak lista dwukierunkowa
    // łatwo coś dodać/zdjąć z przodu i z tyłu, ale trudno ze środka

    deque<int> deq;
    deq = { 1, 2, 3 };

    display(deq);
    deq.push_back(4);
    deq.push_front(5);
    deq.push_front(6);
    display(deq);

    cout << "\n--List--\n\n";
    // lista dwukierunkowa

    list<int> l = { 1, 2, 3, 4, 5 };
    auto l_it = find(l.begin(), l.end(), 3);
    l.insert(l_it, 10);
    display(l);
    l.erase(l_it);
    display(l);
    l.resize(2);
    display(l);
    l.resize(5);
    display(l);

    cout << "\n--Forward_List--\n\n";
    // lista jednokierunkowa

    forward_list<int> fl = { 1, 2, 3, 4, 5 };
    auto fl_it = find(fl.begin(), fl.end(), 3);
    display(fl);
    fl.insert_after(fl_it, 10);
    display(fl);
    fl.erase_after(fl_it);
    display(fl);
    fl.resize(2);
    display(fl);
    fl.resize(5);
    display(fl);

    cout << "\n--Set--\n\n";
    // Set

    set<int> s = { 4, 1, 2, 1, 5, 3, 3 };
    display(s);
    // set nie ma duplikatów i jest posortowany
    
    // nie ma front i back
    // jak chcemy dodać element do set to używamy insert
    s.insert(7);
    display(s);

    // insert w przypadku set zwraca oobiekt "pair"
    // jest to specjalny obiekt mający dwa elementy
    // first - w przypadku set jest tam przypisany iterator do wstawionego obiektu
    // second - w przypadku set jest tam przypisany bool informujący o powodzeniu insert
    // można używać normalnie do czego się chce obiektu pair
    // jest w bibliotece <utility>
    auto set_insertion = s.insert(6);
    display(s);

    cout << endl << *set_insertion.first << endl;
    cout << set_insertion.second << endl;

    cout << "\n--Map--\n\n";
    // Map
    // mapa jest podobna do słownika z pythona
    // elementy są posortowane przez klucz
    // nie może być zdublikowanych kluczy

    map<string, int> m
    {
        {"Jan", 20},
        {"Anna", 27},
        {"Julia", 16},
        {"Adam", 36}
    };
    display_map(m);
    pair<string, int> p1{ "Maciej", 44 };
    m.insert(p1);
    m.insert(make_pair("Patrycja", 36));
    m["Pawel"] = 9;
    display_map(m);
    m["Pawel"] = 59;
    display_map(m);

    cout << "\n--Stack--\n\n";
    // Stack
    // stos podstawowo działa na deque
    // możemy mu kazać działać na innym kontenerze tak jak w przykładzie
    stack<int, vector<int>> stos;

    stos.push(1);
    stos.push(2);
    stos.push(3);
    stos.push(4);
    
    display_stack(stos);
    stos.pop();
    display_stack(stos);
    stos.top() += 10;
    display_stack(stos);

    // jest też kolejka i kolejka priorytetowa
    // wiadomo jak działa kolejka, first in first out
    // metoda posługiwania się nią jest podobna do stosu
    // więc nie będę tego już pisał
    // jest w bibliotece <queue>
    // kolejka priorytetowa to tak co na górze jest największy element
    // ogólnie wszystkie elemenety kolejki priorytetowej są posortowane
    // działa podstawowo na vector
    // też jest w bibliotece <queue>

    // Lambda
    cout << "\n\n---------------Lambda---------------\n\n";

    Square_Functor sqr;
    Displayer_Functor<int> disp;
    Multiplier by_10(10);

    vector<int> vec_lamb = { 1, 2, 3, 4, 5 };


    // przy użyciu obiektów funkcyjnych
    cout << "Przy uzyciu obiektow funkcyjnych\n";
    for_each(vec_lamb.begin(), vec_lamb.end(), sqr);
    cout << endl;
    for_each(vec_lamb.begin(), vec_lamb.end(), disp);
    cout << endl;
    for_each(vec_lamb.begin(), vec_lamb.end(), Displayer_Functor<int>());
    cout << endl;
    transform(vec_lamb.begin(), vec_lamb.end(), vec_lamb.begin(), by_10);
    for_each(vec_lamb.begin(), vec_lamb.end(), disp);
    cout << endl << endl << "Przy uzyciu lambdy\n";

    vec_lamb = { 1, 2, 3, 4, 5 };
    // przy użyciu lambdy
    for_each(vec_lamb.begin(), vec_lamb.end(), [](int x) {cout << x * x << " "; });
    cout << endl;
    for_each(vec_lamb.begin(), vec_lamb.end(), [](int x) {cout << x << " "; });
    transform(vec_lamb.begin(), vec_lamb.end(), vec_lamb.begin(), [](int x) {return x * 10; });
    cout << endl;
    for_each(vec_lamb.begin(), vec_lamb.end(), [](int x) {cout << x << " "; });
    cout << endl << endl;

    auto lab_dis = [](auto x) {cout << x << " "; }; 
    // jeśli chcemy aby lambda była uniwersalna i przyjmowała wszystkie typy
    // to używamy "auto" aby program sam się domyślił
    lab_dis(6);
    lab_dis(21.3);
    lab_dis("Kot");
    cout << endl << endl;

    auto lab_bp = [](auto& score, int bonus_points)
    {
        score += bonus_points;
    };
    int score_test1 = 89;
    double score_test2 = 65.21;
    lab_bp(score_test1, 3);
    lab_bp(score_test2, 3);

    lab_dis(score_test1);
    cout << endl;
    lab_dis(score_test2);
    cout << endl << endl;

    vec_lamb = { 1, 2, 3, 4, 5 };

    filter_vector(vec_lamb, [](int x) {return x % 2; });
    filter_vector(vec_lamb, [](int x) {return !(x % 2); });
    filter_vector(vec_lamb, [](int x) {return x > 3; });

    auto lamb_make = make_lambda();
    lamb_make();
    cout << endl;

    vector<Person> person_vec = { {"Karolina", 25}, {"Adam", 35}, {"Mateusz", 18} };

    display(person_vec);

    sort(person_vec.begin(), person_vec.end(), [](const Person& p1, const Person& p2) {return p1.get_name() < p2.get_name(); });
    // nasz obiekt person nie ma zapewnionego przeciążonego operatora <
    // możemy użyć lambdy do sortowania w tym wypadku po imionach
    display(person_vec);
    sort(person_vec.begin(), person_vec.end(), [](const Person& p1, const Person& p2) {return p1.get_age() < p2.get_age(); });
    // lub w tym wypadku po wieku
    display(person_vec);
    cout << endl;

    // to wyżej to były stateless lambda expressions
    // teraz będą statefull lambda expressions
    // czyli takie, które w [] przyjmują które zmienne z w tym wypadku maina przyjąć
    // można to zrobić by value lub by reference
    // jeśli mamy ich dużo i np jedną z nich chcemy inaczej (np. wszystkie oprócz jednej przez wartość)
    // to w [] wpiujemy
    // "=" wszystkie by value
    // "&" wszystkie by reference
    // "this"  zmienne składowe bierzącego obiektu w którym jest lambda przez referencje
    //  jeśli chcemy kilka szczególnych inaczej to robimy tak:
    // [=, &x, &y] oznacza to, że wszystkie zmienne w main będą wziętę przez kopię, a zmienne x oraz y przez referencje
    // jeśli chcemy te zmienne zmieniać to musimy dopisać mutable po () np:
    // [=, &x, &y] () mutable {*nasz kod*};

    int state_lab_var1 = 5;
    int state_lab_var2 = 6;

    auto state_lab = [state_lab_var1, &state_lab_var2](int x)mutable
    {
        state_lab_var1 += x;
        state_lab_var2 += x;
        cout << "state_lab_var1: " << state_lab_var1 << " state_lab_var2: " << state_lab_var2 << endl;
    };
    state_lab(10);
    cout << "state_lab_var1: " << state_lab_var1 << " state_lab_var2: " << state_lab_var2 << endl;

    Person osoba("Adam", 20);

    cout << endl << osoba;
    auto person_lambda = osoba.change_person();
    person_lambda("Alicja", 18);
    cout << osoba << endl;

    // koniec
    cout << "\n\n---------------Wszystkie destruktory---------------\n\n";
}
void display_count_klasy_podstawa() 
{
    cout << "Count: " << klasy_podstawa::get_count() << endl;
}
void custom_deleter(Account* ptr)
{
    cout << "Custom deleter for: " << ptr->name << endl;
    delete ptr;
}
double calculate_exceptions(int kiolometers, int liters)
{
    if (liters == 0)
    {
        throw 0;
    }
    if (kiolometers < 0 || liters < 0)
    {
        throw (string)"Ujemne wartosci";
    }
    return (double)kiolometers / liters;
}
void func_a()
{
    cout << "Starting function a\n";
    func_b();
    cout << "Ending function a\n";
}
void func_b()
{
    cout << "Starting function b\n";
    try
    {
        func_c();
    }
    catch (int& ex)
    {
        cout << "Caught error int func_b\n";
    }
    cout << "Ending function b\n";
}
void func_c()
{
    cout << "Starting function c\n";
    throw 100;
    cout << "Ending function c\n";
}
double calculate_exceptions2(int kiolometers, int liters)
{
    if (liters == 0)
    {
        throw DivideByZeroException();
    }
    if (kiolometers < 0 || liters < 0)
    {
        throw NegativeValueException();
    }
    return (double)kiolometers / liters;
}
// zauważ że template piszemy też tu, jest to tak jakby część funkcji
template<typename T>
T max_func(T a, T b)
{
    return (a > b) ? a : b;
    // to działa jak if else
    // jeśli a > b to zwróć a, w przeciwnym wypadku b
}
void Square_Function(int x)
{
    cout << x * x << " ";
}
template<typename T>
void display(T container)
{
    cout << "[ ";
    for (const auto& i : container)
    {
        cout << i << " ";
    }
    cout << "]\n";
}
template<typename T>
void display_map(T map)
{
    cout << "Mapa:\n{\n";
    for (const auto& element : map)
    {
        cout << "\t[ " << element.first << ": " << element.second << " ]\n";
    }
    cout << "}\n";
}
template<typename T>
void display_stack(stack<T, vector<T>> stack)
{
    cout << "Top [ ";
    while (!stack.empty())
    {
        T value = stack.top();
        stack.pop();
        cout << value << " ";
    }
    cout << " ] Bottom\n";
}
void filter_vector(const vector<int>& vec, function<bool(int)>func)
{
    cout << "[ ";
    for (int i : vec)
    {
        if (func(i))
        {
            cout << i << " ";
        }
    }
    cout << "]\n";
}