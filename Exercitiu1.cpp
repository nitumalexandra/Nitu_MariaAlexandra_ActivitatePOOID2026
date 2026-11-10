#include <iostream>
#include <cstring>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

class Masina {
private:
    const int id;
    float pret;
    char* tip;
    string denumire;

public:

    Masina() : id() {
        pret = 0;
        tip = nullptr;
        denumire = " ";
    }

    Masina(int id, float pret, const char* tip, string denumire) : id(id) {
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
};


int main() {


    Masina* m = new Masina(1, 1, "C", "Opel");
    m->afisareMasina();



    return 0;
}