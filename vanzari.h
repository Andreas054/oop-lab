#ifndef _VANZARI_H_
#define _VANZARI_H_

#include <string>

class Vanzari {
protected:
    std::string name;
    int cod_persoana, id;
    double pret;
public:
    Vanzari(std::string name, int cod_persoana, int id, double pret);

    Vanzari();

    const std::string &getName() const;

    int getCod_persoana() const;

    int getIdVanzare() const;

    double getPret() const;

    void setName(const std::string &name);

    void setCod_persoana(int cod_persoana);

    void setId(int id);

    void setPret(double pret);

    bool operator==(const Vanzari &rhs) const;

    bool operator!=(const Vanzari &rhs) const;

    Vanzari &operator=(const Vanzari &rhs);

    friend std::istream &operator>>(std::istream &is, Vanzari &vanzare);

    friend std::ostream &operator<<(std::ostream &os, const Vanzari &vanzare);

    friend std::ifstream &operator>>(std::ifstream &ifstr, Vanzari &vanzare);

    virtual ~Vanzari();
};

#endif
