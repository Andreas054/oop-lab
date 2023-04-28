#ifndef _PERSOANA_H_
#define _PERSOANA_H_

#include <string>

class Persoana {
protected:
    std::string name, data_nastere;
    int cod;
public:
    Persoana();

    Persoana(const std::string &name, const std::string &data_nastere, const int cod);

    const std::string &getName() const;

    const std::string &getDataNastere() const;

    int getCod() const;

    void setName(const std::string &name);

    void setDataNastere(const std::string &data_nastere);

    void setCod(int cod);

    virtual std::string &getDataAngajare() = 0;

    virtual ~Persoana();
};

#endif