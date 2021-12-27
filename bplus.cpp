#include "bplus.h"


// Inserta un elemento al arbol
void bplus::insert(int val)
{
    node* actual = findleaf(val);

    // TODO: Agregar aquí el código de implementación.
}

bplus::bplus(int ord)
{
    order = ord;
    root = new node(order);
}

//Imprime el arbol
void bplus::print()
{
    // TODO: Agregar aquí el código de implementación.
}


// busca el nodo hoja al cual meter el valor
bplus::node* bplus::findleaf(int val)
{
    // TODO: Agregar aquí el código de implementación.
    return nullptr;
}


// informa si el elemento buscado esta en el arbol
bool bplus::find(int val)
{
    // TODO: Agregar aquí el código de implementación.
    return false;
}


// busqueda por rango
std::vector<int> bplus::find_range(int min, int max)
{
    // TODO: Agregar aquí el código de implementación.
    return std::vector<int>();
}


// inserta un elemento en nodo hoja
bool bplus::node::insert(int val)
{
    if (!is_leaf)
    {
        return false;
    }
    values.push_back(val);
    // TODO: se necesita implementar correctamente esta funcion. Debe insertarse los elementos en orden.
    return true;
}

bool bplus::node::insert(int val, node* nodo)
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
bool bplus::node::is_overfull()
{
    return (children.size() >= orden);
}
