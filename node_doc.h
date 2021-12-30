#pragma once
#include <vector>
class node_doc
{
public:
	std::vector<char> values;
	std::vector<int> children;
	int next, father;
	int count{ 0 };
	int orden;
	bool is_leaf{ false };
	int id = 0;
	node_doc();
	node_doc(int ord);
	// inserta un elemento en nodo hoja
	bool insert(int val);
	//inserta un valor y un puntero a un nodo
	bool insert(int val, int nodo);
	// retorna true si esta lleno y necesita ser dividido
	bool is_overfull();
	// divide al nodo, comportamiento depende de si es hoja o no. Regresa puntero al padre.
	int split();
	// funcion para guardar el nodo a archivo
	void update();
	// funcion para cargar un nodo desde un archivo
	static node_doc cargar(int id);
};

