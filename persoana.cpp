#include "persoana.h"

Persoana::Persoana() : name("nedefinit"), data_nastere("01-01-1900"), cod(0) {}

Persoana::Persoana(const std::string &name, const std::string &data_nastere, const int cod) : name(name), data_nastere(data_nastere), cod(cod) {}

const std::string &Persoana::getName() const {
    return name;
}

const std::string &Persoana::getDataNastere() const {
    return data_nastere;
}

int Persoana::getCod() const {
    return cod;
}

void Persoana::setName(const std::string &name_) {
    Persoana::name = name_;
}

void Persoana::setDataNastere(const std::string &data_nastere_) {
    Persoana::data_nastere = data_nastere_;
}

void Persoana::setCod(int cod_) {
    Persoana::cod = cod_;
}

Persoana::~Persoana() = default;
