#include <string>
#include <fstream>

int main() {
	std::ifstream dane;
	std::ofstream odpowiedz;
	//////////
	dane.open("dane_6_2.txt"); // otwieramy dane
	odpowiedz.open("wyniki_6_2.txt"); // otwieramy wyniki
	for (int i = 1; i <= 100; ++i) {
		std::string tmp;
		int klucz;
		dane >> tmp >> klucz;
		klucz %= 26;
		klucz = 26 - klucz; // szyfrowanie jest cykliczne, tak bedzie nam latwiej
		for (int j = 0; j < tmp.size(); ++j) {
			char k = tmp[j] - 'A'; // zamieniamy na kod, A = 0, Z = 26
			k += klucz; // dodajemy klucz
			k %= 26; // nie wychodzimy poza Z
			k += 'A'; // zamieniamy na litere
			odpowiedz << k;
		}
		odpowiedz << std::endl;
	}
	// zamykamy pliki
	odpowiedz.close();
	dane.close();
	// koniec
	return 0;
}
