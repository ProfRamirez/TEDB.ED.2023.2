/*-------------------------------------------------------------
 * UFRJ - Universidade Federal do Rio de Janeiro
 * IM   - Instituto de Matemática
 * DMA  - Departamento de Matemática Aplicada
 *
 *   MAE016 - Tópicos em Engenharia de Dados B
 *            "Estruturas de Dados (e seus algoritmos)"
 *
 *   Semana 08  : Estruturas de Dados Lineares
 *   Exemplo 802: Classe Lista Duplamente Encadeadas 001
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

class C_Lista_dupla;
enum t_Direcao_de_percurso {DO_INICIO_PARA_O_FIM, DO_FIM_PARA_O_INICIO};


class C_No_lst_encadeada_dupla {
    int dado;
    C_No_lst_encadeada_dupla * prox;
    C_No_lst_encadeada_dupla * anterior;
    friend class C_Lista_dupla;

public:
    C_No_lst_encadeada_dupla(int p_dado) { dado = p_dado; anterior = prox = nullptr; }
};

class C_Lista_dupla {
    C_No_lst_encadeada_dupla * inicio;
    C_No_lst_encadeada_dupla * fim;

public:
    C_Lista_dupla(void) { inicio = fim = nullptr; }
    C_Lista_dupla(initializer_list<int>); // construtor para lista de inicializacao

    void insere_no_inicio(int p_dado);
    void percorre_lista(t_Direcao_de_percurso);
};


void C_Lista_dupla::insere_no_inicio(int p_dado)
{
    C_No_lst_encadeada_dupla * novo_no; // ponteiro para o novo NO

    novo_no = new C_No_lst_encadeada_dupla(p_dado); // cria o novo NO na memoria com o dado
    if (inicio != nullptr) {// se a lista nao esta vazia
        novo_no->prox  = inicio;
        inicio->anterior = novo_no;
    }
    inicio = novo_no; // vale tanto se a lista estiver vazia ou nao
    if (fim == nullptr) // se a lista estiver vazia
        fim = novo_no;
}

C_Lista_dupla::C_Lista_dupla(initializer_list<int> itens)
{
    for(auto & x : itens)
        insere_no_inicio(x);
}

void C_Lista_dupla::percorre_lista(t_Direcao_de_percurso direcao_de_percurso = DO_INICIO_PARA_O_FIM)
{
    C_No_lst_encadeada_dupla * aux;

    if (direcao_de_percurso == DO_INICIO_PARA_O_FIM)
        aux = inicio;
    else
        aux = fim;

    while ( aux ) // enquanto não for o fim da lista (testa tb se lista esta vazia)
    {
        cout << aux->dado << endl;
        aux = (direcao_de_percurso == DO_INICIO_PARA_O_FIM) ? aux->prox : aux->anterior;
    }
}

/*---------------------------------------------------------*/
int main()
{
    cout << "Exemplo de Listas - 001" << endl;

    C_Lista_dupla lista1;

    lista1.insere_no_inicio(10);
    lista1.insere_no_inicio(20);
    lista1.insere_no_inicio(30);
    lista1.insere_no_inicio(40);
    lista1.insere_no_inicio(50);

    cout << "\n percurso em ordem direta" << endl;
    lista1.percorre_lista();
    cout << "\n percurso em ordem inversa" << endl;
    lista1.percorre_lista(DO_FIM_PARA_O_INICIO);

    C_Lista_dupla lista2 = {101,102,103,104,105};
    cout << "\n percorre lista2 em ordem direta" << endl;
    lista2.percorre_lista();


    return 0;
}
