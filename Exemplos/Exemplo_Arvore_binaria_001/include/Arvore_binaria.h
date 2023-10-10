#ifndef ARVORE_BINARIA_H
#define ARVORE_BINARIA_H

#include "No_arvore_binaria.h"


class Arvore_binaria
{
    public:
        Arvore_binaria();
        ~Arvore_binaria();
        Arvore_binaria(const Arvore_binaria& other);
        Arvore_binaria& operator=(const Arvore_binaria& other);
        Arvore_binaria(std::initializer_list<int>);

        void insere_recursivo(No_arvore_binaria *, No_arvore_binaria *);
        No_arvore_binaria * busca_recursiva(No_arvore_binaria *, int);

        void insere(int);
        No_arvore_binaria * busca(int); // retorna ponteiro para o no que contem a chave, senao nullptr

    protected:

    private:
        No_arvore_binaria * raiz;
};

#endif // ARVORE_BINARIA_H
