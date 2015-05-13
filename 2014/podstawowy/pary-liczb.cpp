#include <iostream>
#include <fstream>
using namespace std;

int sprawdzA (int x, int y) {
	if (x % y == 0 || y % x == 0) // jak nie ma reszty z dzielenia
		return 1; // jest wielokrotnoscia
	return 0;
}

int sprawdzB (int x, int y) {
	for (int k = 2; k <= x && k <= y; ++k) { // 1 < k <= (x,y)
		if (x % k == 0 && y % k == 0) { // jezeli k jest wspolnym dzielnikiem
			return 0; // konczymy szukac
		}
	}
	return 1;
}

int suma (int x) { // liczy sume cyfr
	int suma = 0;
	for (int k = 10000; k >= 1; k /= 10) { // bo max 30000
		suma += (x/k) % 10;
	}
	return suma;
}

int sprawdzC (int x, int y) {
	int sumax = 0, sumay = 0;
	sumax = suma(x);
	sumay = suma(y);
	if (sumax == sumay) // jesli sumy  sa takie same
		return 1; // to dobrze
	return 0;
}

int main () {
	ifstream dane;
	ofstream odpowiedz;
	int a, b; // wczytana para liczb
	int podpunkta = 0, podpunktb = 0, podpunktc = 0; // odpowiedzi
	//////////
	dane.open("PARY_LICZB.TXT"); // otwieramy plik z danymi
	odpowiedz.open("ZADANIE5.TXT"); // otwieramy plik wyjsciowy
	for (int i = 0; i < 1000; ++i) {
		dane >> a >> b;
		podpunkta += sprawdzA(a, b);
		podpunktb += sprawdzB(a, b);
		podpunktc += sprawdzC(a, b);
	}
	// wypisujemy odpowiedzi
	odpowiedz << "A: " << podpunkta << endl;
	odpowiedz << "B: " << podpunktb << endl;
	odpowiedz << "C: " << podpunktc << endl;
	// zamykamy pliki
	odpowiedz.close();
	dane.close();
	// koniec
	return 0;
}
