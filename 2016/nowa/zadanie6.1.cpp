#include <string>
#include <fstream>

static int const klucz = 107 % 26; // 107 z danych, 26 liter w alfabecie

int main() {
	std::ifstream dane;
	std::ofstream odpowiedz;
	//////////
	dane.open("dane_6_1.txt"); // otwieramy dane
	odpowiedz.open("wyniki_6_1.txt"); // otwieramy wyniki
	for (int i = 1; i <= 100; ++i) {
		std::string tmp;
		dane >> tmp;
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
