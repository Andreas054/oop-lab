#ifndef _ANGAJAT_H_
#define _ANGAJAT_H_

#include "persoana.h"
#include <string>

class Angajat : public Persoana {
private:
    std::string data_angajare;
    static int nr_angajati;
public:
    Angajat();

    Angajat(const std::string &name, const std::string &data_nastere, const int cod, const std::string &data_angajare);

    bool operator==(const Angajat &rhs) const;

    bool operator!=(const Angajat &rhs) const;

    Angajat &operator=(const Angajat &rhs);

    friend std::istream &operator>>(std::istream &is, Angajat &angajat);

    friend std::ostream &operator<<(std::ostream &os, const Angajat &angajat);

    friend std::ifstream &operator>>(std::ifstream &ifstr, Angajat &angajat);

    std::string &getDataAngajare() override;

    void setDataAngajare(std::string data_angajare);

    static void decNrAngajati();

    static int getNrAngajati();

    virtual ~Angajat();
};

#endif
