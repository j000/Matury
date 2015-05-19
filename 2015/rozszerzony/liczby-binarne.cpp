#include <fstream>
#include <string>
using namespace std;

int sprawdzA (string x) {
	int zera = 0, jedynki = 0;
	for (int i = 0; i < x.size(); ++i) {
		if (x[i] == '0')
			++zera;
		else if (x[i] == '1')
			++jedynki;
	}
	if (zera > jedynki)
		return 1;
	return 0;
}

void sprawdzB (string x, int& podzielne2, int& podzielne8) {
	int dlugosc = x.size();
	if (dlugosc >= 2 // odpowiednia dlugosc
			&& x[dlugosc-1] == '0') // i ostatnia cyfra to 0
		++podzielne2;
	if (dlugosc >= 4 // odpowiednia dlugosc 
			&& x[dlugosc-1] == '0'
			&& x[dlugosc-2] == '0'
			&& x[dlugosc-3] == '0') // i ostatnie 3 cyfry to 000
		++podzielne8;
}

void sprawdzC (string x, int wiersz, string& min_liczba, int& min_wiersz, string& max_liczba, int& max_wiersz) {
	if (x < min_liczba) {
		min_liczba = x;
		min_wiersz = wiersz;
	}
	if (x > max_liczba) {
		max_liczba = x;
		max_wiersz = wiersz;
	}
}

int main () {
	ifstream dane;
	ofstream odpowiedz;
	int podpunkta = 0, podpunktb1 = 0, podpunktb2 = 0;
	int min_wiersz = 0, max_wiersz = 0;
	string min_liczba = "1000000000000", max_liczba = "1"; //ustawiamy na wieksza/mniejsza niz jedna z pierwszych liczb w danych
	string a;
	//////////
	dane.open("liczby.txt"); // otwieramy plik z danymi
	odpowiedz.open("wynik4.txt"); // otwieramy plik wyjsciowy
	for (int i = 0; i < 1000; ++i) {
		dane >> a;
		podpunkta += sprawdzA(a);
		sprawdzB(a, podpunktb1, podpunktb2);
		sprawdzC(a, i, min_liczba, min_wiersz, max_liczba, max_wiersz); 
	}
	// wypisujemy odpowiedzi
	odpowiedz << "A: " << podpunkta << endl;
	odpowiedz << "B: podzielne przez 2: " << podpunktb1 << " podzielne przez 8: " << podpunktb2 << endl;
	odpowiedz << "C: najwieksza: " << max_wiersz << " najmniejsza: " << min_wiersz << endl;
	// zamykamy pliki
	odpowiedz.close();
	dane.close();
	// koniec
	return 0;
}
