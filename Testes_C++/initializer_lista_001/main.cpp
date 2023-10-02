/*-------------------------------------------------------------
 * UFRJ - Universidade Federal do Rio de Janeiro
 * IM   - Instituto de Matemática
 * DMA  - Departamento de Matemática Aplicada
 *
 *   MAE016 - Tópicos em Engenharia de Dados B
 *            "Estruturas de Dados (e seus algoritmos)"
 *
 *   Semana TOD :
 *   Teste  001 : Lista de Inicialização com lista simplesmente encadeada
 *
 *   Módulo Principal
 *   Autor: Prof. Milton R Ramirez (milton@matematica.ufrj.br)
 *   Data criação  : 01 de outubro de 2023
 *   Data alteração: 02 de outubro de 2023
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
    C_Lista(initializer_list<int>);
    void insere_no_inicio(int p_dado);
    int recupera_do_inicio(void);
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

int C_Lista::recupera_do_inicio(void)
{
    C_No_lst_encadeada_simples * no_do_inicio; // ponteiro para o primeiro no

    no_do_inicio = inicio;
    if (no_do_inicio != nullptr) // se a lista nao esta vazia
        inicio = no_do_inicio->prox; // atualiza para o 2o da lista
    int dado = no_do_inicio->dado;
    delete no_do_inicio;
    return dado;
}

C_Lista::C_Lista(initializer_list<int> itens)
{
    for(auto & x : itens)
        insere_no_inicio(x);
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

int main()
{
    cout << "Initializer list" << endl;

    int vet[] = {1,2,3,4,5};

    for( int i = 0 ; i < 5; i++)
        cout << vet[i] << " ";
    cout << endl;

    for(auto & x : vet)
        cout << x << " ";
    cout << endl;

    C_Lista l1 = {6,7,8,9};
    l1.percorre_lista();

/*    for(auto & x : l1)
        cout << x << " ";
    cout << endl;
*/
    for( int i = 0; i < 4; i++)
        cout << l1.recupera_do_inicio() << " ";
    cout << endl;

    return 0;
}
