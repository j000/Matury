#include <fstream>
#include <string>
using namespace std;

bool czy_rowne_dlugosci(string a[]) {
	// piec slow
	for (int k = 1; k < 5; ++k) {
		if (a[k-1].size() != a[k].size()) // jesli rozna dlugosc
			return false; // zwroc false
	}
	return true;
}

void zamien(char &x, char &y) {
	char tmp = x;
	x = y;
	y = tmp;
}

void sortuj(string &a) {
	int dlugosc = a.size();
	for (int i = 1; i < dlugosc; ++i) {
		for (int k = i; k > 0 && a[k] < a[k-1]; --k) {
			zamien(a[k], a[k-1]);
		}
	}
}

bool czy_anagram(string a[]) {
	// dzialanie:
	// adcb dcba -> abcd abcd => anagramy
	// abac adac -> aabc aacd => nie anagramy
	string kopia[5];
	for (int k = 0; k < 5; ++k) {
		kopia[k] = a[k];
	}
	for (int k = 0; k < 5; ++k) { // to jedziemy
		sortuj(kopia[k]);
	}
	for (int k = 1; k < 5; ++k) { // ostatniego nie potrzebujemy
		if (kopia[k-1] != kopia[k]) // jesli slowa sa rozne
			return false; // to nie sa anagramem
	}
	return true;
}

int main () {
	ifstream dane;
	ofstream odpowiedza, odpowiedzb;
	string wyrazy[5];
	//////////
	dane.open("anagram.txt"); // otwieramy plik z danymi
	odpowiedza.open("odp_4a.txt"); // otwieramy plik wyjsciowy
	odpowiedzb.open("odp_4b.txt"); // otwieramy plik wyjsciowy
	for (int i = 0; i < 200; ++i) {
		for (int k = 0; k < 5; ++k) {
			dane >> wyrazy[k];
		}
		if (!czy_rowne_dlugosci(wyrazy)) // slowa roznej dlugosci
			continue; // anagramami tez nie beda
		for (int k = 0; k < 5; ++k) {
			odpowiedza << wyrazy[k] << " "; // wypisujemy wszystkie wyrazy
		}
		odpowiedza << endl; // koniec lini
		if (czy_anagram(wyrazy)) {
			for (int k = 0; k < 5; ++k) {
				odpowiedzb << wyrazy[k] << " "; // wypisujemy wszystkie wyrazy
			}
			odpowiedzb << endl; // koniec lini
		}
	}
	// zamykamy pliki
	odpowiedza.close();
	odpowiedzb.close();
	dane.close();
	// koniec
	return 0;
}
