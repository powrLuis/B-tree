#include "node.h"
// inserta un elemento en nodo hoja
bool node::insert(int val)
{
    if (!is_leaf)
    {
        return false;
    }
    values.push_back(val);
    // TODO: se necesita implementar correctamente esta funcion. Debe insertarse los elementos en orden.
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
    return (children.size() >= orden);
}
