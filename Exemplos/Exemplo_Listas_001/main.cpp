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

struct T_Pessoa {
    string nome;
    long int CPF;

    T_Pessoa(string p_nome = "") { nome = p_nome; }
};

template <class T> class C_Lista;

template <class T>
class C_No_lst_encadeada_simples {
    T dado;
    C_No_lst_encadeada_simples * prox;
    friend class C_Lista<T>;

public:
    C_No_lst_encadeada_simples(T p_dado) { dado = p_dado; prox = nullptr; ); }
};

template <class T>
class C_Lista {
    C_No_lst_encadeada_simples<T> * inicio;
    unsigned int num_elementos;

public:
    C_Lista(void) { inicio = nullptr; num_elementos = 0;}
    void insere_no_inicio(T p_dado);
    T select_pos(unsigned int i);
};

template <class T>
void C_Lista<T>::insere_no_inicio(T p_dado)
{
    C_No_lst_encadeada_simples<T> * novo_no;

    novo_no = new C_No_lst_encadeada_simples<T>(p_dado);
    if (inicio != nullptr)
        novo_no->prox  = inicio;
    inicio = novo_no;
    num_elementos++;
}

template <class T>
void C_Lista<T>::select_pos(unsigned int indx)
{
    C_No_lst_encadeada_simples<T> * aux = inicio;
    while ( ???? )
    {
        aux = aux->prox;
    }
}

/*---------------------------------------------------------*/
int main()
{
    cout << "Exemplo de Listas - 001" << endl;
    return 0;
}
