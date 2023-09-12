/*-------------------------------------------------------------
 * UFRJ - Universidade Federal do Rio de Janeiro
 * IM   - Instituto de Matemática
 * DMA  - Departamento de Matemática Aplicada
 *
 *   MAE016 - Tópicos em Engenharia de Dados B - 2023.2
 *            "Estruturas de Dados (e seus algoritmos)"
 *
 *   Semana 04  : Introdução a linguagem C/C++
 *   Exemplo 002: Classes simples
 *
 *   Autor: Prof. Milton R Ramirez (milton@matematica.ufrj.br)
 *   Data criação  : 12 de setembro de 2023
 *   Data alteração: 12 de setembro de 2023
 *
 *--------------------------------------------------------------
*/
#include <iostream>

using namespace std;

typedef unsigned long int t_CPF;

class t_Pessoa
{
    t_CPF   CPF;
    string  Nome;
    string  Dt_nasc;

  public:
    // Area de algoritmos: métodos do objeto
    void Cadastro(t_CPF pCPF, string pNome, string pDt_nasc)
    {
        CPF = pCPF;
        Nome = pNome;
        Dt_nasc = pDt_nasc;
    }
    void Print(void)
    {
        cout << "+-------------------------------------+" << endl;
        cout << "|          Registro de Aluno          |" << endl;
        cout << "+-------------------------------------+" << endl;
        cout << "            CPF : " << CPF     << endl;
        cout << "            Nome: " << Nome    << endl;
        cout << " Data Nascimento: " << Dt_nasc << endl;
        cout << "+-------------------------------------+" << endl;
    }
};


/*--------------------------------------------------------------
 * Area de variaveis globais
 *--------------------------------------------------------------
*/
t_Pessoa TAB_Pessoas[10];
unsigned int indx_pessoas = 0;

/*--------------------------------------------------------------
 * Area de Rotina globais
 *--------------------------------------------------------------
*/
void Apresenta_texto_menu(void)
{
    cout << "+----------------------------------+" << endl;
    cout << "\t1 - Cadastrar Pessoa" << endl;
    cout << "\t2 - Consultar Pessoa" << endl;
    cout << "\t3 - Deletar Pessoa" << endl;
    cout << "+----------------------------------+" << endl;
    cout << "+ aperte a tecla 's' para sair" << endl;
    cout << "+----------------------------------+" << endl;
}

void Executa_opcao_1(void)
{
    t_Pessoa obj_pessoa;

    cout << "*************************" << endl;
    cout << "* Cadastro de Pessoa    *" << endl;
    cout << "*************************" << endl;

    obj_pessoa.Cadastro(98744400123,"Ze das Coves","12/03/2002");
    obj_pessoa.Print();
    TAB_Pessoas[indx_pessoas++] = obj_pessoa;
}

void Executa_opcao_2(void)
{
    cout << "*************************" << endl;
    cout << "* Consultar Pessoa      *" << endl;
    cout << "*************************" << endl;
}

void Executa_opcao_3(void)
{
    cout << "*************************" << endl;
    cout << "* Deletar Pessoa *" << endl;
    cout << "*************************" << endl;
}

void Menu_de_opcoes(void)
{
    char opcao_escolhida;

    do {
        Apresenta_texto_menu();
        cin >> opcao_escolhida;
        switch (opcao_escolhida) {
            case '1' : Executa_opcao_1(); break;
            case '2' : Executa_opcao_2(); break;
            case '3' : Executa_opcao_3(); break;
            case 's' : break;
            default  : cout << "Opcao invalida, tente novamente, ou 's' para sair" << endl;
        }
    } while (opcao_escolhida != 's');
}

/*--------------------------------------------------------------
 * Rotina principal
 *--------------------------------------------------------------
*/
int main()
{
    cout << "Exemplo 002: Classe Pessoas " << endl;
    Menu_de_opcoes();

    return 0;
}
