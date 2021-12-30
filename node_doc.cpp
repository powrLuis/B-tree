#include "node_doc.h"
#include <fstream>
#include <string>
using namespace std;

node_doc::node_doc(int ord)
{
    static int identifiers = 0;
    orden = ord;
    father = -1;
    next = -1;
    id = identifiers++;

    auto name = std::to_string(id);
    name += ".txt";
    name = "btree/" + name;
    fstream archivo;
    archivo.open(name, ios::_Noreplace);
    archivo << orden << endl;
    archivo << id << endl;
    archivo << is_leaf << endl;
    archivo.close();
}

// inserta un elemento en nodo hoja
bool node_doc::insert(int val)
{
    if (!is_leaf)
    {
        return false;
    }
    if (values.size() == 0)
    {
        values.push_back(val);
    }
    else
    {
        int pos = 0;
        while (values[pos] < val)
        {
            pos++;
        }
        values.insert(values.begin() + pos, val);
    }
    return true;
}

bool node_doc::insert(int val, int nodo)
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
bool node_doc::is_overfull()
{
    return (values.size() >= orden);
}

node_doc* node_doc::cargar(int id)
{
    auto name = std::to_string(id);
    name += ".txt";
    name = "btree/" + name;
    fstream archivo;
    archivo.open(name, ios::_Nocreate);
    //archivo << orden << endl;
    archivo << id << endl;
    //archivo << is_leaf << endl;
    archivo.close();


    node_doc* temp = new node_doc(5);
    return temp;
}



// divide al nodo que no es hoja, el elemento del medio sube arriba. Regresa puntero al padre.
int node_doc::split()
{
    int center = orden / 2;
    node_doc* right = new node_doc(orden);
    right->is_leaf = is_leaf;
    if (is_leaf)
    {
        for (size_t i = center; i < values.size(); i++)
        {
            right->values.push_back(values[i]);
        }
        right->next = next;
        next = right->id;
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
    
    if (father==-1)
    {
        auto f = new node_doc(orden);
        f->children.push_back(id);
        father = f->id;
    }
    //father->insert(values[center], right);
    right->father = father;
    values.resize(center);
    
    return father;
}
