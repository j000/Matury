#include <string>
#include <fstream> // ifstream, ofstream
#include <vector>

static int const LICZBY = 2000;

bool sprawdz_czy_pierwsza(int a) {
	// z danych wynika, że możemy dostać 0, ale nie jest pierwsze
	if (a == 0 || a == 1 || a % 2 == 0) { // jeśli 0, 1 albo parzysta
		return false;
	}
	int tmp = 3;
	while (tmp < a) {
		if (a % tmp == 0) { // jeśli dzieli się przez tmp bez reszty
			return false;
		}
		tmp += 2; // omijamy parzyste
	}
	return true;
}

int main() {
	std::ifstream dane;
	std::ofstream odpowiedz;
	int max = 0;
	int min = 30000;
	int pierwsze = 0;
	int prev = 0;
	std::vector<int> blizniacze;
	//////////
	dane.open("dane6.txt"); // otwieramy dane
	odpowiedz.open("wyniki_6.txt"); // otwieramy wyniki
	for (int i = 1; i <= LICZBY; ++i) {
		int tmp;
		dane >> tmp;
		bool czy_pierwsza = sprawdz_czy_pierwsza(tmp);
		if (czy_pierwsza) {
			++pierwsze;
			if (tmp > max) max = tmp; // największaa
			if (tmp < min) min = tmp; // najmniejsza
			if (tmp - prev == 2 || tmp - prev == -2) {
				blizniacze.push_back(prev); // dopisz do tablicy
				blizniacze.push_back(tmp); // w takiej kolejności w jakiej są w pliku
			}
			prev = tmp;
		}
	}
	odpowiedz << "6.1: " << pierwsze << std::endl;
	odpowiedz << "6.2: " << max << ", " << min << std::endl;
	odpowiedz << "6.3: " << blizniacze.size()/2 << std::endl;
	for (int i = 0; i < blizniacze.size(); i += 2) {
		odpowiedz << blizniacze[i] << " " << blizniacze[i+1] << std::endl;
	}
	// zamykamy pliki
	odpowiedz.close();
	dane.close();
	// koniec
	return 0;
}
