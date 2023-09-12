/*-------------------------------------------------------------
 * UFRJ - Universidade Federal do Rio de Janeiro
 * IM   - Instituto de Matemática
 * DMA  - Departamento de Matemática Aplicada
 *
 *   MAE016 - Tópicos em Engenharia de Dados B - 2023.2
 *            "Estruturas de Dados (e seus algoritmos)"
 *
 *   Semana 04  : Introdução a linguagem C/C++
 *   Exemplo 001: Menu de Opções simples
 *
 *   Autor: Prof. Milton R Ramirez (milton@matematica.ufrj.br)
 *   Data criação  : 12 de setembro de 2023
 *   Data alteração: 12 de setembro de 2023
 *
 *--------------------------------------------------------------
*/
#include <iostream>

using namespace std;

void Apresenta_texto_menu(void)
{
    cout << "+----------------------------------+" << endl;
    cout << "\t1 - Executar a Rotina A" << endl;
    cout << "\t2 - Executar a Rotina B" << endl;
    cout << "\t3 - Executar a Rotina c" << endl;
    cout << "+----------------------------------+" << endl;
    cout << "+ aperte a tecla 's' para sair" << endl;
    cout << "+----------------------------------+" << endl;
}

void Executa_opcao_1(void)
{
    cout << "*************************" << endl;
    cout << "* executando a Rotina A *" << endl;
    cout << "*************************" << endl;
}

void Executa_opcao_2(void)
{
    cout << "*************************" << endl;
    cout << "* executando a Rotina B *" << endl;
    cout << "*************************" << endl;
}

void Executa_opcao_3(void)
{
    cout << "*************************" << endl;
    cout << "* executando a Rotina C *" << endl;
    cout << "*************************" << endl;
}

void Menu(void)
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

int main()
{
    cout << "Exemplo 001: Menu de Opcoes simples " << endl;
    Menu();

    return 0;
}
