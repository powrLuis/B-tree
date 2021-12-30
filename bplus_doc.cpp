#include "bplus_doc.h"
// bplus doc

// Inserta un elemento al arbol
void bplus_doc::insert(int val)
{
    auto actual = findleaf(val);
    actual->insert(val);
    while (actual->is_overfull())
    {
        int temp=actual->split();
        actual = node_doc::cargar(temp);
    }
    if (actual->father==-1)
    {
        root = actual->id;
    }
    // insertar valor en la hoja
    // verificar que este lleno
    // si esta lleno hacer split
    // repetir hasta llegar a la raiz o no se necesite un split.
    // TODO: Agregar aquí el código de implementación.
}

bplus_doc::bplus_doc(int ord)
{
    order = ord;
    
    auto temp = new node_doc(order);
    root = temp->id;
    temp->is_leaf = true;

}

//Imprime el arbol
void bplus_doc::print()
{
    // TODO: Agregar aquí el código de implementación.
}


// busca el nodo hoja al cual meter el valor
node_doc* bplus_doc::findleaf(int val)
{
    ////Desde aquí modifico el findleaf
    //int i = 0;
    //while (i < n && k > keys[i])
    //    i++;

    //// If the found key is equal to k, return this node
    //if (keys[i] == k)
    //    return this;

    //// If the key is not found here and this is a leaf node
    //if (leaf == true)
    //    return NULL;

    //// Go to the appropriate child
    //return C[i]->search(k);

    node_doc* actual = node_doc::cargar(root);
    while (!actual->is_leaf)
    {
        actual = node_doc::cargar(actual->children[0]);
    }
    // nodo actual= root;
    // while actual no sea hoja
    // actual.is_leaf()
    // 
    // TODO: Agregar aquí el código de implementación.
    return actual;
}


// informa si el elemento buscado esta en el arbol
bool bplus_doc::find(int val)
{
    // TODO: Agregar aquí el código de implementación.
    return false;
}


// busqueda por rango
std::vector<int> bplus_doc::find_range(int min, int max)
{
    // TODO: Agregar aquí el código de implementación.
    return std::vector<int>();
}


