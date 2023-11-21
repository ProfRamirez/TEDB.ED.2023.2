/*-------------------------------------------------------------
 * UFRJ - Universidade Federal do Rio de Janeiro
 * IM   - Instituto de Matemática
 * DMA  - Departamento de Matemática Aplicada
 *
 *   MAE016 - Tópicos em Engenharia de Dados B
 *            "Estruturas de Dados (e seus algoritmos)"
 *
 *   Semana 14  : Estruturas de Dados Hierarquicas -
 *   Exemplo 141: PR-Quadtree para pontos 2D
 *
 *   Módulo Principal
 *   Autor: Prof. Milton R Ramirez (milton@matematica.ufrj.br)
 *   Data criação  : 14 de novembro de 2023
 *   Data alteração: 15 de novembro de 2023
 *
 *   Obs.: Adapatado a partir do código existente no site: https://www.geeksforgeeks.org/quad-tree/
 *         onde a dita "Quadtree" foi adaptada para uma PR-Quadtree e, para simplificar o trabalho,
 *         neste exemplo iremos utilizar como “Pontos 2D” uma representação adaptada de técnicas básicas
 *         utilizadas em Computação Gráfica, ou seja, os Pontos 2D serão codificando através da composição
 *         entre um dupla (x,y) de números do tipo Inteiro, que irá registrar a localização do ponto em
 *         relação as coordenadas da região da “tela do computador”, conhecido como “Canvas”, que será a
 *         área de abrangência da PR-Quadtree. Assim, todo ponto para poder ser armazenado na PR-Quadtree
 *         deverá residir nesse intervalo de valores inteiros especificados para o Canvas.
 *
 *--------------------------------------------------------------
*/
// C++ Implementation of PR-QuadTree para armazenar Pontos 2D
#include <cmath>
#include <iostream>
using namespace std;

// TAD codificando os pontis 2D
// Tomados em coordenadas inteiras relativas ao "Canvas"
struct Point2D {
	int x;
	int y;
	Point2D(int _x, int _y)
	{
		x = _x;
		y = _y;
	}
	Point2D()
	{
		x = 0;
		y = 0;
	}
};

// Os Dados que serã armazenados no nós da PR-Quadtree.
// Eles contem a localização do ponto de dados e o registro de dados
// que no caso deste exemplo é apenas um inteiro
struct Reg_Node {
	Point2D pos;
	int data;
	Reg_Node(Point2D _pos, int _data = 0)
	{
		pos = _pos;
		data = _data;
	}
	Reg_Node() { pos = Point2D(); data = 0; }
};

// Classe subdivisão da PR_Quadtree, ou seja, um nó interno ou folha da árvore
class no_PR_Quadtree {
	// As coordenadas do retangulo que delimita a area da tela abrangida pela subdivisão da PR-Quadtree
	// Os pontos são o canto superior esquerdo e o canto inferior direito do retangulo
	Point2D topLeft;
	Point2D botRight;

	// Contem os dados armazenado neste nó da PR-Quadtree
	Reg_Node* n;

	// Indica se o no é folha
	bool eh_folha;

	// subarvores ou filho do nó
	no_PR_Quadtree* topLeftTree;
	no_PR_Quadtree* topRightTree;
	no_PR_Quadtree* botLeftTree;
	no_PR_Quadtree* botRightTree;

public:
	no_PR_Quadtree()
	{
		topLeft = Point2D(0, 0);
		botRight = Point2D(0, 0);
		n = NULL;
		eh_folha = true;
		topLeftTree = NULL;
		topRightTree = NULL;
		botLeftTree = NULL;
		botRightTree = NULL;
	}
	no_PR_Quadtree(Point2D topL, Point2D botR)
	{
		n = NULL;
		eh_folha = true;
		topLeftTree = NULL;
		topRightTree = NULL;
		botLeftTree = NULL;
		botRightTree = NULL;
		topLeft = topL;
		botRight = botR;
	}
	void insert(Reg_Node*);
	Reg_Node* search(Point2D);
	bool inBoundary(Point2D);
};

// Insere o ponto através de uma busca em profundidade da sua localização na árvore.
void no_PR_Quadtree::insert(Reg_Node* node)
{
	if (node == NULL)
		return;

	// Current quad cannot contain it
	if (!inBoundary(node->pos))
		return;

	// We are at a quad of unit area
	// We cannot subdivide this quad further
	if (abs(topLeft.x - botRight.x) <= 1
		&& abs(topLeft.y - botRight.y) <= 1) {
		if (n == NULL)
			n = node;
		return;
	}

	// Se o no for folha recem criada, insere nele
    if (eh_folha && n == NULL) {
        n = node;
        return;
    }

    // se eh folha e já contem um ponto, reinsere este ponto subdividindo a folha
    if(eh_folha && n != NULL){
        eh_folha = false;
        insert(n);
    }
	//se chegou aqui tem que subdividir
	if ((topLeft.x + botRight.x) / 2 >= node->pos.x) {
		// Indicates topLeftTree
		if ((topLeft.y + botRight.y) / 2 >= node->pos.y) {
			if (topLeftTree == NULL)
				topLeftTree = new no_PR_Quadtree(
					Point2D(topLeft.x, topLeft.y),
					Point2D((topLeft.x + botRight.x) / 2,
						(topLeft.y + botRight.y) / 2));
			cout << "Desci pela topLeftTree com o ponto: "<< node->data << endl;
			topLeftTree->insert(node);
		}

		// Indicates botLeftTree
		else {
			if (botLeftTree == NULL)
				botLeftTree = new no_PR_Quadtree(
					Point2D(topLeft.x,
						(topLeft.y + botRight.y) / 2),
					Point2D((topLeft.x + botRight.x) / 2,
						botRight.y));
			cout << "Desci pela botLeftTree com o ponto: "<< node->data << endl;
			botLeftTree->insert(node);
		}
	}
	else {
		// Indicates topRightTree
		if ((topLeft.y + botRight.y) / 2 >= node->pos.y) {
			if (topRightTree == NULL)
				topRightTree = new no_PR_Quadtree(
					Point2D((topLeft.x + botRight.x) / 2,
						topLeft.y),
					Point2D(botRight.x,
						(topLeft.y + botRight.y) / 2));
			cout << "Desci pela topRightTree com o ponto: "<< node->data << endl;
			topRightTree->insert(node);
		}

		// Indicates botRightTree
		else {
			if (botRightTree == NULL)
				botRightTree = new no_PR_Quadtree(
					Point2D((topLeft.x + botRight.x) / 2,
						(topLeft.y + botRight.y) / 2),
					Point2D(botRight.x, botRight.y));
			cout << "Desci pela botRightTree com o ponto: "<< node->data << endl;
			botRightTree->insert(node);
		}
	}
}

// Find a node in a quadtree
Reg_Node* no_PR_Quadtree::search(Point2D p)
{
	// Current quad cannot contain it
	if (!inBoundary(p))
		return NULL;

	// We are at a quad of unit length
	// We cannot subdivide this quad further
	if (eh_folha && n != NULL)
		return n;

	if ((topLeft.x + botRight.x) / 2 >= p.x) {
		// Indicates topLeftTree
		if ((topLeft.y + botRight.y) / 2 >= p.y) {
			if (topLeftTree == NULL)
				return NULL;
			return topLeftTree->search(p);
		}

		// Indicates botLeftTree
		else {
			if (botLeftTree == NULL)
				return NULL;
			return botLeftTree->search(p);
		}
	}
	else {
		// Indicates topRightTree
		if ((topLeft.y + botRight.y) / 2 >= p.y) {
			if (topRightTree == NULL)
				return NULL;
			return topRightTree->search(p);
		}

		// Indicates botRightTree
		else {
			if (botRightTree == NULL)
				return NULL;
			return botRightTree->search(p);
		}
	}
};

// Check if current quadtree contains the point
bool no_PR_Quadtree::inBoundary(Point2D p)
{
	return (p.x >= topLeft.x && p.x <= botRight.x
			&& p.y >= topLeft.y && p.y <= botRight.y);
}

// Driver program
int main()
{
	no_PR_Quadtree raiz(Point2D(0, 0), Point2D(8, 8));
	Reg_Node a(Point2D(1, 1), 11);
	Reg_Node b(Point2D(2, 5), 22);
	Reg_Node c(Point2D(7, 6), 33);
	Reg_Node d(Point2D(5, 5), 44);
	Reg_Node e(Point2D(7, 5), 55);
	raiz.insert(&a);
	raiz.insert(&b);
	raiz.insert(&c);
	cout << "Aqui vai dar split " << endl;
	raiz.insert(&d);
	raiz.insert(&e);
	cout << "Node a: " << raiz.search(Point2D(1, 1))->data << endl;
	cout << "Node b: " << raiz.search(Point2D(2, 5))->data << endl;
	cout << "Node c: " << raiz.search(Point2D(7, 6))->data << endl;
	cout << "Node d: " << raiz.search(Point2D(5, 5))->data << endl;
	cout << "Node e: " << raiz.search(Point2D(7, 5))->data << endl;
	cout << "Non-existing node: " << raiz.search(Point2D(6, 6)) << endl;
	return 0;
}
