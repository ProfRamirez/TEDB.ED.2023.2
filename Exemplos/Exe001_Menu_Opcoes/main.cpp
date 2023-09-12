/*-------------------------------------------------------------
 * UFRJ - Universidade Federal do Rio de Janeiro
 * IM   - Instituto de Matemática
 * DMA  - Departamento de Matemática Aplicada
 *
 *   MAE016 - Tópicos em Engenharia de Dados B - 2023.2
 *            "Estruturas de Dados (e seus algoritmos)"
 *
 *   Semana 04  : Introdução a linguagem C/C++
 *   Exemplo 001: Menu simples
 *
 *   Autor: Prof. Milton R Ramirez (milton@matematica.ufrj.br)
 *   Data criação  : 12 de setembro de 2023
 *   Data alteração: 12 de setembro de 2023
 *
 *--------------------------------------------------------------
*/
#include <iostream>

using namespace std;


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

void Cadastrar_Pessoa(void)
{
    cout << "*************************" << endl;
    cout << "* Cadastro de Pessoa    *" << endl;
    cout << "*************************" << endl;

}

void Consultar_Pessoa(void)
{
    cout << "*************************" << endl;
    cout << "* Consultar Pessoa      *" << endl;
    cout << "*************************" << endl;
}

void Deletar_Pessoa(void)
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
            case '1' : Cadastrar_Pessoa(); break;
            case '2' : Consultar_Pessoa(); break;
            case '3' : Deletar_Pessoa(); break;
            case 's' :
            case 'S' : break;
            default  : cout << "Opcao invalida, tente novamente, ou 's' para sair" << endl;
        }

    } while (opcao_escolhida != 's' && opcao_escolhida != 'S');
}

/*--------------------------------------------------------------
 * Rotina principal
 *--------------------------------------------------------------
*/
int main()
{
    cout << "Exemplo 001: Menu de Opcoes" << endl;
    Menu_de_opcoes();

    return 0;
}
