#include <string>
#include <fstream> // ifstream, ofstream
#include <iostream> // cout
#include <iomanip> // width
#include <cmath> // pi

static int const PUNKTY = 10000;
static int const PROMIEN = 200;

int main() {
	std::ifstream dane;
	std::ofstream odpowiedz;
	//////////
	dane.open("punkty.txt"); // otwieramy dane
	odpowiedz.open("wyniki_4.txt"); // otwieramy wyniki
	odpowiedz << std::fixed << std::setprecision(4); // wypisujemy 4 cyfry po przecinku
	// 4.1
	odpowiedz << "4.1.\n";
	int a = 0; // ilość punktów
	for (int i = 0; i < PUNKTY; ++i) {
		int x,y;
		dane >> x >> y;
		if ((x-200)*(x-200) + (y-200)*(y-200) == PROMIEN*PROMIEN) {
			odpowiedz << "(" << x << ", " << y << ")\n";
		} else if ((x-200)*(x-200) + (y-200)*(y-200) < PROMIEN*PROMIEN) {
			++a;
		}
	}
	odpowiedz << a << std::endl;
	//
	dane.seekg(0); // przewijamy do początku pliku
	// 4.2
	odpowiedz << "4.2.\n";
	// liczymy nk/n = (pi*r^2)/(4*r^2) => pi = 4*nk/n
	int nk = 0;
	for (int i = 1; i <= PUNKTY; ++i) {
		int x,y;
		dane >> x >> y;
		if ((x-200)*(x-200) + (y-200)*(y-200) <= PROMIEN*PROMIEN) {
			++nk;
		}
		if (i == 1000) {
			odpowiedz << 4./1000*nk << std::endl;
		} else if (i == 5000) {
			odpowiedz << 4./5000*nk << std::endl;
		}
	}
	odpowiedz << 4./PUNKTY*nk << std::endl;
	//
	dane.seekg(0); // przewijamy do początku pliku
	// 4.3
	odpowiedz << "4.3." << std::endl;
	nk = 0;
	std::cout << std::fixed << std::setprecision(4);
	for (int i = 1; i <= 1700; ++i) {
		int x,y;
		dane >> x >> y;
		if ((x-200)*(x-200) + (y-200)*(y-200) <= PROMIEN*PROMIEN) {
			++nk;
		}
		//std::cout << i << " " << std::abs(M_PI - 4./i*nk) << std::endl; // do excela, dla wykresu
		if (i == 1000 || i == 1700) {
			odpowiedz << std::abs(M_PI - 4./i*nk) << std::endl;
		}
	}
	// zamykamy pliki
	odpowiedz.close();
	dane.close();
	// koniec
	return 0;
}
