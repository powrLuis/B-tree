#include "node.h"
#include <bits/stdc++.h>
using namespace std;

// inserta un elemento en nodo hoja
bool node::insert(int val)
{
    if (!is_leaf)
    {
        return false;
    }
    values.push_back(val);
    // TODO: se necesita implementar correctamente esta funcion. Debe insertarse los elementos en orden.
    // Program below illustrates the
// vector::insert() function



	// initialising the vector
	vector<int> vec = { 10, 20, 30, 40 };
	int cont=0;
	int val1 = 41;
    for (int x=0; x<vec.size(); x++){
        if ((val1 == vec[x]) or (val1 < vec[x] )){
            auto it = vec.insert(vec.begin() + x, val1); 
            break;
        }
        if (val1 > vec[x] and val1 < vec[x+1]){
            auto it = vec.insert(vec.begin() + x+1, val1);          
            break;            
        }
        if (val1 > vec[vec.size()-1]) {
            auto it = vec.insert(vec.end() + x, val1); 
            break; 
        }
        cont = cont + 1;
    }
	int i = 2;

	cout << "The vector elements are: ";
	for (auto it = vec.begin(); it != vec.end(); ++it)
		cout << *it << " ";


    return true;
}

bool node::insert(int val, node* nodo)
{
    if (is_leaf)
    {
        return false;
    }
    values.push_back(val);
    children.push_back(nodo);
    //TODO: se necesita implementar correctamente esta funcion.
    return true;
}


// retorna true si esta lleno y necesita ser dividido
bool node::is_overfull()
{
    return (values.size() >= orden);
}



// divide al nodo que no es hoja, el elemento del medio sube arriba. Regresa puntero al padre.
node* node::split()
{
    int center = orden / 2;
    node* right = new node(orden);
    right->is_leaf = is_leaf;
    if (is_leaf)
    {
        for (size_t i = center; i < values.size(); i++)
        {
            right->values.push_back(values[i]);
        }
        right->next = next;
        next = right;
    }
    else
    {
        for (size_t i = center + 1; i < values.size(); i++)
        {
            right->values.push_back(values[i]);
        }
        for (size_t i = center + 1; i < children.size(); i++)
        {
            right->children.push_back(children[i]);
        }
        children.resize(center + 1);
    }
    
    if (father==nullptr)
    {
        father = new node(orden);
        father->children.push_back(this);
    }
    father->insert(values[center], right);
    right->father = father;
    values.resize(center);
    
    return father;
}
