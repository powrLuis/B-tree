#include "node.h"
//#include <bits/stdc++.h>
using namespace std;

// inserta un elemento en nodo hoja
bool node::insert(int val)
{
    if (!is_leaf)
    {
        return false;
    }
    if (values.size()==0)
    {
        values.push_back(val);
    }
    else
    {
        int pos = 0;
        while (pos < values.size() && values[pos] < val )
        {
            pos++;
        }

        values.insert(values.begin() + pos, val);
    }
    return true;
}

bool node::insert(int val, node* nodo)
{
    int pos = 0;
    if (is_leaf)
    {
        return false;
    }
    if (values.size()==0)
    {
        values.push_back(val);
    }
    else
    {

        while (pos < values.size() && values[pos] < val )
        {
            pos++;
        }

        values.insert(values.begin() + pos, val);
    }  

        children.insert(children.begin() + pos + 1, nodo);
    
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
