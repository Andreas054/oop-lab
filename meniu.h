#ifndef _MENIU_H_
#define _MENIU_H_

#include <iostream>
#include "angajat.h"
#include "client.h"
#include "vanzari.h"
#include "functii.h"

void meniu(std::vector<std::shared_ptr<Angajat>> &lista_angajati, std::vector<std::shared_ptr<Client>> &lista_clienti, std::vector<std::shared_ptr<Vanzari>> &lista_vanzari,
           const std::string &fisierAngajati, const std::string &fisierClienti, const std::string &fisierVanzari) {
    int alegere = 1;

    while (alegere) {
        std::cout << "\n0-Iesire program\n"
                     "1-Afisare Angajati\t2-Adaugare Angajati din Fisier\t3-Sterge Angajat\n"
                     "4-Afisare Clienti\t5-Adaugare Clienti din Fisier\t6-Sterge Client\n"
                     "7-Afisare Vanzari\t8-Adaugare Vanzari din Fisier\t9-Sterge Vanzare\n"
                     "10-Afisare numar Angajati\t11-Afisare numar Clienti\n"
                     "12-Afisare Vanzari pentru un Angajat\n13-Afisare data angajare pentru un Angajat\n"
                     "14-Afisare date implicite Angajat\n"
                     "\nAlegere=";
        std::cin >> alegere;

        switch (alegere) {
            default:
                std::cout << "\n\nAlegere invalida!\n";
                break;
            case 0:
                break;
            case 1:
                afisareAngajati(lista_angajati);
                break;
            case 2:
                adaugareAngajati(lista_angajati, fisierAngajati);
                break;
            case 3:
                try {
                    stergeAngajat(lista_angajati, lista_vanzari);
                }
                catch (const CodAngajatAsociatException &e) {
                    std::cout << e.what() << "\n";
                }
                break;
            case 4:
                afisareClienti(lista_clienti);
                break;
            case 5:
                adaugareClienti(lista_clienti, fisierClienti);
                break;
            case 6:
                try {
                    stergeClient(lista_clienti);
                }
                catch (const CodClientInexistentException &e) {
                    std::cout << e.what() << "\n";
                }
                break;
            case 7:
                afisareVanzari(lista_vanzari);
                break;
            case 8:
                adaugareVanzari(lista_vanzari, fisierVanzari);
                break;
            case 9:
                stergeVanzare(lista_vanzari);
                break;
            case 10:
                afisareNrAngajati();
                break;
            case 11:
                afisareNrClienti();
                break;
            case 12:
                getVanzariByAngajat(lista_angajati, lista_vanzari);
                break;
            case 13:
                getDataAngByAngajat(lista_angajati);
                break;
            case 14:
                afisareDateDefaultAngajat();
                break;
        }
    }
}

#endif