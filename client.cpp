#include "client.h"
#include <iostream>
#include <fstream>

Client::Client() : Persoana(), cantitate_achiz(0) {}

Client::Client(const std::string name, const std::string data_nastere, const int cod, const int cantitate_achiz)
            : Persoana(name, data_nastere, cod), cantitate_achiz(cantitate_achiz) {}

bool Client::operator==(const Client &rhs) const {
    return this->name == rhs.name && this->cod == rhs.cod && this->data_nastere == rhs.data_nastere &&
            this->cantitate_achiz == rhs.cantitate_achiz;
}

bool Client::operator!=(const Client &rhs) const {
    return !(rhs == *this);
}

Client &Client::operator=(const Client &rhs) {
    setName(rhs.name);
    setCod(rhs.cod);
    setDataNastere(rhs.data_nastere);
    setCantitate_Achiz(rhs.cantitate_achiz);
    return *this;
}

std::istream &operator>>(std::istream &is, Client &client) {
    std::cout << "\nNume=";
    is >> client.name;
    std::cout << "\nCod Client=";
    is >> client.cod;
    std::cout << "\nCantitate Achizitionata=";
    is >> client.cantitate_achiz;
    std::cout << "\nData Nastere=";
    is >> client.data_nastere;
    return is;
}

std::ostream &operator<<(std::ostream &os, const Client &client) {
    if (!client.cod) {
        os << "Client Neinitializat\n";
        return os;
    }
    os << "cod_client: " << client.cod << "\tname: " << client.name << "\tdata_nastere: " << client.data_nastere
       << "\tcantitate_achiz: " << client.cantitate_achiz << "\n";
    return os;
}

std::ifstream &operator>>(std::ifstream &ifstr, Client &client) {
    ifstr >> client.name >> client.cantitate_achiz >> client.cod >> client.data_nastere;
    return ifstr;
}

std::string &Client::getDataAngajare() {
    return data_nastere;
}

int Client::getCantitateAchiz() const {
    return cantitate_achiz;
}

void Client::setCantitate_Achiz(const int cantitate_achiz) {
    Client::cantitate_achiz = cantitate_achiz;
}

Client::~Client() = default;
