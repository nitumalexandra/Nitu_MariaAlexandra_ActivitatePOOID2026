#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<string>
using namespace std;

class Hotel {
private:
	const int codHotel;
	string denumire;
	int nrCamere;
	float* preturiCamere;

public:
	static int nrHotel;

	Hotel() :codHotel(++nrHotel) {
		denumire = " ";
		nrCamere = 0;
		preturiCamere = nullptr;
	}

	Hotel(string denumire, int nrCamere, float* preturiCamere) : codHotel(++nrHotel) {
		if (denumire.length() > 0) {
			this->denumire = denumire;
		}
		else {
			denumire = " ";
		}

		if (nrCamere > 0 && preturiCamere != nullptr) {
			this->nrCamere = nrCamere;
			this->preturiCamere = new float[nrCamere];

			for (int i = 0; i < nrCamere; i++) {
				this->preturiCamere[i] = preturiCamere[i];
			}

		}
		else {
			this->nrCamere = 0;
			this->preturiCamere = nullptr;
		}

	}

	//constructor de copiere
	Hotel(const Hotel& h) : codHotel(++nrHotel) {
		denumire = h.denumire;
		nrCamere = h.nrCamere;

		if (nrCamere > 0 && h.preturiCamere != nullptr) {
			preturiCamere = new float[nrCamere];

			for (int i = 0; i < nrCamere; i++) {
				preturiCamere[i] = h.preturiCamere[i];
			}
		}
		else {
			preturiCamere = nullptr;
			nrCamere = 0;
		}

	}

	string getDenunmire() {
		return denumire;
	}

	void setDenumire(string denumire) {
		if (this->denumire.length() > 0) {
			this->denumire = denumire;
		}
	}

	int getNrCamere() {
		return nrCamere;
	}

	int getCodHotel() {
		return codHotel;
	}

	//operatorul =

	Hotel& operator=(const Hotel& h) {
		if (this != &h) {
			this->denumire = h.denumire;
			this->nrCamere = h.nrCamere;

			if (this->preturiCamere != nullptr) {
				delete[] this->preturiCamere;
				this->preturiCamere = h.preturiCamere;
			}

			if (h.preturiCamere != nullptr) {
				this->preturiCamere = new float[this->nrCamere];

				for (int i = 0; i < this->nrCamere; i++) {
					this->preturiCamere[i] = h.preturiCamere[i];
				}
			}
			else {
				this->preturiCamere = nullptr;
			}
		}

		return *this;

	}


	~Hotel() {
		delete[] preturiCamere;
	}

	void afisare() {
		cout << "Cod hotel: " << codHotel << endl;
		cout << "Denumire: " << denumire << endl;
		cout << "Numar camere: " << nrCamere << endl;

		cout << "Preturi camere: ";
		for (int i = 0; i < nrCamere; i++) {
			cout << preturiCamere[i] << " ";
		}
		cout << endl;
	}
};

int Hotel::nrHotel = 0;

int main() {
	float preturi[] = { 150, 220, 300 };

	Hotel h1;
	Hotel h2("Ramada", 3, preturi);
	Hotel h3 = h2;

	h1.afisare();
	cout << endl;

	h2.afisare();
	cout << endl;

	h3.afisare();
	cout << endl;

	cout << "Numarul de hoteluri: " << Hotel::nrHotel << endl;



	return 0;
}