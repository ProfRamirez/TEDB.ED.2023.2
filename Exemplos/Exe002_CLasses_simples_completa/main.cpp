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
        cout << "|          Registro de Pessoa         |" << endl;
        cout << "+-------------------------------------+" << endl;
        cout << "            CPF : " << CPF     << endl;
        cout << "            Nome: " << Nome    << endl;
        cout << " Data Nascimento: " << Dt_nasc << endl;
        cout << "+-------------------------------------+" << endl;
    }
    t_CPF getCPF(void) // getter() necessário pois o CPF é membro PRIVATE
    {
        return CPF;
    }
};


/*--------------------------------------------------------------
 * Area de variaveis globais
 *--------------------------------------------------------------
*/
t_Pessoa TAB_Pessoas[100];
unsigned int pos_cadastro_nova_pessoas = 0;

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

void Cadastro_Pessoas(void)
{
    t_Pessoa obj_pessoa;
    string   pNome, pDatNasc;
    t_CPF    pCPF;

    cout << "*************************" << endl;
    cout << "* Cadastro de Pessoa    *" << endl;
    cout << "*************************" << endl;

    cout << "Qual o CPF pessoa? "; cin >> pCPF;
    cout << "Qual o nome da pessoa? "; cin.ignore(); getline(cin,pNome);
    cout << "Qual a data de nascimento da pessoa? "; getline(cin,pDatNasc);
    obj_pessoa.Cadastro(pCPF,pNome,pDatNasc);
    TAB_Pessoas[pos_cadastro_nova_pessoas++] = obj_pessoa;
}

void Consulta_Pessoas(void)
{
    t_CPF pCPF;

    cout << "*************************" << endl;
    cout << "* Consultar Pessoa      *" << endl;
    cout << "*************************" << endl;

    cout << "Qual o CPF da pessoa a consultar? ";  cin >> pCPF;
    for (unsigned int indx = 0; indx < pos_cadastro_nova_pessoas; indx++) {
        if (TAB_Pessoas[indx].getCPF() == pCPF) TAB_Pessoas[indx].Print();
    }
}

void Deleta_Pessoa(void)
{
    cout << "*************************" << endl;
    cout << "* Deletar Pessoa        *" << endl;
    cout << "*************************" << endl;

}

void Menu_de_opcoes(void)
{
    char opcao_escolhida;

    do {
        Apresenta_texto_menu();
        cin >> opcao_escolhida;
        switch (opcao_escolhida) {
            case '1' : Cadastro_Pessoas(); break;
            case '2' : Consulta_Pessoas(); break;
            case '3' : Deleta_Pessoa(); break;
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
