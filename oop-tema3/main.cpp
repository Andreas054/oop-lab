#include <iostream>
#include <string>
#include <vector>
#include <memory>

struct data {
    int d, m, y;
};

class DataInvalidaAdult : public std::exception {
public:
    DataInvalidaAdult() = default;

    const char* what() const noexcept override  {
        return "Adultul nu poate avea sub 18 ani!";
    }
};

class DataInvalidaCopil : public std::exception {
public:
    DataInvalidaCopil() = default;

    const char* what() const noexcept override  {
        return "Copilul nu poate avea peste 18 ani!";
    }
};

class PrintStream {
public:
    virtual void Print(std::ostream&) const = 0;

    friend std::ostream& operator<<(std::ostream&, const PrintStream&);

    virtual ~PrintStream();
};

std::ostream& operator<<(std::ostream& os, const PrintStream& obj) {
    obj.Print(os);
    return os;
}

PrintStream::~PrintStream() = default;

template<typename T>
class GenerareCodCopil {
    inline static int last_id;

    const std::string id_persoana;
public:
    GenerareCodCopil() : id_persoana("C" + std::to_string(++last_id)){}

    const std::string getId_Persoana() const {
        return id_persoana;
    }
};

class Baiat;
class Fata;

template<>
GenerareCodCopil<Baiat>::GenerareCodCopil() : id_persoana("B" + std::to_string(++last_id)) {};

template<>
GenerareCodCopil<Fata>::GenerareCodCopil() : id_persoana("F" + std::to_string(++last_id)) {};

enum class CategoriePersoana {
    Adult,
    Copil
};

template<CategoriePersoana T>
class Persoana : public PrintStream {
protected:
    std::string name;
    data data_nastere;
public:
    Persoana();

    Persoana(const std::string &name, const data &data_nastere);

    void Print(std::ostream &ostream) const override;

    const std::string &getName() const;

    const data &getDataNastere() const;

    void setName(const std::string &name);

    void setDataNastere(const data &data_nastere);

    virtual ~Persoana();
};

template<CategoriePersoana T>
Persoana<T>::Persoana() : name("nedefinit"), data_nastere({01, 01, 1900}) {}

template<CategoriePersoana T>
Persoana<T>::Persoana(const std::string &name, const data &data_nastere)
    : name(name), data_nastere(data_nastere) {
        if (T == CategoriePersoana::Copil) {
            if (data_nastere.y <= 2005) {
                throw DataInvalidaCopil();
            }
        }
        else {
            if (data_nastere.y > 2005) {
                throw DataInvalidaAdult();
            }
        }
    }

template<>
void Persoana<CategoriePersoana::Adult>::Print(std::ostream &os) const {
    os << "\nAdult";
    os << "\nNume: " << name << "\nData Nasterii: " << data_nastere.d << "." << data_nastere.m << "." << data_nastere.y;
}

template<>
void Persoana<CategoriePersoana::Copil>::Print(std::ostream &os) const {
    os << "\tCopil";
    os << "\nNume: " << name << "\nData Nasterii: " << data_nastere.d << "." << data_nastere.m << "." << data_nastere.y;
}

template<CategoriePersoana T>
const std::string &Persoana<T>::getName() const {
    return name;
}

template<CategoriePersoana T>
const data &Persoana<T>::getDataNastere() const {
    return data_nastere;
}

template<CategoriePersoana T>
void Persoana<T>::setName(const std::string &name_) {
    Persoana::name = name_;
}

template<CategoriePersoana T>
void Persoana<T>::setDataNastere(const data &data_nastere_) {
    Persoana::data_nastere = data_nastere_;
}

template<CategoriePersoana T>
Persoana<T>::~Persoana() = default;

class Baiat : public Persoana<CategoriePersoana::Copil>, public GenerareCodCopil<Baiat> {
protected:
    std::string joc_preferat;
public:
    Baiat();

    Baiat(const std::string &name, const data &data_nastere, const std::string &joc_preferat);

    void Print(std::ostream &ostream) const override;

    const std::string &getJocPreferat() const;

    void setJocPreferat(const std::string &joc_preferat_);
};

Baiat::Baiat() : Persoana(), joc_preferat("") {}

Baiat::Baiat(const std::string &name, const data &data_nastere, const std::string &joc_preferat)
    : Persoana(name, data_nastere), joc_preferat(joc_preferat) {}

void Baiat::Print(std::ostream &os) const {
    os << "\nBaiat";
    Persoana<CategoriePersoana::Copil>::Print(os);
    os << "\nJoc preferat: " << joc_preferat;
}

const std::string &Baiat::getJocPreferat() const {
    return joc_preferat;
}

void Baiat::setJocPreferat(const std::string &joc_preferat_) {
    Baiat::joc_preferat = joc_preferat_;
}

class Fata : public Persoana<CategoriePersoana::Copil>, public GenerareCodCopil<Fata> {
protected:
    std::string film_preferat;
public:
    Fata();

    Fata(const std::string &name, const data &data_nastere, const std::string &film_preferat);

    void Print(std::ostream &ostream) const override;

    const std::string &getFilmPreferat() const;

    void setFilmPreferat(const std::string &film_preferat_);
};

Fata::Fata() : Persoana(), film_preferat("") {}

Fata::Fata(const std::string &name, const data &data_nastere, const std::string &film_preferat)
        : Persoana(name, data_nastere), film_preferat(film_preferat) {}

void Fata::Print(std::ostream &os) const {
    os << "\nFata";
    Persoana<CategoriePersoana::Copil>::Print(os);
    os << "\nFilm preferat: " << film_preferat;
}

const std::string &Fata::getFilmPreferat() const {
    return film_preferat;
}

void Fata::setFilmPreferat(const std::string &film_preferat_) {
    Fata::film_preferat = film_preferat_;
}

template <typename T>
bool propozitie(const T &copil1, const T &copil2) {
    return typeid(copil1) == typeid(copil2);
}

int main() {
    data data_tmp;

    data_tmp = {1,1,2006};
    try {
        auto baiat1 = std::make_shared<Baiat>("Baiat1", data_tmp, "joc1");
        std::cout << "\nID: " << baiat1->getId_Persoana();
        std::cout << *baiat1;
    }
    catch (const DataInvalidaCopil &e) {
        std::cout << "\n\n" << e.what();
    }

    data_tmp = {1,1,2002};
    try {
        auto baiat2 = std::make_shared<Baiat>("Baiat2", data_tmp, "joc2");
        std::cout << "\nID: " << baiat2->getId_Persoana();
        std::cout << *baiat2;
    }
    catch (const DataInvalidaCopil &e) {
        std::cout << "\n\n" << e.what();
    }

    std::cout << "\n";

    data_tmp = {1,1,2009};
    try {
        auto fata1 = std::make_shared<Fata>("Fata1", data_tmp, "film1");
        std::cout << "\nID: " << fata1->getId_Persoana();
        std::cout << *fata1;
    }
    catch (const DataInvalidaCopil &e) {
        std::cout << "\n\n" << e.what();
    }

    std::cout << "\n";

    data_tmp = {1,1,2010};
    try {
        auto fata2 = std::make_shared<Fata>("Fata2", data_tmp, "film2");
        std::cout << "\nID: " << fata2->getId_Persoana();
        std::cout << *fata2;
    }
    catch (const DataInvalidaCopil &e) {
        std::cout << "\n\n" << e.what();
    }

    std::cout << "\n";

    data_tmp = {1,1,2020};
    try {
        auto baiat3 = std::make_shared<Baiat>("Baiat3", data_tmp, "joc3");
        std::cout << "\nID: " << baiat3->getId_Persoana();
        std::cout << *baiat3;
    }
    catch (const DataInvalidaCopil &e) {
        std::cout << "\n\n" << e.what();
    }

    std::cout << "\n";

    data_tmp = {1,1,1990};
    try {
        auto persoana1 = std::make_shared<Persoana<CategoriePersoana::Adult>>("Adult1", data_tmp);
        std::cout << *persoana1;
    }
    catch (const DataInvalidaAdult &e) {
        std::cout << "\n\n" << e.what();
    }

    return 0;
}
