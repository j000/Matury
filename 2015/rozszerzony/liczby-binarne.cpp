#include <fstream>
#include <string>
using namespace std;

int sprawdzA (string x) {
	// zakladamy, ze zadna liczba nie zaczyna sie zerami, np. "000010"
	int zera = 0, jedynki = 0;
	// proste zliczanie wystarczy
	for (int i = 0; i < x.size(); ++i) {
		if (x[i] == '0')
			++zera;
		else if (x[i] == '1')
			++jedynki;
	}
	if (zera > jedynki) // jesli ma wiecej zer niz jedynek
		return 1; // to zliczamy
	return 0;
}

void sprawdzB (string x, int& podzielne2, int& podzielne8) {
	int dlugosc = x.size();
	if (dlugosc >= 2 // odpowiednia dlugosc
			&& x[dlugosc-1] == '0') // i ostatnia cyfra to 0 (binarnie 2 to 10)
		++podzielne2;
	if (dlugosc >= 4 // odpowiednia dlugosc 
			&& x[dlugosc-1] == '0'
			&& x[dlugosc-2] == '0'
			&& x[dlugosc-3] == '0') // i ostatnie 3 cyfry to 000 (binarnie 8 to 1000)
		++podzielne8;
}

void sprawdzC (string liczba, int wiersz, string& min_liczba, int& min_wiersz, string& max_liczba, int& max_wiersz) {
	// proste porownanie NIE wystarczy
	// "100" > "10"
	// "101" > "100"
	// "10" < "101"
	// ale "11" > "101"
	//if (liczba < min_liczba) {
	if (liczba.length() < min_liczba.length() || (liczba.length() == min_liczba.length() && liczba < min_liczba)) {
		min_liczba = liczba;
		min_wiersz = wiersz;
	//} else if (liczba > max_liczba) {
	} else if (liczba.length() > max_liczba.length() || (liczba.length() == max_liczba.length() && liczba > max_liczba)) {
		max_liczba = liczba;
		max_wiersz = wiersz;
	}
}

int main () {
	ifstream dane;
	ofstream odpowiedz;
	int podpunkta = 0, podpunktb2 = 0, podpunktb8 = 0;
	int wiersz_min = 0, wiersz_max = 0;
	string liczba_min = "1000000000000", liczba_max = "1"; //ustawiamy na wieksza/mniejsza niz jedna z pierwszych liczb w danych (wiemy jakie sa dane, sprawdzamy)
	string a;
	//////////
	dane.open("liczby.txt"); // otwieramy plik z danymi
	odpowiedz.open("wynik4.txt"); // otwieramy plik wyjsciowy
	for (int i = 0; i < 1000; ++i) {
		dane >> a;
		podpunkta += sprawdzA(a);
		sprawdzB(a, podpunktb2, podpunktb8);
		sprawdzC(a, i, liczba_min, wiersz_min, liczba_max, wiersz_max); 
	}
	// wypisujemy odpowiedzi
	odpowiedz << "A: " << podpunkta << endl;
	odpowiedz << "B: podzielne przez 2: " << podpunktb2 << " podzielne przez 8: " << podpunktb8 << endl;
	odpowiedz << "C: najwieksza: " << wiersz_max << " najmniejsza: " << wiersz_min << endl;
	// zamykamy pliki
	odpowiedz.close();
	dane.close();
	// koniec
	return 0;
}
