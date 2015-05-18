#include <fstream>
#include <iomanip>
using namespace std;

// prosta potega
// y >= 0
int potega(int x, int y) {
	int wynik = 1;
	while (y > 0) {
		wynik *= x;
		--y;
	}
	return wynik;
}

int cyfra_z_liczby_na_miejscu(int a, int i) {
	// a = ... + 8*8*x + 8*y + z
	// a = z + 8*(y + 8*(x + 8*(...)))
	//   1-> z = a %8
	//   2-> y = a/8 %8
	//   3-> x = a/(8*8) %8
	return (a/potega(8,i-1)) % 8;
}

int cyfra_z_liczby_na_miejscu10(int a, int i) {
	// a = ... + 10*10*x + 10*y + z
	// a = z + 10*(y + 10*(x + 10*(...)))
	//   1-> z = a %10
	//   2-> y = a/10 %10
	//   3-> x = a/(10*10) %10
	return (a/potega(10,i-1)) % 10;
}

int sprawdzA(int a) {
	int i = 7;
	// bo od 7 do 2 cyfr
	// szukamy najbardziej znaczaczej cyfry
	// najwyzsze miejsce i rozna od 0
	while (cyfra_z_liczby_na_miejscu(a, i) == 0 && i > 2) {
		--i;
	}
	if (cyfra_z_liczby_na_miejscu(a, i) == cyfra_z_liczby_na_miejscu(a, 1))
		return 1;
	return 0;
}

int sprawdzB(int a) {
	// jak A, tylko dla podstawy 10
	int i = 7;
	while (cyfra_z_liczby_na_miejscu10(a, i) == 0 && i > 2) {
		--i;
	}
	if (cyfra_z_liczby_na_miejscu10(a, i) == cyfra_z_liczby_na_miejscu10(a, 1))
		return 1;
	return 0;
}

int sprawdzC(int a, int &min, int &max) {
	for (int i = 7; i > 1; --i) { // sprawdzamy wyszystkie cyfry
		if (cyfra_z_liczby_na_miejscu(a, i) > cyfra_z_liczby_na_miejscu(a, i-1)) // nie spelnia warunku
			return 0; // wiec nie zliczamy
	}
	if (a < min) min = a;
	if (a > max) max = a;
	return 1;
}


int main () {
	ifstream dane;
	ofstream odpowiedz;
	int podpunkta = 0, podpunktb = 0, podpunktc = 0; // odpowiedzi
	int maxc = 0, minc = 2000000; // pierwsze sprawdzone beda na pewno wieksze/mniejsze
	int a;
	//////////
	dane.open("dane.txt"); // otwieramy plik z danymi
	odpowiedz.open("wyniki6.txt"); // otwieramy plik wyjsciowy
	// wczytujemy liczby osemkowe
	dane >> setbase(8);
	for (int i = 0; i < 5000; ++i) {
		dane >> a;
		podpunkta += sprawdzA(a);
		podpunktb += sprawdzB(a);
		podpunktc += sprawdzC(a, minc, maxc);
	}
	// wypisujemy odpowiedzi
	odpowiedz << "A: " << podpunkta << endl;
	odpowiedz << "B: " << podpunktb << endl;
	odpowiedz << "C: " << podpunktc << endl;
	odpowiedz << "najmniejsza: " << minc << " (" << setbase(8) << minc << ")" << endl;
	odpowiedz << "najwieksza: " << setbase(10) << maxc << " (" << setbase(8) << maxc << ")" << endl;
	// zamykamy pliki
	odpowiedz.close();
	dane.close();
	// koniec
	return 0;
}
