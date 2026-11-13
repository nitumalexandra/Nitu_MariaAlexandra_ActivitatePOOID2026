#include <iostream>
#include <cstring>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

class Masina {
private:
    const int id; //get
    float pret;//get
    char* tip;
    string denumire; //get set

public:
    static int nrMasina;
    Masina() : id(++nrMasina) {
        pret = 0;
        tip = nullptr;
        denumire = " ";
    }

    Masina(int id, float pret, const char* tip, string denumire) : id(id) {
        nrMasina++;
        this->pret = pret;
        this->denumire = denumire;
        if (tip != nullptr) {
            this->tip = new char[strlen(tip) + 1];
            strcpy_s(this->tip, strlen(tip) + 1, tip);
        }
        else {
            this->tip = nullptr;
        }
    }

    //get si set
    int getId() {
        return this->id;
    }

    float getPret() {
        return this->pret;
    }

    string getDenumire() {
        return this->denumire;
    }

    void setDenumire(string denumireNoua) {
        if (denumireNoua.length() > 0) {
            this->denumire = denumireNoua;
        }
        else {
            cout << "Denumire falsa" << endl;
        }
    }

    void afisareMasina() {
        cout << id << " ";
        cout << pret << " ";
        cout << denumire << " ";
        if (tip != nullptr) {
            cout << tip;
        }
        else {
            cout << "nu exista tip masina";
        }

    }

    ~Masina() {
        cout << endl << "s-a apelat destructorul";
        if (this->tip != nullptr) {
            delete[] this->tip;
        }
    }
};

int Masina::nrMasina = 0;

int main() {
    Masina m1 = Masina(1, 1.4, "C ", "Opel ");
    Masina m2 = Masina(6, 5.7, "D ", "Mercedes ");
    m1.afisareMasina();
    m2.afisareMasina();
    cout << endl;
    cout << m1.getDenumire() << endl;
    m1.setDenumire("BMW");
    cout << m1.getDenumire() << endl;
    cout << endl << "Numarul de masini este " << Masina::nrMasina;



    return 0;
}
