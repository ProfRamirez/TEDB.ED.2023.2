#include <iostream>
#include <string>
#include "No_arvore_binaria.h"

No_arvore_binaria::No_arvore_binaria(int p_dado)
{
    dado = p_dado;
    esq = dir = nullptr;
}

No_arvore_binaria::~No_arvore_binaria()
{
    //todo
}

No_arvore_binaria::No_arvore_binaria(const No_arvore_binaria& other)
{
    //todo copy ctor
}

No_arvore_binaria& No_arvore_binaria::operator=(const No_arvore_binaria& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

std::string No_arvore_binaria::visita(void)
{
    return std::to_string(dado);
}

