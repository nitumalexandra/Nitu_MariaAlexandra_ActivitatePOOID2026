#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <cstring>
#include<string>
using namespace std;

class Restaurant {
private:
	const int codRestaurant;
	string nume;
	int nrPreparate;
	float* preturiPreparate;

public:
	static int nrRestaurante;

	Restaurant() :codRestaurant(++nrRestaurante) {
		nume = " ";
		nrPreparate = 0;
		preturiPreparate = nullptr;

	}

	Restaurant(string nume, int nrPreparate, float* preturiPreparate) : codRestaurant(++nrRestaurante) {
		if (nume.length() > 0) {
			this->nume = nume;
		}

		if (nrPreparate > 0 && preturiPreparate != nullptr) {
			this->nrPreparate = nrPreparate;
			this->preturiPreparate = new float[nrPreparate];

			for (int i = 0; i < nrPreparate; i++) {
				this->preturiPreparate[i] = preturiPreparate[i];
			}
		}
		else {
			this->nrPreparate = 0;
			this->preturiPreparate = nullptr;
		}
	}

	Restaurant(const Restaurant& r) :codRestaurant(++nrRestaurante) {
		nume = r.nume;
		nrPreparate = r.nrPreparate;

		if (r.nrPreparate > 0 && r.preturiPreparate != nullptr) {
			preturiPreparate = new float[nrPreparate];

			for (int i = 0; i < nrPreparate; i++) {
				preturiPreparate[i] = r.preturiPreparate[i];
			}

		}
		else {
			preturiPreparate = nullptr;
		}


	}

	Restaurant& operator=(const Restaurant& r) {
		if (this != &r) {
			this->nume = r.nume;
			this->nrPreparate = r.nrPreparate;

			if (this->preturiPreparate != nullptr) {
				delete[]preturiPreparate;
				this->preturiPreparate = nullptr;
			}
			if (r.preturiPreparate != nullptr) {
				this->preturiPreparate = new float[this->nrPreparate];

				for (int i = 0; i < r.nrPreparate; i++) {
					this->preturiPreparate[i] = r.preturiPreparate[i];
				}
			}
			else {
				this->preturiPreparate = nullptr;
			}
		}

		return *this;

	}


	void afisare() {
		cout << "Codul este: " << codRestaurant << endl;
		cout << "Numele este: " << nume << endl;
		cout << "Numarul preparatelor este: " << nrPreparate << endl;
		cout << "Preturile sunt: ";
		for (int i = 0; i < nrPreparate;i++) {
			cout << preturiPreparate[i] << " ";
		}
		cout << endl;
	}


	string getNume() {
		return nume;
	}

	void setNume(string nume) {
		if (nume.length() > 0) {
			this->nume = nume;
		}
	}

	int getNrPreparate() {
		return nrPreparate;
	}

	int getNrRestaurant() {
		return nrRestaurante;
	}

	~Restaurant() {
		delete[] preturiPreparate;
		cout << "Destructorul a fost apelat";
	}

};

int Restaurant::nrRestaurante = 0;

int main() {

	float preturi[] = { 20, 40 };

	Restaurant r1("La Placinte", 2, preturi);
	Restaurant r2 = r1;
	r1.afisare();
	cout << endl;
	r2.afisare();
	Restaurant r3;

	r3 = r1;

	cout << endl;

	r1.getNrPreparate();
	r1.setNume("Bunica");
	r1.afisare();

	cout << endl;

	r3.afisare();

	cout << "Numarul restaurantelor este de: " << Restaurant::nrRestaurante << endl;


}