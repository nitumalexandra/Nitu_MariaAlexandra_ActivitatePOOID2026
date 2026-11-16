#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<string>
using namespace std;

class Magazin {
private:
	const int idMagazin;
	string denumire;
	int nrProduse;
	float* preturiProduse;

public:
	static int nrMagazin;

	Magazin() : idMagazin(++nrMagazin) {
		denumire = " ";
		nrProduse = 0;
		preturiProduse = nullptr;
	}

	Magazin(string denumire, int nrProduse, float* preturiProduse) : idMagazin(++nrMagazin) {
		if (denumire.length() > 0) {
			this->denumire = denumire;
		}
		else {
			this->denumire = " ";
		}

		if (nrProduse > 0 && preturiProduse != nullptr) {
			this->nrProduse = nrProduse;
			this->preturiProduse = new float[nrProduse];
			for (int i = 0; i < nrProduse; i++) {
				this->preturiProduse[i] = preturiProduse[i];
			}
		}
		else {
			this->nrProduse = 0;
			this->preturiProduse = nullptr;
		}

	}


	string getDenumire() {
		return denumire;
	}

	void setDenumire(string denumire) {
		if (denumire.length() > 0) {
			this->denumire = denumire;
		}
	}

	int getNrProduse() {
		return nrProduse;
	}

	void setNrProduse(int nrProduse) {
		if (nrProduse > 0) {
			this->nrProduse = nrProduse;
		}
	}

	float* getPreturiProduse() {
		return preturiProduse;
	}

	void setPreturiProduse(int nrProduse, const float* preturiProduse) {
		if (nrProduse > 0 && preturiProduse != nullptr) {

			float* vectorNou = new float[nrProduse];

			for (int i = 0; i < nrProduse; i++) {
				vectorNou[i] = preturiProduse[i];
			}

			delete[] this->preturiProduse;

			this->preturiProduse = vectorNou;
			this->nrProduse = nrProduse;
		}
	}

	//constructorul de copiere
	Magazin(const Magazin& m) : idMagazin(++nrMagazin) {
		denumire = m.denumire;
		nrProduse = m.nrProduse;

		if (nrProduse > 0 && m.preturiProduse != nullptr) {
			preturiProduse = new float[nrProduse];

			for (int i = 0; i < nrProduse; i++) {
				preturiProduse[i] = m.preturiProduse[i];
			}

		}
		else {
			nrProduse = 0;
			preturiProduse = nullptr;
		}
	}

	//operatorul =
	Magazin& operator=(const Magazin& m) {
		if (this != &m) {
			denumire = m.denumire;
			nrProduse = m.nrProduse;

			if (preturiProduse != nullptr) {
				delete[]preturiProduse;
				preturiProduse = nullptr;
			}

			if (m.preturiProduse != nullptr) {
				preturiProduse = new float[nrProduse];
				for (int i = 0; i < nrProduse; i++) {
					preturiProduse[i] = m.preturiProduse[i];
				}
			}
		}
		else {
			preturiProduse = nullptr;
		}

		return *this;
	}

	void afisare() {
		cout << "ID-ul magazinului este: " << idMagazin << endl;
		cout << "Denumirea magazinului este: " << denumire << endl;
		cout << "Numarul produselor sunt: " << nrProduse << endl;

		cout << "Preturile produselor sunt: ";
		for (int i = 0; i < nrProduse; i++) {
			cout << preturiProduse[i] << " ";
		}
		cout << endl;
	}


	~Magazin() {
		delete[] preturiProduse;
	}


};

int Magazin::nrMagazin = 0;

int main() {

	float preturi[] = { 10.5, 16.3,20.6 };

	Magazin m1;

	Magazin m2("Profi", 3, preturi);

	m1.afisare();
	cout << endl;
	m2.afisare();

	cout << endl;
	cout << "Numarul magazinelor este de: " << Magazin::nrMagazin << endl;

	cout << endl;
	cout << "Copiam valoarea din al 2-lea magazin intr-un magazin 3 nedeclarat: ";
	Magazin m3 = m2;
	cout << endl;
	m3.afisare();
	cout << endl << "Numarul magazinelor este de: " << Magazin::nrMagazin << endl;

	cout << "Copiam valoarea din al 2-lea in primul magazin: " << endl;
	m1 = m2;
	m1.afisare();



	return 0;
}