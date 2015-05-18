#include <fstream>
#include <string>
using namespace std;

int main () {
	ifstream dane;
	ofstream odpowiedz;
	string a;
	int dlugosc;
	bool czy_palindrom;
	//////////
	dane.open("dane.txt"); // otwieramy plik z danymi
	odpowiedz.open("palindromy.txt"); // otwieramy plik wyjsciowy
	for (int i = 0; i < 1000; ++i) {
		dane >> a; // wczytujemy
		dlugosc = a.size() - 1; // bo potrzebujemy do tablicy [0 - (n-1)]
		czy_palindrom = true; // zakladamy, ze jest
		for (int k = 0; k <= a.size()/2; ++k) { // petla przez wieksze pol (gdy nieparzysta dlugosc)
			if (a[k] != a[dlugosc-k]) { // jesli znaki sa rozne
				czy_palindrom = false; // nie jest palindomem
				break; // nie potrzebujemy sprawdzac dalej
			}
		}
		if (czy_palindrom)
			odpowiedz << a << endl;
	}
	// zamykamy pliki
	odpowiedz.close();
	dane.close();
	// koniec
	return 0;
}
