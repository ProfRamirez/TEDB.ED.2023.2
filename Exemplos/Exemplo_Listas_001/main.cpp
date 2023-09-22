/*-------------------------------------------------------------
 * UFRJ - Universidade Federal do Rio de Janeiro
 * IM   - Instituto de Matemática
 * DMA  - Departamento de Matemática Aplicada
 *
 *   MAE016 - Tópicos em Engenharia de Dados B
 *            "Estruturas de Dados (e seus algoritmos)"
 *
 *   Semana 07  : Estruturas de Dados Lineares
 *   Exemplo 701: Classe Lista 001
 *
 *   Módulo Principal
 *   Autor: Prof. Milton R Ramirez (milton@matematica.ufrj.br)
 *   Data criação  : 21 de setembro de 2023
 *   Data alteração: 26 de setembro de 2023
 *
 *--------------------------------------------------------------
*/
#include <iostream>

using namespace std;

class C_Lista;

class C_No_lst_encadeada_simples {
    int dado;
    C_No_lst_encadeada_simples * prox;
    friend class C_Lista;

public:
    C_No_lst_encadeada_simples(int p_dado) { dado = p_dado; prox = nullptr; }
};

class C_Lista {
    C_No_lst_encadeada_simples * inicio;

public:
    C_Lista(void) { inicio = nullptr; }
    void insere_no_inicio(int p_dado);
    void percorre_lista(void);
};


void C_Lista::insere_no_inicio(int p_dado)
{
    C_No_lst_encadeada_simples * novo_no; // ponteiro para o novo NO

    novo_no = new C_No_lst_encadeada_simples(p_dado); // cria o novo NO na memoria com o dado
    if (inicio != nullptr) // se a lista nao esta vazia
        novo_no->prox  = inicio;
    inicio = novo_no;
}

void C_Lista::percorre_lista(void)
{
    C_No_lst_encadeada_simples * aux = inicio; // aponta para o 1o NO da lista
    while ( aux ) // enquanto não for o fim da lista (testa tb se lista esta vazia)
    {
        cout << aux->dado << endl;
        aux = aux->prox;
    }
}

/*---------------------------------------------------------*/
int main()
{
    cout << "Exemplo de Listas - 001" << endl;

    C_Lista lista1;

    lista1.insere_no_inicio(10);
    lista1.insere_no_inicio(20);
    lista1.insere_no_inicio(30);
    lista1.insere_no_inicio(40);
    lista1.insere_no_inicio(50);

    lista1.percorre_lista();

    return 0;
}
