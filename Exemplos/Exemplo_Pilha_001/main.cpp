/*-------------------------------------------------------------
 * UFRJ - Universidade Federal do Rio de Janeiro
 * IM   - Instituto de Matemática
 * DMA  - Departamento de Matemática Aplicada
 *
 *   MAE016 - Tópicos em Engenharia de Dados B
 *            "Estruturas de Dados (e seus algoritmos)"
 *
 *   Semana 06  : Estruturas de Dados Lineares
 *   Exemplo 601: Classe Pilha - 001
 *      Uso de classe e funções parametrizadas (template)
 *
 *   Módulo Principal
 *   Autor: Prof. Milton R Ramirez (milton@matematica.ufrj.br)
 *   Data criação  : 21 de setembro de 2023
 *   Data alteração: 21 de setembro de 2023
 *
 *--------------------------------------------------------------
*/

#include <iostream>

using namespace std;

/*--------------------------------------
 Area de constantes do programa
 ---------------------------------------*/
const int TAM_MAX_PILHA = 100; // quando a pilha eh definida em um ARRAY

/*--------------------------------------
 Area de Estruturas de Dados
 ---------------------------------------*/
struct T_Pessoa {
    string nome;
    long int CPF;

    T_Pessoa(string p_nome = "") { nome = p_nome; }
};

template <class T>
class C_Pilha {
    T pilha[TAM_MAX_PILHA]; // a pilha esta sendo implementada em um ARRAY do C
    int topo;

public: // INTERFACE
    C_Pilha() { topo = 0; } // o topo aponta par a 1a pos vazia da pilha
    void push(T dado) { pilha[topo++] = dado; }
    T pop(void) { return pilha[--topo]; }
    bool pilha_esta_vazia(void) { return (topo == 0); }
};

int main()
{
    cout << "Pilhas - 001" << endl;

    // Teste usando INTEIROS
    C_Pilha<int> p1;

    p1.push(20.4);
    p1.push(30);
    p1.push(40);
    p1.push(50);

    while( !p1.pilha_esta_vazia() )
        cout << p1.pop() << endl;

    // Teste usando a classe PESSOA
    C_Pilha<T_Pessoa> p2;

    p2.push(T_Pessoa("Ze das coves"));
    p2.push(T_Pessoa("Mariazinha"));
    p2.push(T_Pessoa("Fulano de tal"));

    while( !p2.pilha_esta_vazia() )
        cout << p2.pop().nome << endl;

    return 0;
}
