#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct eleviPb1 {
	string nume;
	string prenume;
	int medie;
	int teza;

	int notaSemestriala() {
		return round((double) ((3 * medie) + teza) / 4);
	}
};