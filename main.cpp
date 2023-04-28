#include <string>
#include <vector>
#include <memory>
#include "meniu.h"
#include "angajat.h"
#include "client.h"
#include "vanzari.h"

//std::string fisierAngajati = "C:\\Users\\DelMX\\Documents\\GitHub\\oop-lab\\fisierAngajati.in";
//std::string fisierClienti = "C:\\Users\\DelMX\\Documents\\GitHub\\oop-lab\\fisierClienti.in";
//std::string fisierVanzari = "C:\\Users\\DelMX\\Documents\\GitHub\\oop-lab\\fisierVanzari.in";

std::string fisierAngajati = "C:\\Users\\Dell\\CLionProjects\\oop-lab\\fisierAngajati.in";
std::string fisierClienti = "C:\\Users\\Dell\\CLionProjects\\oop-lab\\fisierClienti.in";
std::string fisierVanzari = "C:\\Users\\Dell\\CLionProjects\\oop-lab\\fisierVanzari.in";

int Angajat::nr_angajati = 0;

int main() {
    // initializare
    std::vector<std::shared_ptr<Angajat>> lista_angajati;
    std::vector<std::shared_ptr<Client>> lista_clienti;
    std::vector<std::shared_ptr<Vanzari>> lista_vanzari;

    {
        Angajat tmp("nedefinit", "01-01-1900", 0, "01-01-1900");
        lista_angajati.push_back(std::make_shared<Angajat>(tmp));
    }

    meniu(lista_angajati, lista_clienti, lista_vanzari, fisierAngajati, fisierClienti, fisierVanzari );

    return 0;
}
