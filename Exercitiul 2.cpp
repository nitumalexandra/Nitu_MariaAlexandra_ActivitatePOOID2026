#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<cstring>
#include<exception>
using namespace std;

class Farmacie {
private:
	const int CODUnic;
	string adresa;
	int nrMedicamente;
	float* preturiMedicamente;

public:
	static int nrFarmacii;
	Farmacie() : CODUnic(++nrFarmacii) {
		adresa = " ";
		nrMedicamente = 0;
		preturiMedicamente = nullptr;
	}

	Farmacie(string adresa, int nrMedicamente, float* preturiMedicamente) : CODUnic(++nrFarmacii) {
		this->adresa = adresa;
		if (nrMedicamente > 0 && preturiMedicamente != nullptr) {
			this->nrMedicamente = nrMedicamente;

			this->preturiMedicamente = new float[nrMedicamente];

			for (int i = 0; i < nrMedicamente; i++) {
				this->preturiMedicamente[i] = preturiMedicamente[i];
			}
		}
		else {
			this->nrMedicamente = 0;
			this->preturiMedicamente = nullptr;
		}

	}

	void afisareFarmacie() {
		cout << "Codul unic este: " << CODUnic << endl;
		cout << "Adresa este: " << adresa << endl;
		cout << "Nr. medicamente este: " << nrMedicamente << endl;
		if (preturiMedicamente != nullptr) {
			cout << "Pretul este: " << preturiMedicamente[nrMedicamente - 1] << endl;
		}
	}

	int getCODUnic() {
		return this->CODUnic;
	}

	string getAdresa() {
		return this->adresa;
	}

	int getNrMedicamente() {
		return this->nrMedicamente;
	}

	void setAdresa(string adresaNoua) {
		if (adresaNoua.length() > 0) {
			this->adresa = adresaNoua;
		}
		else {
			throw exception();
		}

	}

	~Farmacie() {
		if (this->preturiMedicamente != nullptr) {
			delete[]preturiMedicamente;
		}
		cout << "S-a apelat destructorul" << endl;
	}

};

int Farmacie::nrFarmacii = 0;

int main() {

	float preturiMedicamente[2] = { 13.5, 20.4 };

	Farmacie f = Farmacie("Bucuresti", 2, preturiMedicamente);
	Farmacie f2 = Farmacie("Brasov", 1, preturiMedicamente);
	f.afisareFarmacie();
	f2.afisareFarmacie();

	f.setAdresa("Calea Mosilor");
	f.getAdresa();
	cout << endl;
	f.afisareFarmacie();
	cout << endl << f.getCODUnic() << endl;
	cout << f.getAdresa() << endl;
	cout << f.getNrMedicamente() << endl;

	cout << "Numarul de farmacii este: " << Farmacie::nrFarmacii << endl;

	return 0;
}
