#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool czy_rowne_dlugosci(string a) {
	int x,y,delta;
	int dlugosci[5];
	// piec slow
	x = -1;
	for (int k = 0; k < 5; ++k) {
		y = x; // wartosc z poprzedniej petli
		x = a.find(" ",x+1); // znajdz spacje
		if (x == -1) x = a.size(); // ostatni wyraz
		delta = x-y; // dlugosc slowa
		for (int j = 0; j < k; ++j) { // sprawdzamy poprzednie slowa
			if (dlugosci[j] != delta) // jesli nie sa tej samej dlugosci
				return false; // nie sprawdzajmy dalej
		}
		dlugosci[k] = delta; // zapisz do tablicy
	}
	return true;
}

void swap(char &x, char &y) {
	char tmp = x;
	x = y;
	y = tmp;
}

void sortuj(string &a) {
	int dlugosc = a.size();
	for (int i = 1; i < dlugosc; ++i) {
		for (int k = i; k > 0 && a[k] < a[k-1]; --k) {
			swap(a[k], a[k-1]);
		}
	}
}

bool czy_anagram(string a) {
	int x,y = 0;
	string slowa[5]; // bo 5 slow
	for (int k = 0; k < 5; ++k) { // to jedziemy
		x = a.find(" ",y); // szukamy kolejnej spacji
		slowa[k] = a.substr(y,x-y); // od poprzedniej spacji, drugi argument to dlugosc slowa
		y = x+1; // zapamietujemy do nastepnej petli
		sortuj(slowa[k]);
	}
	for (int k = 0; k < 4; ++k) { // ostatniego nie potrzebujemy
		if (slowa[k] != slowa[k+1]) // jesli slowa sa rozne
			return false; // to nie sa anagramem
	}
	return true;
}

int main () {
	ifstream dane;
	ofstream odpowiedza, odpowiedzb;
	string wiersz;
	//////////
	dane.open("anagram.txt"); // otwieramy plik z danymi
	odpowiedza.open("odp_4a.txt"); // otwieramy plik wyjsciowy
	odpowiedzb.open("odp_4b.txt"); // otwieramy plik wyjsciowy
	for (int i = 0; i < 200; ++i) {
		getline(dane,wiersz); // wczytujemy cala linie
		wiersz.erase(wiersz.find_last_not_of(" \n\r")+1); // kasujemy biale znaki z konca
		if (!czy_rowne_dlugosci(wiersz)) // slowa roznej dlugosci
			continue; // anagramami tez nie beda
		odpowiedza << wiersz << endl;
		if (czy_anagram(wiersz))
			odpowiedzb << wiersz << endl;
	}
	// zamykamy pliki
	odpowiedza.close();
	odpowiedzb.close();
	dane.close();
	// koniec
	return 0;
}
