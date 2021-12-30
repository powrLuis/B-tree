#pragma once
#include <vector>
#include "node_doc.h"

class bplus_doc
{
public:
	//constructor
	bplus_doc(int ord = 3);
	// Inserta un elemento al arbol
	void insert(int val);
	//imprime el arbol
	void print();
	void print(int id, int level);
	// informa si el elemento buscado esta en el arbol
	bool find(int val);
	// busqueda por rango
	std::vector<int> find_range(int min, int max);
private:
	// busca el nodo hoja al cual meter el valor
	node_doc findleaf(int val);
	// Nodo raiz
	int root;
	// orden del arbol
	int order;
	
};
