#include "bplus.h"


// Inserta un elemento al arbol
void bplus::insert(int val)
{
    node* actual = findleaf(val);
    actual->insert(val);
    while (actual->is_overfull())
    {
        actual=actual->split();
    }
    if (actual->father==nullptr)
    {
        root = actual;
    }
    // insertar valor en la hoja
    // verificar que este lleno
    // si esta lleno hacer split
    // repetir hasta llegar a la raiz o no se necesite un split.
    // TODO: Agregar aquí el código de implementación.
}

bplus::bplus(int ord)
{
    order = ord;
    root = new node(order);
    root->is_leaf = true;
}

//Imprime el arbol
void bplus::print()
{
    // TODO: Agregar aquí el código de implementación.
}


// busca el nodo hoja al cual meter el valor
node* bplus::findleaf(int val)
{
    node* actual = root;
    while (!actual->is_leaf)
    {
        actual = actual->children[0];
    }
    // TODO: Agregar aquí el código de implementación.
    return actual;
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


