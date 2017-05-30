#include <string>
#include <fstream> // ifstream, ofstream
#include <iostream>

static int const WIERSZE = 200;
static int const KOLUMNY = 320;

bool kontrast(unsigned char &a, unsigned char &b) {
	if (abs(a-b) > 128)
		return true;
	return false;
}

int main() {
	std::ifstream dane;
	std::ofstream odpowiedz;
	// nie zapominamy o unsigned
	unsigned char obraz[WIERSZE][KOLUMNY];
	int odpowiedz1_min = 255;
	int odpowiedz1_max = 0;
	int odpowiedz2 = 0;
	int odpowiedz3 = 0;
	int odpowiedz4 = 0;
	//////////
	//#define PRZYKLAD
#ifdef PRZYKLAD
	dane.open("przyklad.txt"); // otwieramy przyklad
#else
	dane.open("dane.txt"); // otwieramy dane
#endif
	odpowiedz.open("wyniki6.txt"); // otwieramy wyniki
	//////////
	// wczytujemy
	for (int x = 0; x < WIERSZE; ++x) {
		for (int y = 0; y < KOLUMNY; ++y) {
			int tmp;
			dane >> tmp;
			obraz[x][y] = tmp;
			if (obraz[x][y] < 0)
				std::cout << x << ", " << y << std::endl;
			// od razu szukamy min/max
			if (tmp > odpowiedz1_max)
				odpowiedz1_max = tmp;
			if (tmp < odpowiedz1_min)
				odpowiedz1_min = tmp;
		}
	}
	//////////
	// pionowa oś symetrii
	for (int x = 0; x < WIERSZE; ++x) {
		for (int y = 0; y < KOLUMNY/2; ++y) {
			// jesli piksel 0+y ma inną wartość niż 319-y
			// to nie ma osi symetrii w tym wierszu
			if (obraz[x][y] != obraz[x][KOLUMNY-1-y]) {
				++odpowiedz2;
				break; // przerywamy wewnętrzną pętlę
				// czyli przechodzimy do następnego wiersza
			}
		}
	}
	//////////
	// kontrastujące piksele
	for (int x = 0; x < WIERSZE; ++x) {
		for (int y = 0; y < KOLUMNY; ++y) {
			if ((x!=0 && kontrast(obraz[x][y],obraz[x-1][y])) || // powyżej
			   (x!=WIERSZE-1 && kontrast(obraz[x][y],obraz[x+1][y])) || // poniżej
			   (y!=0 && kontrast(obraz[x][y],obraz[x][y-1])) || // na lewo
			   (y!=KOLUMNY-1 && kontrast(obraz[x][y],obraz[x][y+1]))) { // na prawo
				++odpowiedz3;
			}
		}
	}
	//////////
	// pionowa linia
	int najdluzsza = 0;
	int nasza = 0;
	unsigned char poprzedni = 0;
	for (int y = 0; y < KOLUMNY; ++y) {
		for (int x = 0; x < WIERSZE; ++x) {
			// kiedy taki sam to liczymy
			if (obraz[x][y] == poprzedni) {
				++nasza;
			// skończył się jeden kolor
			} else {
				if (nasza > najdluzsza)
					najdluzsza = nasza;
				poprzedni = obraz[x][y]; // zapamiętujemy
				nasza = 1; // bo jesteśmy na pierwszym pikselu linii
			}
		}
	}
	odpowiedz4 = najdluzsza;
	//////////
	odpowiedz << "6.1: najjaśniejszy:" << odpowiedz1_max << " najciemniejszy: " << odpowiedz1_min << std::endl;
	odpowiedz << "6.2: " << odpowiedz2 << std::endl;
	odpowiedz << "6.3: " << odpowiedz3 << std::endl;
	odpowiedz << "6.4: " << odpowiedz4 << std::endl;
	// zamykamy pliki
	odpowiedz.close();
	dane.close();
	// koniec
	return 0;
}
