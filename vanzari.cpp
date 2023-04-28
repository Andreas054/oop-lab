#include "vanzari.h"
#include <iostream>
#include <fstream>

Vanzari::Vanzari() : name("nedefinit"), cod_persoana(0), id(0), pret(0.0) {}

Vanzari::Vanzari(const std::string &name, const int cod_persoana, const int id, const double pret) : name(name), cod_persoana(cod_persoana), id(id), pret(pret) {}

const std::string &Vanzari::getName() const {
    return name;
}

int Vanzari::getCod_persoana() const {
    return cod_persoana;
}

int Vanzari::getIdVanzare() const {
    return id;
}

double Vanzari::getPret() const {
    return pret;
}

void Vanzari::setName(const std::string &name_) {
    Vanzari::name = name_;
}

void Vanzari::setCod_persoana(int cod_persoana_) {
    Vanzari::cod_persoana = cod_persoana_;
}

void Vanzari::setId(int id_) {
    Vanzari::id = id_;
}

void Vanzari::setPret(double pret_) {
    Vanzari::pret = pret_;
}

bool Vanzari::operator==(const Vanzari &rhs) const {
    return this->name == rhs.name && this->cod_persoana == rhs.cod_persoana && this->id == rhs.id && this->pret == rhs.pret;
}

bool Vanzari::operator!=(const Vanzari &rhs) const {
    return !(rhs == *this);
}

Vanzari &Vanzari::operator=(const Vanzari &rhs) {
    setName(rhs.name);
    setCod_persoana(rhs.cod_persoana);
    setId(rhs.id);
    setPret(rhs.pret);
    return *this;
}

std::istream &operator>>(std::istream &is, Vanzari &vanzare) {
    std::string buf;
    std::cout << "\nProdus=";
    is >> buf;
    vanzare.setName(buf);
    std::cout << "\nID Vanzare=";
    is >> vanzare.id;
    std::cout << "\nCod Angajat=";
    is >> vanzare.cod_persoana;
    std::cout << "\nPret=";
    is >> vanzare.pret;
    return is;
}

std::ostream &operator<<(std::ostream &os, const Vanzari &vanzare) {
    if (!vanzare.id) {
        os << "Vanzare Neinitializata\n";
        return os;
    }
    os << "id_vanzare: " << vanzare.id << "\t\tprodus: " << vanzare.name << "\t\tcod_angajat: "
       << vanzare.cod_persoana << "\t\tpret: " << vanzare.pret << "\n";
    return os;
}

std::ifstream &operator>>(std::ifstream &ifstr, Vanzari &vanzare) {
    ifstr >> vanzare.name >> vanzare.id >> vanzare.cod_persoana >> vanzare.pret;
    return ifstr;
}

Vanzari::~Vanzari() = default;