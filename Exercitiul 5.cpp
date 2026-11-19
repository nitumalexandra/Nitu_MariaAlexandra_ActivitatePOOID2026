#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Biblioteca {
private:
	const int codBiblioteca;
	string denumire;
	int nrCarti;
	float* preturiCarti;

public:
	static int nrBiblioteci;

	Biblioteca() :codBiblioteca(++nrBiblioteci) {
		denumire = " ";
		nrCarti = 0;
		preturiCarti = nullptr;
	}

	Biblioteca(string denumire, int nrCarti, float* preturiCarti) : codBiblioteca(++nrBiblioteci) {
		if (denumire.length() > 0) {
			this->denumire = denumire;
		}

		if (nrCarti > 0 && preturiCarti != nullptr) {
			this->nrCarti = nrCarti;
			this->preturiCarti = new float[nrCarti];
			for (int i = 0; i < this->nrCarti; i++) {
				this->preturiCarti[i] = preturiCarti[i];
			}
		}
		else {
			this->nrCarti = 0;
			this->preturiCarti = nullptr;
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

	int getNrCarti() {
		return nrCarti;
	}

	int getCodBiblioteca() {
		return codBiblioteca;
	}

	Biblioteca(const Biblioteca& b) :codBiblioteca(++nrBiblioteci) {
		denumire = b.denumire;
		nrCarti = b.nrCarti;

		if (b.nrCarti > 0 && b.preturiCarti != nullptr) {
			preturiCarti = new float[nrCarti];

			for (int i = 0; i < nrCarti; i++) {
				preturiCarti[i] = b.preturiCarti[i];
			}
		}
		else {
			nrCarti = 0;
			preturiCarti = nullptr;
		}


	}

	Biblioteca& operator=(const Biblioteca& b) {
		if (this != &b) {
			this->denumire = b.denumire;
			this->nrCarti = b.nrCarti;

			if (this->preturiCarti != nullptr) {
				delete[] this->preturiCarti;
				this->preturiCarti = nullptr;
			}

			if (b.preturiCarti != nullptr) {
				this->preturiCarti = new float[this->nrCarti];
				for (int i = 0; i < this->nrCarti;i++) {
					this->preturiCarti[i] = b.preturiCarti[i];
				}
			}
			else {
				this->preturiCarti = nullptr;
			}
		}

		return *this;
	}

	~Biblioteca() {
		delete[] preturiCarti;
	}

	void afisare() {
		cout << "Codul este: " << codBiblioteca << endl;
		cout << "Denumire este: " << denumire << endl;
		cout << "Numarul cartilor este: " << nrCarti << endl;
		cout << "Pretul cartilor este: ";

		for (int i = 0; i < nrCarti; i++) {
			cout << preturiCarti[i] << " ";
		}
		cout << endl;

	}



};

int Biblioteca::nrBiblioteci = 0;


int main() {

	float preturi[] = { 40.4, 12.8 };

	Biblioteca b1("Carturesti", 1, preturi);
	Biblioteca b2 = b1;
	Biblioteca b3;

	b1.afisare();
	b2.afisare();

	b3 = b1;

	b3.afisare();

	cout << "Numarul lor este: " << Biblioteca::nrBiblioteci;


	return 0;
}
