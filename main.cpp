#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

char fisierAngajati[75] = "C:\\Users\\Dell\\Documents\\GitHub\\oop-lab\\fisierAngajati.in";
char fisierVanzari[75] = "C:\\Users\\Dell\\Documents\\GitHub\\oop-lab\\fisierVanzari.in";



class Angajat {
    int cod_angajat;
    char *name;
public:
    // constructor
    Angajat(char *name_, int cod_angajat_) {
        this->name = new char[strlen(name_) + 1];
        strcpy(this->name, name_);
        this->cod_angajat = cod_angajat_;
    }
    // constructor default
    Angajat() {
        this->name = new char[10];
        strcpy(this->name, "nedefinit");
        this->cod_angajat = 0;
    }
    // constructor copiere
    Angajat(const Angajat &stud) {
        this->name = new char[strlen(stud.name)];
        strcpy(this->name, stud.name);
        this->cod_angajat = stud.cod_angajat;
    }

    void setName(const char *name_) {
        delete[] this->name;
        this->name = new char[strlen(name_) + 1];
        strcpy(this->name, name_);
    }
    void setCodAngajat(int cod_angajat_) {
        this->cod_angajat = cod_angajat_;
    }
    char *getName() const {
        return this->name;
    }
    int getCodAngajat() const {
        return this->cod_angajat;
    }

    bool operator==(const Angajat &rhs) const {
        return strcmp(this->name, rhs.name) == 0 && this->cod_angajat == rhs.cod_angajat;
    }
    bool operator!=(const Angajat &rhs) const {
        return !(rhs == *this);
    }
    Angajat &operator=(const Angajat &rhs) {
        if (this != &rhs)
            setName(rhs.name);
        this->cod_angajat = rhs.cod_angajat;

        return *this;
    }

    friend std::istream &operator>>(std::istream &is, Angajat &angajat) {
        char buf[50];
        cout << "\nNume=";
        is >> buf;
        angajat.setName(buf);
        cout << "\nCod Angajat=";
        is >> angajat.cod_angajat;
        return is;
    }
    friend ostream &operator<<(ostream &os, const Angajat &angajat) {
        if (!angajat.name) {
            os << "Angajat Neinitializat\n";
            return os;
        }
        os << "cod_angajat: " << angajat.cod_angajat << " name: " << angajat.name << "\n";
        return os;
    }

    friend std::ifstream &operator>>(std::ifstream &ifstr, Angajat &angajat) {
        char buf[50];
        ifstr >> buf;
        angajat.setName(buf);
        ifstr >> angajat.cod_angajat;
        return ifstr;
    }

    // destructor
    ~Angajat() {
        delete[] this->name;
    }
};

class Vanzari {
    int id_vanzare, cod_angajat;
    double pret;
    char *produs;
public:
    // constructor
    Vanzari(char *produs_, int id_vanzare_, int cod_angajat_, double pret_) {
        this->produs = new char[strlen(produs_) + 1];
        strcpy(this->produs, produs_);
        this->id_vanzare = id_vanzare_;
        this->cod_angajat = cod_angajat_;
        this->pret = pret_;
    }
    // constructor default
    Vanzari() {
        this->produs = new char[10];
        strcpy(this->produs, "nedefinit");
        this->id_vanzare = 0;
        this->cod_angajat = 0;
        this->pret = 0.0;
    }
    // constructor copiere
    Vanzari(const Vanzari &stud) {
        this->produs = new char[strlen(stud.produs)];
        strcpy(this->produs, stud.produs);
        this->id_vanzare = stud.id_vanzare;
        this->cod_angajat = stud.cod_angajat;
        this->pret = stud.pret;
    }

    void setProdus(const char *produs_) {
        delete[] this->produs;
        this->produs = new char[strlen(produs_) + 1];
        strcpy(this->produs, produs_);
    }
    void setIdVanzare(int id_vanzare_) {
        this->id_vanzare = id_vanzare_;
    }
    void setCodAngajat(int cod_angajat_) {
        this->cod_angajat = cod_angajat_;
    }
    void setPret(double pret_) {
        this->pret = pret_;
    }
    char *getProdus() const {
        return this->produs;
    }
    int getIdVanzare() const {
        return this->id_vanzare;
    }
    int getCodAngajat() const {
        return this->cod_angajat;
    }
    double getPret() const {
        return this->pret;
    }

    bool operator==(const Vanzari &rhs) const {
        return strcmp(this->produs, rhs.produs) == 0 && this->id_vanzare == rhs.id_vanzare
        && this->cod_angajat == cod_angajat && this->pret == rhs.pret;
    }
    bool operator!=(const Vanzari &rhs) const {
        return !(rhs == *this);
    }
    Vanzari &operator=(const Vanzari &rhs) {
        if (this != &rhs)
            setProdus(rhs.produs);
        this->id_vanzare = rhs.id_vanzare;
        this->cod_angajat = rhs.cod_angajat;
        this->pret = rhs.pret;

        return *this;
    }

    friend std::istream &operator>>(std::istream &is, Vanzari &vanzare) {
        char buf[50];
        cout << "\nProdus=";
        is >> buf;
        vanzare.setProdus(buf);
        cout << "\nID Vanzare=";
        is >> vanzare.id_vanzare;
        cout << "\nCod Angajat=";
        is >> vanzare.cod_angajat;
        cout << "\nPret=";
        is >> vanzare.pret;
        return is;
    }
    friend ostream &operator<<(ostream &os, const Vanzari &vanzare) {
        if (!vanzare.produs) {
            os << "Vanzare Neinitializata\n";
            return os;
        }
        os << "id_vanzare: " << vanzare.id_vanzare << " produs: " << vanzare.produs << " cod_angajat: "
        << vanzare.cod_angajat << " pret: " << vanzare.pret << "\n";
        return os;
    }

    friend std::ifstream &operator>>(std::ifstream &ifstr, Vanzari &vanzare) {
        char buf[50];
        ifstr >> buf;
        vanzare.setProdus(buf);
        ifstr >> vanzare.id_vanzare >> vanzare.cod_angajat >> vanzare.pret;
        return ifstr;
    }

    // destructor
    ~Vanzari() {
        delete[] this->produs;
    }
};

void afisareAngajati(int nr_angajati, Angajat *lista_angajati) {
    for (int i = 0; i < nr_angajati; i++)
        cout << lista_angajati[i];
}

Angajat *adaugareAngajati(int &nr_angajati, Angajat *lista_angajati) {
    ifstream fin(fisierAngajati);
    int nr_angajati_de_adaugat;
    fin >> nr_angajati_de_adaugat;

    nr_angajati += nr_angajati_de_adaugat;
    Angajat *tmp = new Angajat[nr_angajati];
    for (int i = 0; i < nr_angajati - nr_angajati_de_adaugat; i++) {
        tmp[i] = lista_angajati[i];
    }
    delete[] lista_angajati;
    lista_angajati = tmp;
    for (int i = nr_angajati - nr_angajati_de_adaugat; i < nr_angajati; i++) {
        fin >> lista_angajati[i];
    }
    return lista_angajati;
}

Angajat *stergeAngajat(int &nr_angajati, Angajat *lista_angajati) {
    int pos = -1, cod_angajat_;
    cout << "Cod angajat de sters=";
    cin >> cod_angajat_;
    for (int i = 0; i < nr_angajati; i++) {
        if (lista_angajati[i].getCodAngajat() == cod_angajat_) {
            pos = i;
            break;
        }
    }
    if (pos != -1 and cod_angajat_ != 0) {
        nr_angajati--;
        Angajat *tmp = new Angajat[nr_angajati];
        for (int i = 0; i < pos; i++) {
            tmp[i] = lista_angajati[i];
        }
        for (int i = pos; i < nr_angajati; i++) {
            tmp[i] = lista_angajati[i + 1];
        }
        delete[] lista_angajati;
        lista_angajati = tmp;
    }
    else {
        cout << "Cod angajat invalid\n";
    }
    return lista_angajati;
}

void afisareVanzari(int nr_vanzari, Vanzari *lista_vanzari) {
    for (int i = 0; i < nr_vanzari; i++)
        cout << lista_vanzari[i];
}

Vanzari *adaugareVanzari(int &nr_vanzari, Vanzari *lista_vanzari) {
    ifstream fin(fisierVanzari);
    int nr_vanzari_de_adaugat;
    fin >> nr_vanzari_de_adaugat;

    nr_vanzari += nr_vanzari_de_adaugat;
    Vanzari *tmp = new Vanzari[nr_vanzari];
    for (int i = 0; i < nr_vanzari - nr_vanzari_de_adaugat; i++) {
        tmp[i] = lista_vanzari[i];
    }
    delete[] lista_vanzari;
    lista_vanzari = tmp;
    for (int i = nr_vanzari - nr_vanzari_de_adaugat; i < nr_vanzari; i++) {
        fin >> lista_vanzari[i];
    }
    return lista_vanzari;
}

Vanzari *stergeVanzare(int &nr_vanzari, Vanzari *lista_vanzari) {
    int pos = -1, id_vanzare_;
    cout << "ID Vanzare de sters=";
    cin >> id_vanzare_;
    for (int i = 0; i < nr_vanzari; i++) {
        if (lista_vanzari[i].getIdVanzare() == id_vanzare_) {
            pos = i;
            break;
        }
    }
    if (pos != -1 and id_vanzare_ != 0) {
        nr_vanzari--;
        Vanzari *tmp = new Vanzari[nr_vanzari];
        for (int i = 0; i < pos; i++) {
            tmp[i] = lista_vanzari[i];
        }
        for (int i = pos; i < nr_vanzari; i++) {
            tmp[i] = lista_vanzari[i + 1];
        }
        delete[] lista_vanzari;
        lista_vanzari = tmp;
    }
    else {
        cout << "ID Vanzare invalid\n";
    }
    return lista_vanzari;
}

void getVanzariByAngajat(Angajat *lista_angajati, Vanzari *lista_vanzari, int nr_angajati, int nr_vanzari) {
    int pos = -1, cod_angajat_;
    cout << "Cod angajat de cautat=";
    cin >> cod_angajat_;
    for (int i = 0; i < nr_angajati; i++) {
        if (lista_angajati[i].getCodAngajat() == cod_angajat_) {
            pos = i;
            break;
        }
    }
    if (pos != -1 and cod_angajat_ != 0) {
        for (int i = 0; i < nr_vanzari; i++) {
            if (lista_vanzari[i].getCodAngajat() == lista_angajati[pos].getCodAngajat()) {
                cout << lista_vanzari[i] << "\n";
            }
        }
    }
    else {
        cout << "Cod angajat invalid\n";
    }
}

int main() {

    // initializare
    int nr_angajati = 1;
    int nr_vanzari = 1;
    Angajat *lista_angajati = new Angajat[nr_angajati];
    Vanzari *lista_vanzari = new Vanzari[nr_vanzari];


    int alegere = 1;
    while (alegere >= 1 and alegere <= 99) {
        cout << "\n0-Iesire program\n"
                "1-Afisare angajati\n2-Adaugare Angajati din Fisier\n3-Sterge Angajat\n"
                "4-Afisare vanzari\n5-Adaugare Vanzari din Fisier\n6-Sterge Vanzare\n"
                "7-Afisare Vanzari pentru un Angajat"
                "\nAlegere=";
        cin >> alegere;

        switch (alegere) {
            default:
                cout << "\n\nAlegere invalida!\n";
                break;
            case 0:
                break;
            case 1:
                afisareAngajati(nr_angajati, lista_angajati);
                break;
            case 2:
                lista_angajati = adaugareAngajati(nr_angajati, lista_angajati);
                break;
            case 3:
                lista_angajati = stergeAngajat(nr_angajati, lista_angajati);
                break;
            case 4:
                afisareVanzari(nr_vanzari, lista_vanzari);
                break;
            case 5:
                lista_vanzari = adaugareVanzari(nr_vanzari, lista_vanzari);
                break;
            case 6:
                lista_vanzari = stergeVanzare(nr_vanzari, lista_vanzari);
                break;
            case 7:
                getVanzariByAngajat(lista_angajati, lista_vanzari, nr_angajati, nr_vanzari);
                break;
        }
    }

    delete[] lista_angajati;

    return 0;
}
