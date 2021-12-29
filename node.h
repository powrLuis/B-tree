#pragma once
#include <vector>
class node
{
public:
	std::vector<char> values;
	std::vector<node*> children;
	node *next, *father;
	int count{ 0 };
	int orden;
	bool is_leaf{ false };
	node(int ord)
	{
		orden = ord;
		next = nullptr;
		father = nullptr;
	}
	// inserta un elemento en nodo hoja
	bool insert(int val);
	//inserta un valor y un puntero a un nodo
	bool insert(int val, node* nodo);
	// retorna true si esta lleno y necesita ser dividido
	bool is_overfull();
	// divide al nodo, comportamiento depende de si es hoja o no. Regresa puntero al padre.
	node* split();
};

