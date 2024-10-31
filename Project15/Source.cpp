#include <iostream>
using namespace std;

class Flat {
    int ploshiyad;
    double price;
    char* addres;
public:
    Flat() :price(0), addres(nullptr), ploshiyad(0) {};
    Flat(const char* _addres, int _ploshiyad, double _price) :price(_price), ploshiyad(_ploshiyad) {
        addres = new char[strlen(_addres) + 1];
        strcpy_s(addres, strlen(_addres) + 1, _addres);
    };
    ~Flat() {
        delete[]addres;
    }
    Flat(const Flat& obj) {
        ploshiyad = obj.ploshiyad;
        price = obj.price;
        addres = new char[strlen(obj.addres) + 1];
        strcpy_s(addres, strlen(obj.addres) + 1, obj.addres);
    }
    Flat operator=(const Flat& obj) {
        if (this == &obj) {
            return*this;
        }
        if (addres != nullptr) {
            delete[]addres;
        }
        ploshiyad = obj.ploshiyad;
        price = obj.price;
        addres = new char[strlen(obj.addres) + 1];
        strcpy_s(addres, strlen(obj.addres) + 1, obj.addres);
        return *this;
    }
    bool operator==(const Flat& obj) {
        if (ploshiyad == obj.ploshiyad) {
            return true;
        }
        return false;
    }
    bool operator>(const Flat& obj) {
        if (price > obj.price) {
            return true;
        }
        return false;
    }
    void Print() {
        cout << addres << endl << price << endl << ploshiyad << endl;
    }
};
int main()
{
    Flat a("ценик будет стоить вам от", 125, 900);
    Flat b("ценик будет стоить вам от", 200, 1500);
    Flat c = a;
    Flat d("ценик будет стоить вам от", 100, 1100);
    d = b;
    a.Print();
}

