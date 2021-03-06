#include "bplus_doc.h"
#include <iostream>
// bplus doc

// Inserta un elemento al arbol
void bplus_doc::insert(int val)
{
    auto actual = findleaf(val);    // nos devuelve un nodo el cual almmacenamos en actual
    actual.insert(val);             // procedemos a insertar el valor recibido en el nodo correspondiente (de la anterior línea)
    while (actual.is_overfull())
    {
        int temp=actual.split();
        actual = node_doc::cargar(temp);
    }
    if (actual.father==-1)
    {
        root = actual.id;
    }
}

bplus_doc::bplus_doc(int ord)
{
    order = ord;
    
    auto temp = new node_doc(order);
    root = temp->id;
    temp->is_leaf = true;
    temp->update();
}

//Imprime el arbol
void bplus_doc::print()
{
    print(root, 0);
}

void bplus_doc::print(int id, int level)
{
    if (id!=-1)
    {
        int i;
        auto ptr = node_doc::cargar(id);
        for (i = ptr.values.size() - 1; i >= 0; i--)
        {
            if (!ptr.is_leaf)
                print(ptr.children[i + 1], level + 1);
            for (size_t k = 0; k < level; k++)
            {
                std::cout << "   ";
            }
            std::cout << ptr.values[i] << "\n";
        }
        if (!ptr.is_leaf)
            print(ptr.children[i + 1], level + 1);
    }
}


// busca el nodo hoja al cual meter el valor
node_doc bplus_doc::findleaf(int val)
{
    node_doc actual = node_doc::cargar(root);
    while (!actual.is_leaf)
    {
        int temp = 0;
        for (int a = 0; a < actual.values.size(); a++) {
            if (actual.values[a] < val) {
                temp++;
            }
        }
        actual = node_doc::cargar(actual.children[temp]);
    }
    return actual;
}


// informa si el elemento buscado esta en el arbol
bool bplus_doc::find(int val)
{
    node_doc actual = findleaf(val);
    for (int a = 0; a < actual.values.size(); a++) {
        if (actual.values[a] == val) {
            return true;
        }
    }
    return false;
}


// busqueda por rango
std::vector<int> bplus_doc::find_range(int min, int max)
{
    std::vector<int> vec = {};
    node_doc actual = findleaf(min);
    int temp = 0;
    bool mantieneBucle = true;
    while (mantieneBucle)
    {
        for (int a=0; a < actual.values.size(); a++) {
            if (actual.values[a] < min) { continue; }
            if (actual.values[a] > max) { mantieneBucle = false;          break; }
            vec.push_back(actual.values[a]);
        }
        if (actual.next == -1) { break; }
        actual = node_doc::cargar(actual.next);
    }
    return vec;
}


