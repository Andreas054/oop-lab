#ifndef _EXCEPTII_H_
#define _EXCEPTII_H_

class CodAngajatAsociatException : public std::exception {
public:
    CodAngajatAsociatException() = default;

    const char* what() const noexcept override  {
        return "Exceptie: Codul de angajat are asociat vanzari!";
    }
};

class CodClientInexistentException : public std::exception {
public:
    CodClientInexistentException() = default;

    const char* what() const noexcept override  {
        return "Exceptie: Codul de client nu exista!";
    }
};

#endif