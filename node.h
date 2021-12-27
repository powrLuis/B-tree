#pragma once
#include <vector>
class node
{
public:
	int orden;
	std::vector<char> values;
	std::vector<node*> children;
	node* right, * left, * father;
	int count{ 0 };
	bool is_leaf{ false };
	node(int ord)
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

