#include <fstream>
#include <string>
using namespace std;

bool czy_pierwsza(int a) {
	for (int k = 2; k < a; ++k) { // 1 < k < a
		if (a % k == 0) { // jesli dzieli sie bez reszty
			return false; // to nie jest pierwsza
		}
	}
	return true;
}

int sprawdzA (string x) {
	int suma = 0;
	for (int k = 0; k < x.size(); ++k) {
		suma += x[k];
	}
	if (czy_pierwsza(suma)) return 1;
	return 0;
}

string sprawdzB (string x) {
	for (int k = 1; k < x.size(); ++k) {
		if (x[k-1] >= x[k]) // jesli nie jest rosnacy
			return ""; // nie sprawdzamy dalej
	}
	return '\n' + x;
	// dla windowsa chyba tak trzeba:
	// return "\r\n" + x
}

int main () {
	ifstream dane;
	ofstream odpowiedz;
	int podpunkta = 0, podpunktc = 0; // odpowiedzi
	string podpunktb = "";
	string a;
	string lista [1000];
	int wystapienia [1000];
	//////////
	dane.open("NAPIS.TXT"); // otwieramy plik z danymi
	odpowiedz.open("ZADANIE5R.TXT"); // otwieramy plik wyjsciowy
	for (int i = 0; i < 1000; ++i) {
		dane >> a;
		podpunkta += sprawdzA(a);
		podpunktb += sprawdzB(a);
		lista[i] = a;
		// podpunkt c
		wystapienia[i] = 0;
		for (int k = 0; k <= i; ++k) {
			if (lista[i] == lista[k]) {
				++wystapienia[k];
				break;
			}
		}
	}
	// wypisujemy odpowiedzi
	odpowiedz << "A: " << podpunkta << endl;
	odpowiedz << "B: " << podpunktb << endl;
	odpowiedz << "C: " << endl;
	for (int i = 0; i < 1000; ++i) {
		if (wystapienia[i] >= 2)
			odpowiedz << lista[i] << endl;
	}
	// zamykamy pliki
	odpowiedz.close();
	dane.close();
	// koniec
	return 0;
}
