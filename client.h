#ifndef _CLIENT_H_
#define _CLIENT_H_

#include "persoana.h"
#include <string>

class Client : public Persoana {
private:
    int cantitate_achiz;
public:
    Client();

    Client(std::string name, std::string data_nastere, int cod, int cantitate_achiz);

    bool operator==(const Client &rhs) const;

    bool operator!=(const Client &rhs) const;

    Client &operator=(const Client &rhs);

    friend std::istream &operator>>(std::istream &is, Client &client);

    friend std::ostream &operator<<(std::ostream &os, const Client &client);

    friend std::ifstream &operator>>(std::ifstream &ifstr, Client &client);

    std::string &getDataAngajare() override;

    int getCantitateAchiz() const;

    void setCantitate_Achiz(const int cantitate_achiz);

    virtual ~Client();
};

#endif
