#pragma once
#include <vector>
class bplus
{
	struct node
	{
		int orden;
		std::vector<char> values;
		std::vector<node*> children;
		node* right, *left, *father;
		int count{ 0 };
		bool is_leaf{false};
		node(int ord ) 
		{
			orden = ord;
			right = nullptr;
			left = nullptr;
			father = nullptr;
		}
		// inserta un elemento en nodo hoja
		bool insert(int val);
		//inserta un valor y un puntero a un nodo
		bool insert(int val, node* nodo);
		// retorna true si esta lleno y necesita ser dividido
		bool is_overfull();
		
	};
public:
	//constructor
	bplus(int ord = 3);
	// Inserta un elemento al arbol
	void insert(int val);
	//imprime el arbol
	void print();
	// informa si el elemento buscado esta en el arbol
	bool find(int val);
	// busqueda por rango
	std::vector<int> find_range(int min, int max);
private:
	// busca el nodo hoja al cual meter el valor
	node* findleaf(int val);
	// Nodo raiz
	node* root;
	// orden del arbol
	int order;
	
};
