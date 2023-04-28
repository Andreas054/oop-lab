#ifndef _FUNCTII_H_
#define _FUNCTII_H_

#include <fstream>
#include "exceptii.h"

void afisareAngajati(const std::vector<std::shared_ptr<Angajat>> lista_angajati) {
    for (auto &ptr : lista_angajati) {
        std::cout << *ptr;
    }
}

void adaugareAngajati(std::vector<std::shared_ptr<Angajat>> &lista_angajati, std::string fisierAngajati) {
    std::ifstream fin(fisierAngajati);
    int nr_angajati_de_adaugat;
    fin >> nr_angajati_de_adaugat;

    for (int i = 0; i < nr_angajati_de_adaugat; ++i) {
        Angajat tmp;
        fin >> tmp;
        lista_angajati.push_back(std::make_shared<Angajat>(tmp));
    }
}

void stergeAngajat(std::vector<std::shared_ptr<Angajat>> &lista_angajati, std::vector<std::shared_ptr<Vanzari>> lista_vanzari) {
    int cod_;
    std::cout << "Cod angajat de sters=";
    std::cin >> cod_;

    auto i = lista_angajati.begin();
    for (i = lista_angajati.begin(); i != lista_angajati.end(); ++i) {
        if ((*i)->getCod() == cod_) {
            break;
        }
    }

    if (i != lista_angajati.end() and cod_ != 0) {
        auto j = lista_vanzari.begin();
        for (j = lista_vanzari.begin(); j != lista_vanzari.end(); ++j) {
            if ((*j)->getCod_persoana() == (*i)->getCod())
                break;
        }
        if (j != lista_vanzari.end()) {
            throw CodAngajatAsociatException();
        } else {
            (*i)->decNrAng();
            lista_angajati.erase(i);
        }
    } else {
        std::cout << "Cod angajat invalid!\n";
    }
}

void afisareClienti(const std::vector<std::shared_ptr<Client>> lista_clienti) {
    for (auto &ptr : lista_clienti) {
        std::cout << *ptr;
    }
}

void adaugareClienti(std::vector<std::shared_ptr<Client>> &lista_clienti, std::string fisierClienti) {
    std::ifstream fin(fisierClienti);
    int nr_clienti_de_adaugat;
    fin >> nr_clienti_de_adaugat;

    for (int i = 0; i < nr_clienti_de_adaugat; ++i) {
        Client tmp;
        fin >> tmp;
        lista_clienti.push_back(std::make_shared<Client>(tmp));
    }
}

void stergeClient(std::vector<std::shared_ptr<Client>> &lista_clienti) {
    int cod_;
    std::cout << "Cod client de sters=";
    std::cin >> cod_;

    auto i = lista_clienti.begin();
    for (i = lista_clienti.begin(); i != lista_clienti.end(); ++i) {
        if ((*i)->getCod() == cod_) {
            break;
        }
    }

    if (i != lista_clienti.end() and cod_ != 0) {
        lista_clienti.erase(i);
    }
    else {
        throw CodClientInexistentException();
    }
}

void afisareVanzari(const std::vector<std::shared_ptr<Vanzari>> lista_vanzari) {
    for (auto &ptr : lista_vanzari) {
        std::cout << *ptr;
    }
}

void adaugareVanzari(std::vector<std::shared_ptr<Vanzari>> &lista_vanzari, std::string fisierVanzari) {
    std::ifstream fin(fisierVanzari);
    int nr_vanzari_de_adaugat;
    fin >> nr_vanzari_de_adaugat;

    for (int i = 0; i < nr_vanzari_de_adaugat; ++i) {
        Vanzari tmp;
        fin >> tmp;
        lista_vanzari.push_back(std::make_shared<Vanzari>(tmp));
    }
}

void stergeVanzare(std::vector<std::shared_ptr<Vanzari>> &lista_vanzari) {
    int id_vanzare_;
    std::cout << "ID Vanzare de sters=";
    std::cin >> id_vanzare_;

    auto i = lista_vanzari.begin();
    for (i = lista_vanzari.begin(); i != lista_vanzari.end(); ++i) {
        if ((*i)->getIdVanzare() == id_vanzare_) {
            break;
        }
    }

    if (i != lista_vanzari.end() and id_vanzare_ != 0) {
        lista_vanzari.erase(i);
    }
    else {
        std::cout << "ID Vanzare invalid!\n";
    }
}

void getVanzariByAngajat(std::vector<std::shared_ptr<Angajat>> lista_angajati, const std::vector<std::shared_ptr<Vanzari>> lista_vanzari) {
    int cod_;
    std::cout << "Cod angajat de cautat=";
    std::cin >> cod_;

    auto i = lista_angajati.begin();
    for (i = lista_angajati.begin(); i != lista_angajati.end(); ++i) {
        if ((*i)->getCod() == cod_) {
            break;
        }
    }
    if (i != lista_angajati.end() and cod_ != 0) {
        double suma = 0.0;
        for (auto j = lista_vanzari.begin(); j != lista_vanzari.end(); ++j) {
            if ((*j)->getCod_persoana() == (*i)->getCod()) {
                std::cout << **j;
                suma += (*j)->getPret();
            }
        }
        std::cout << "Suma totala=" << suma << "\n";
    }
    else {
        std::cout << "Cod angajat invalid!\n";
    }
}

void getDataAngByAngajat(std::vector<std::shared_ptr<Angajat>> lista_angajati) {
    int cod_;
    std::cout << "Cod angajat de cautat=";
    std::cin >> cod_;

    auto i = lista_angajati.begin();
    for (i = lista_angajati.begin(); i != lista_angajati.end(); ++i) {
        if ((*i)->getCod() == cod_) {
            break;
        }
    }
    if (i != lista_angajati.end() and cod_ != 0) {
        std::cout << (*i)->getDataAngajare();
    }
    else {
        std::cout << "Cod angajat invalid!\n";
    }
}

void afisareNrAngajati() {
    std::cout << "\nNumarul de angajati este: " << Angajat::getNrAngajati() << "\n";
}

void afisareDateDefaultAngajat() {
    // functii virtuale (pure) apelate prin pointeri de clasa baza
    Persoana *pers = new Angajat;
    std::cout << "cod_angajat: " << pers->getCod() << "\n";
    std::cout << "name: " << pers->getName() << "\n";
    std::cout << "data_nastere: " << pers->getDataNastere() << "\n";
    std::cout << "data_angajare: " << pers->getDataAngajare() << "\n";

    // dynamic_cast
    Angajat *ang = dynamic_cast<Angajat*>(pers);
    ang->decNrAng();
    delete pers;
}

#endif