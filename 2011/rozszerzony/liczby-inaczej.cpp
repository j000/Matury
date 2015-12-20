#include <fstream>
#include <string>
#include <cstdlib> // strtol
using namespace std;

unsigned int sprawdzA (string x) {
	// w zadaniu jest ze liczby maja min 2 znaki, wiec nie trzeba nic sprawdzac
	// parzysta wtedy, gdy ostatnia cyfra to 0
	// liczbe trzymamy jako string, wiec parzysta jesli ostatni ZNAK to '0'
	if (x[x.length()-1] == '0') {
		return 1;
	}
	return 0;
}

void sprawdzB (string x, string& max) {
	// proste porownanie NIE wystarczy
        // "100" > "10"
        // "101" > "100"
        // "10" < "101"
	// ale "11" > "101"
	if (x.length() > max.length() | (x.length() == max.length() & x > max)) {
		max = x; // zeby zadzialalo musimy przekazywac przez odwolanie (&)
	}
}

int string_na_liczbe(string x) {
	int wynik = 0;
	for (int i = 0; i < x.length(); ++i) {
		wynik *= 2;
		if (x[i] == '1')
			wynik += 1;
	}
	return wynik;
}

unsigned int sprawdzC (string x) {
	// 9-znakowe, mamy podac sume
	// zwracamy 0, albo liczbe
	// w petli sobie zsumujemy
	if (x.length() == 9) {
		return string_na_liczbe(x);
		// albo wlasna funkcja jak nie pamietamy o STRing_TO_Long z <cstdlib>
		return strtol(x.c_str(), NULL, 2); // NULL bo nie uzywamy, 2 bo binarny
	}
	return 0;
}

string binary(unsigned int a) {
	string output = "";
	for (;a > 0; a /= 2) {
		if (a & 0x1) {
			output.insert(0,"1");
		} else {
			output.insert(0,"0");
		}
	}
	return output;
}

int main () {
	ifstream dane;
	ofstream odpowiedz;
	unsigned int podpunkta = 0, podpunktc = 0;
	string liczba_max = "1"; //ustawiamy tak, zeby znalazl wieksza w danych
	string tmp;
	//////////
	dane.open("liczby.txt"); // otwieramy plik z danymi
	odpowiedz.open("wynik6.txt"); // otwieramy plik wyjsciowy
	for (int i = 0; i < 1000; ++i) {
		dane >> tmp;
		podpunkta += sprawdzA(tmp);
		sprawdzB(tmp, liczba_max);
		podpunktc += sprawdzC(tmp); 
	}
	// wypisujemy odpowiedzi
	odpowiedz << "A: parzyste: " << podpunkta << endl;
	odpowiedz << "B: najwieksza: " << liczba_max << " (" << strtol(liczba_max.c_str(), NULL, 2) << ")" << endl;
	// std::setbase nie ma opcji na binarne, wiec piszemy wlasna funkcje
	odpowiedz << "C: suma 9-cyfrowych: " << binary(podpunktc) << endl;
	// zamykamy pliki
	odpowiedz.close();
	dane.close();
	// koniec
	return 0;
}
