#pragma once
#include <vector>
#include "node.h"
class bplus
{
public:
	//constructor
	bplus(int ord = 3);
	// Inserta un elemento al arbol
	void insert(int val);
	//imprime el arbol
	void print();
	void print(node* ptr, int level);  	
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
