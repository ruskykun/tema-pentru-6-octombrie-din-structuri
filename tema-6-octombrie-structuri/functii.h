#include "functii-baza.h"

// Afisari Vectori

void afisareVectorDouble(double x[], int n) {
	cout << "x[" << n << "] = {";
	int c = n;
	for (int i = 0; i < n; i++) {
		cout << x[i];
		if (c > 1) {
			cout << ", ";
			c--;
		}
		else {
			cout << "}" << endl;
		}
	}
}

void afisareVectorInt(int x[], int n) {
	cout << "x[" << n << "] = {";
	int c = n;
	for (int i = 0; i < n; i++) {
		cout << x[i];
		if (c > 1) {
			cout << ", ";
			c--;
		}
		else {
			cout << "}" << endl;
		}
	}
}

void afisareVectorString(string x[], int n) {
	for (int i = 0; i < n; i++) {
		cout << x[i] << endl;
	}
}

// Citiri

void citireEleviTipA(eleviTipA x[], int& n) {
	ifstream f("pb-eleviA.txt");
	f >> n;

	for (int i = 0; i < n; i++) {
		eleviTipA elev;
		f >> elev.nume;
		f >> elev.prenume;
		f >> elev.medie;
		f >> elev.teza;

		x[i] = elev;
	}
}

void citireEleviTipB(eleviTipB x[], int& n) {
	ifstream f("pb-eleviB.txt");
	f >> n;
	
	for (int i = 0; i < n; i++) {
		eleviTipB a;

		f >> a.nume;
		f >> a.prenume;
		f >> a.varsta;
		f >> a.inaltime;

		x[i] = a;
	}
}

void citireSportiviTipA(sportiviTipA x[], int& n) {
	ifstream f("pb-sportivi.txt");
	f >> n;

	for (int i = 0; i < n; i++) {
		sportiviTipA a;
		f >> a.luna;
		f >> a.an;
		
		x[i] = a;
	}
}

void citireBursaTipA(bursaTipA x[], int& n) {
	ifstream f("pb-bursa.txt");
	f >> n;

	for (int i = 0; i < n; i++) {
		bursaTipA b;

		f >> b.nume;
		f >> b.prenume;
		f >> b.nrmembrii;
		f >> b.venit;

		x[i] = b;
	}
}

void citireFractieTipA(fractieTipA x[], int& n) {
	ifstream f("pb-fractii.txt");
	f >> n;
	
	for (int i = 0; i < n; i++) {
		fractieTipA fractie;

		f >> fractie.numitor;
		f >> fractie.numarator;
		
		x[i] = fractie;
	}
}

void citireComplexTipA(complexTipA x[], int& n) {
	ifstream f("pb-complexe.txt");
	f >> n;

	for (int i = 0; i < n; i++) {
		f >> x[i].reala;
		f >> x[i].imaginara;
	}
}

// Metode de sortare

void bubbleSortDouble(double x[], int n) {
	bool flag = true;
	do {
		flag = true;
		for (int i = 0; i < n - 1; i++) {
			if (x[i] > x[i + 1]) {
				double r = x[i];
				x[i] = x[i + 1];
				x[i + 1] = r;
				flag = false;
			}
		}
	} while (flag == false);
}

// Problema 1

void mediiSemestriale(eleviTipA x[], int n, int medii[]) {
	for (int i = 0; i < n; i++) {
		medii[i] = x[i].notaSemestriala();
	}
}

void mediaClaseiSiNotaMax(int medii[], int n, int& max, double& medieClasa) {
	int s = 0;
	max = medii[0];
	for (int i = 0; i < n; i++) {
		s += medii[i];
		if (medii[i] > max) {
			max = medii[i];
		}
	}
	medieClasa = (double) s / n;
}

void afisareRaspunsPb1(eleviTipA x[], int medii[], int n, int max, double medieClasa) {
	cout << "Media clasei este " << medieClasa << ", iar elevii cu nota maxima sunt :" << endl;
	for (int i = 0; i < n; i++) {
		if (x[i].notaSemestriala() == max) {
			cout << x[i].nume << " " << x[i].prenume << endl;
		}
	}

}

// Problema 2

void atribuireIndiciSiMedii(eleviTipA x[], int n, int medii[], int indici[], int& m) {
	m = 0;
	for (int i = 0; i < n; i++) {
		int medie = x[i].notaSemestriala();
		if (medie >= 5) {
			indici[m] = i;
			medii[m] = medie;
			m++;
		}
	}
}

void sortareDescrescatorDupaMedie(int medii[], int indici[], int m) {
	bool flag = true;
	do {
		flag = true;
		for (int i = 0; i < m - 1; i++) {
			if (medii[i] < medii[i + 1]) {
				int r1 = medii[i];
				int r2 = indici[i];
				medii[i] = medii[i + 1];
				medii[i + 1] = r1;
				indici[i] = indici[i + 1];
				indici[i + 1] = r2;
				flag = false;
			}
		}
	} while (flag == false);
}

void afisareRaspunsPb2(eleviTipA x[], int indici[], int m) {
	cout << "Elevii care au promovat in ordine descrescatoare a mediei sunt :" << endl;
	for (int i = 0; i < m; i++) {
		eleviTipA elev;
		elev = x[indici[i]];
		cout << elev.nume << " " << elev.prenume << " - " << elev.notaSemestriala() << endl;
	}
}

// Problema 3

void atribuieNumeSiPrenume(eleviTipA x[], int n, string nume[], string prenume[], int& m) {
	m = 0;
	for (int i = 0; i < n; i++) {
		if (x[i].notaSemestriala() < 5) {
			nume[m] = x[i].nume;
			prenume[m] = x[i].prenume;
			m++;
		}
	}
}

void afisareRaspunsPb3(string nume[], string prenume[], int m) {
	cout << "Elevii corigenti in ordine alfabetica sunt :" << endl;
	for (int i = 0; i < m; i++) {
		cout << nume[i] << " " << prenume[i] << endl;
	}
}

// Problema 4

void numeSiPrenumePb4(eleviTipA x[], int n, string nume[], string prenume[]) {
	for (int i = 0; i < n; i++) {
		nume[i] = x[i].nume;
		prenume[i] = x[i].prenume;
	}
}

void afisareRaspunsPb4(string nume[], string prenume[], int n) {
	cout << "Elevii ordonati alfabetic sunt :" << endl;
	for (int i = 0; i < n; i++) {
		cout << nume[i] << " " << prenume[i] << endl;
	}
}

// Problema 5

double mediaVarstei(sportiviTipA x[], int n) {
	int s = 0;
	for (int i = 0; i < n; i++) {
		s += x[i].varsta();
	}
	return (double)s / n;
}

void afisareRaspunsPb5(sportiviTipA x[], double medie, int n) {
	cout << "(Varsta a fost rotunjita pentru afisare)" << endl;
	cout << "Varsta medie a sportivilor este " << round(medie / 12) << ", iar cei mai mici decat aceasta" << endl;
	cout << "sunt cei nascuti in datele :" << endl;
	for (int i = 0; i < n; i++) {
		if (x[i].varsta() < medie) {
			cout << x[i].luna << "-" << x[i].an << endl;
		}
	}
}

// Problema 6

void atribuirePb6(bursaTipA x[], int n, int L, string nume[], string prenume[], int& m) {
	m = 0;
	for (int i = 0; i < n; i++) {
		if (x[i].venitPerMembru() > L) {
			nume[m] = x[i].nume;
			prenume[m] = x[i].prenume;
			m++;
		}
	}
}

void afisareRaspunsPb6(string nume[], string prenume[], int m) {
	cout << "Elevii care nu primesc bursa in ordine alfabetica sunt :" << endl;
	for (int i = 0; i < m; i++) {
		cout << nume[i] << " " << prenume[i] << endl;
	}
}

// Problema 7

void rezolvarePb7(fractieTipA x[], int n, int& numar) {
	numar = 0;
	double val = x[n - 1].valoare();
	for (int i = 0; i < n - 1; i++) {
		if (x[i].valoare() == x[n - 1].valoare()) {
			numar++;
		}
	}
}

// Problema 8

void atribuireModule(complexTipA x[], int n, double module[], int& m, int a, int b) {
	m = 0;
	for (int i = 0; i < n; i++) {
		double modul = x[i].modul();
		if (modul < a || modul > b) {
			module[m] = modul;
			m++;
		}
	}
}

void afisareRaspunsPb7(double module[], int m, int a, int b) {
	cout << "Modulele in ordine crescatoare care nu apartin intervalului [" << a << ", " << b << "] sunt :" << endl;
	for (int i = 0; i < m; i++) {
		cout << module[i] << endl;
	}
}

// Problema 9

void atribuirePb9(eleviTipB x[], int n, string nume[], string prenume[], double inaltimi[], int& m, double h1, double h2) {
	m = 0;
	for (int i = 0; i < n; i++) {
		if (x[i].varsta >= 14 && x[i].inaltime >= h1 && x[i].inaltime <= h2) {
			nume[m] = x[i].nume;
			prenume[m] = x[i].prenume;
			inaltimi[m] = x[i].inaltime;
			m++;
		}
	}
}

void afisareRaspunsPb9(string nume[], string prenume[], double inaltimi[], int n) {
	cout << "Elevii care au implinit 14 ani in ordine alfabetica si au inaltimea in acest interval sunt :" << endl;
	for (int i = 0; i < n; i++) {
		cout << nume[i] << " " << prenume[i] << " - " << inaltimi[i] << endl;
	}
}




