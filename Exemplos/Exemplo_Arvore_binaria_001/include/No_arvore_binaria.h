#ifndef NO_ARVORE_BINARIA_H
#define NO_ARVORE_BINARIA_H
#include <iostream>

class Arvore_binaria;

class No_arvore_binaria
{
    public:
        No_arvore_binaria(int);
        ~No_arvore_binaria();
        No_arvore_binaria(const No_arvore_binaria& other);
        No_arvore_binaria& operator=(const No_arvore_binaria& other);

        std::string visita(void);

    protected:

    private:
        int dado;
        No_arvore_binaria * esq;
        No_arvore_binaria * dir;

    friend class Arvore_binaria;
};

#endif // NO_ARVORE_BINARIA_H
