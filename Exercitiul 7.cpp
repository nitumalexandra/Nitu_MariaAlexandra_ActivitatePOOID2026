#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <cstring>
#include<string>
using namespace std;

class Cofetarie {
private:
	const int codCofetarie;
	char* nume;
	int nrAngajati;
	float profitAnual;

public:
	static int nrCofetarii;

	Cofetarie() :codCofetarie(++nrCofetarii) {
		nume = new char[strlen("Necunoscut") + 1];
		strcpy(nume, "Necunoscut");

		nrAngajati = 0;
		profitAnual = 0;

	}

	Cofetarie(const char* nume, int nrAngajati, float profitAnual) :codCofetarie(++nrCofetarii) {

		if (nume != nullptr && strlen(nume) > 0) {
			this->nume = new char[strlen(nume) + 1];
			strcpy(this->nume, nume);
		}
		else {
			this->nume = new char[strlen("Necunoscut") + 1];
			strcpy(this->nume, "Necunoscut");
		}

		if (nrAngajati >= 0) {
			this->nrAngajati = nrAngajati;
		}
		else {
			this->nrAngajati = 0;
		}

		if (profitAnual >= 0) {
			this->profitAnual = profitAnual;
		}
		else {
			this->profitAnual = 0;
		}

	}

	Cofetarie(const Cofetarie& c) :codCofetarie(++nrCofetarii) {
		nume = new char[strlen(c.nume) + 1];
		strcpy(nume, c.nume);

		nrAngajati = c.nrAngajati;
		profitAnual = c.profitAnual;

	}

	const char* getNume() {
		return nume;
	}

	void setNume(const char* nume) {
		if (nume != nullptr && strlen(nume) > 0) {
			char* c = new char[strlen(nume) + 1];
			strcpy(c, nume);

			delete[] this->nume;
			this->nume = c;
		}
	}

	Cofetarie& operator=(const Cofetarie& c) {
		if (this != &c) {

			char* numeNou = new char[strlen(c.nume) + 1];
			strcpy(numeNou, c.nume);

			if (this->nume != nullptr) {
				delete[] this->nume;
				this->nume = nullptr;
			}

			this->nume = numeNou;
			this->nrAngajati = c.nrAngajati;
			this->profitAnual = c.profitAnual;
		}

		return *this;
	}


	void afisare() {
		cout << "Cod cofetarie: " << codCofetarie << endl;
		cout << "Nume: " << nume << endl;
		cout << "Numar angajati: " << nrAngajati << endl;
		cout << "Profit anual: " << profitAnual << endl;
	}

	~Cofetarie() {
		delete[] nume;
	}





};

int Cofetarie::nrCofetarii = 0;


int main() {

	Cofetarie c1("Paul", 10, 20.6);
	c1.afisare();
	cout << endl;

	Cofetarie c2;
	c2 = c1;
	c2.afisare();

	cout << endl;

	Cofetarie c3 = c1;
	c3.afisare();
	cout << endl;


	return 0;

}