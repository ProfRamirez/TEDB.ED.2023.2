#include <iostream>
#include "Arvore_binaria.h"

using namespace std;

Arvore_binaria::Arvore_binaria()
{
    //ctor
    raiz = nullptr;
}

Arvore_binaria::~Arvore_binaria()
{
    //dtor
    delete raiz;
}

Arvore_binaria::Arvore_binaria(const Arvore_binaria& other)
{
    //copy ctor
    raiz = other.raiz;
}

Arvore_binaria& Arvore_binaria::operator=(const Arvore_binaria& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

void Arvore_binaria::insere_recursivo(No_arvore_binaria * no_sendo_inspecionado, No_arvore_binaria * novo_no)
{
    if( novo_no->dado < no_sendo_inspecionado->dado)
        if(no_sendo_inspecionado->esq == nullptr)
            no_sendo_inspecionado->esq = novo_no; // inseriu no ramo  esq
        else
            insere_recursivo(no_sendo_inspecionado->esq, novo_no); // insere na subarvore esquerda
    else // deve seguir pela direita
        if(no_sendo_inspecionado->dir == nullptr)
            no_sendo_inspecionado->dir = novo_no; // inseriu no ramo direito
        else
            insere_recursivo(no_sendo_inspecionado->dir, novo_no); // insere na subarvore direita
}

void Arvore_binaria::insere(int p_dado)
{
    No_arvore_binaria * novo_no = new No_arvore_binaria(p_dado);

    if (raiz == nullptr)
        raiz = novo_no; // arvore vazia
    else
        insere_recursivo(raiz, novo_no);
}

No_arvore_binaria * Arvore_binaria::busca_recursiva(No_arvore_binaria * no_sendo_inspecionado, int chave)
{
    if (no_sendo_inspecionado-> dado == chave)
        return no_sendo_inspecionado;
    else
        if( chave < no_sendo_inspecionado->dado)
            if(no_sendo_inspecionado->esq == nullptr)
                return nullptr; // nao achou a chave pois subarvore esquerda vazia
            else
                return busca_recursiva(no_sendo_inspecionado->esq, chave); // busca na subarvore esquerda
        else // deve seguir pela direita
            if(no_sendo_inspecionado->dir == nullptr)
                return nullptr; // nao achou a chave pois subarvore direita vazia
            else
                return busca_recursiva(no_sendo_inspecionado->dir, chave); // busca na subarvore direita
}

No_arvore_binaria * Arvore_binaria::busca(int chave)
{ // retorna um ponteiro para o no que contem a chave, senão retorna nullptr
    if (raiz == nullptr)
        return raiz; // arvore vazia
    else
        return busca_recursiva(raiz, chave);
}

Arvore_binaria::Arvore_binaria(initializer_list<int> itens)
{
    raiz = nullptr;
    for(const int & x : itens) {
        cout << "Inserindo: " << x << endl;
        insere(x);
    }
}
