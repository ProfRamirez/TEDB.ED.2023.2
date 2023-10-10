#include <iostream>
#include "Arvore_binaria.h"

using namespace std;

int main()
{
    cout << "Arvore Binaria" << endl;

    Arvore_binaria arv01 {10,5,15,3,7,12,20};
    No_arvore_binaria * aux;

    int lista_de_busca[] = {15, 7, 13};
    for(auto & chave : lista_de_busca)
    {
        cout << "Procurando: "<< chave << endl;
        if (aux = arv01.busca(chave))
            cout << "Achei a chave: " << aux->visita() << endl;
        else
            cout << "Nao encontrei a chave: " << chave << endl;
    }

    return 0;
}
