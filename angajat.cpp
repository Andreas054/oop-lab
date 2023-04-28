#include "angajat.h"
#include <iostream>
#include <fstream>

Angajat::Angajat() : Persoana(), data_angajare("01-01-2000") {
    ++nr_angajati;
}

Angajat::Angajat(const std::string name, const std::string data_nastere, const int cod, const std::string data_angajare)
            : Persoana(name, data_nastere, cod), data_angajare(data_angajare) {
    ++nr_angajati;
}

bool Angajat::operator==(const Angajat &rhs) const {
    return this->name == rhs.name && this->cod == rhs.cod && this->data_nastere == rhs.data_nastere && this->data_angajare == rhs.data_angajare;
}

bool Angajat::operator!=(const Angajat &rhs) const {
    return !(rhs == *this);
}

Angajat &Angajat::operator=(const Angajat &rhs) {
    setName(rhs.name);
    setCod(rhs.cod);
    setDataNastere(rhs.data_nastere);
    setDataAngajare(rhs.data_angajare);
    return *this;
}

std::istream &operator>>(std::istream &is, Angajat &angajat) {
    std::cout << "\nNume=";
    is >> angajat.name;
    std::cout << "\nCod Angajat=";
    is >> angajat.cod;
    std::cout << "\nData Nastere=";
    is >> angajat.data_nastere;
    std::cout << "\nData Angajare=";
    is >> angajat.data_angajare;
    return is;
}

std::ostream &operator<<(std::ostream &os, const Angajat &angajat) {
    if (!angajat.cod) {
        os << "Angajat Neinitializat\n";
        return os;
    }
    os << "cod_angajat: " << angajat.cod << "\tname: " << angajat.name << "\tdata_nastere: " << angajat.data_nastere
            << "\tdata_angajare: " << angajat.data_angajare << "\n";
    return os;
}

std::ifstream &operator>>(std::ifstream &ifstr, Angajat &angajat) {
    ifstr >> angajat.name >> angajat.data_angajare >> angajat.cod >> angajat.data_nastere;
    return ifstr;
}

std::string &Angajat::getDataAngajare() {
    return data_angajare;
}

void Angajat::setDataAngajare(std::string data_angajare) {
    Angajat::data_angajare = data_angajare;
}

void Angajat::decNrAng() {
    nr_angajati--;
}

int Angajat::getNrAngajati() {
    return nr_angajati;
}

Angajat::~Angajat() = default;
