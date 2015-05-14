#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool czy_palindrom (string x) {
	return false;
}

bool podpunktC (string x) {
	for (int i = 1; i < x.size(); ++i) {
		if (x[i-1] + x[i] == 220) {
			return true;
		}
	}
	return false;
}

int main () {
        ifstream dane;
        ofstream odpowiedza, odpowiedzb, odpowiedzc;
        int dlugosc_parzysta = 0, dlugosc_nieparzysta = 0;
        string a;
	/////////
	dane.open("hasla.txt"); // otwieramy plik z danymi
        odpowiedza.open("wynik4a.txt"); // otwieramy plik wyjsciowy
        odpowiedzb.open("wynik4b.txt"); // otwieramy plik wyjsciowy
        odpowiedzc.open("wynik4c.txt"); // otwieramy plik wyjsciowy
	for (int i = 0; i < 200; ++i) {
		dane >> a;
		// podpunkt a
		if (a.size() % 2 == 0)
			++dlugosc_parzysta;
		else
			++dlugosc_nieparzysta;
		// podpunkt b
		if (czy_palindrom(a))
			odpowiedzb << a << endl;
		// podpunkt c
		if (podpunktC(a))
			odpowiedzc << a << endl;
	}
	odpowiedza << "parzyste: " << dlugosc_parzysta << endl << "nieparzyste: " << dlugosc_nieparzysta << endl;
        // zamykamy pliki
        odpowiedza.close();
        odpowiedzb.close();
        odpowiedzc.close();
        dane.close();
        // koniec
        return 0;
}
