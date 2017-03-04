#include <string>
#include <fstream>

int main() {
	std::ifstream dane;
	std::ofstream odpowiedz;
	//////////
	dane.open("dane_6_3.txt"); // otwieramy dane
	odpowiedz.open("wyniki_6_3.txt"); // otwieramy wyniki
	for (int i = 1; i <= 3000; ++i) {
		std::string tmp1, tmp2;
		int klucz;
		dane >> tmp1 >> tmp2;
		klucz = tmp2[0] - tmp1[0]; // klucz dla pierwszych liter
		if (klucz < 0) klucz += 26;
		for (int j = 1; j < tmp1.size(); ++j) {
			if (tmp2[j] - tmp1[j] != klucz
			    && tmp2[j] - tmp1[j] != klucz - 26 ) { // jeśli klucz się zmienił
				odpowiedz << tmp1 << std::endl;
				break; // nie musimy sprawdzać reszty slowa, wiemy, że jest błędne
			}
		}
	}
	// zamykamy pliki
	odpowiedz.close();
	dane.close();
	// koniec
	return 0;
}
