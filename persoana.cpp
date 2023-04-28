#include "persoana.h"

Persoana::Persoana() : name("nedefinit"), data_nastere("01-01-1900"), cod(0) {}

Persoana::Persoana(std::string name, std::string data_nastere, int cod) : name(name), data_nastere(data_nastere), cod(cod) {}

const std::string &Persoana::getName() const {
    return name;
}

const std::string &Persoana::getDataNastere() const {
    return data_nastere;
}

int Persoana::getCod() const {
    return cod;
}

void Persoana::setName(const std::string &name) {
    Persoana::name = name;
}

void Persoana::setDataNastere(const std::string &data_nastere) {
    Persoana::data_nastere = data_nastere;
}

void Persoana::setCod(int cod) {
    Persoana::cod = cod;
}

Persoana::~Persoana() = default;
