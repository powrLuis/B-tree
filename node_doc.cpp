#include "node_doc.h"
#include <fstream>
#include <string>
using namespace std;

node_doc::node_doc()
{
    orden = -1;
    father = -1;
    next = -1;
}

node_doc::node_doc(int ord)
{
    static int identifiers = 0;
    orden = ord;
    father = -1;
    next = -1;
    id = identifiers++;
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
        while (pos < values.size() && values[pos] < val)
        {
            pos++;
        }
        values.insert(values.begin() + pos, val);
    }
    update();
    return true;
}

bool node_doc::insert(int val, int nodo)
{
    int pos = 0;
    if (is_leaf)
    {
        return false;
    }
    if (values.size() == 0)
    {
        values.push_back(val);
    }
    else
    {

        while (pos < values.size() && values[pos] < val)
        {
            pos++;
        }

        values.insert(values.begin() + pos, val);
    }

    children.insert(children.begin() + pos + 1, nodo);
    update();
    return true;
}


// retorna true si esta lleno y necesita ser dividido
bool node_doc::is_overfull()
{
    return (values.size() >= orden);
}

node_doc node_doc::cargar(int id)
{
    auto name = std::to_string(id);
    name = "btree/" + name + ".txt";
    fstream archivo;
    int info_order;
    int size;
    archivo.open(name, ios::_Nocreate|ios::in);
    node_doc temp;
    archivo >> temp.orden;
    archivo >> temp.id;
    archivo >> temp.is_leaf;
    archivo >> temp.father;
    archivo >> temp.next;
    archivo >> size;
    for (size_t i = 0; i < size; i++)
    {
        char val;
        archivo >> val;
        temp.values.push_back(val);
    }
    if (!temp.is_leaf)
    {
        for (size_t i = 0; i < size+1; i++)
        {
            int val;
            archivo >> val;
            temp.children.push_back(val);
        }
    }
    archivo.close();

    return temp;
}



// divide al nodo que no es hoja, el elemento del medio sube arriba. Regresa puntero al padre.
int node_doc::split()
{
    int center = orden / 2;
    node_doc right(orden);
    right.is_leaf = is_leaf;
    if (is_leaf)
    {
        for (size_t i = center; i < values.size(); i++)
        {
            right.values.push_back(values[i]);
        }
        right.next = next;
        next = right.id;
    }
    else
    {
        for (size_t i = center + 1; i < values.size(); i++)
        {
            right.values.push_back(values[i]);
        }
        for (size_t i = center + 1; i < children.size(); i++)
        {
            right.children.push_back(children[i]);
        }
        children.resize(center + 1);
    }
    node_doc dad;
    if (father==-1)
    {
        dad = node_doc(orden);
        dad.children.push_back(id);
        father = dad.id;
    }
    else
    {
        dad = cargar(father);
    }
    dad.insert(values[center], right.id);
    right.father = father;
    values.resize(center);
    update();
    right.update();
    dad.update();
    return father;
}

void node_doc::update()
{
    auto name = std::to_string(id);
    name = "btree/" + name + ".txt";
    fstream archivo;
    archivo.open(name, ios::trunc | ios::out);
    archivo << orden << endl;
    archivo << id << endl;
    archivo << is_leaf << endl;
    archivo << father << endl;
    archivo << next << endl;
    archivo << values.size() << endl;
    for (size_t i = 0; i < values.size(); i++)
    {
        archivo << values[i]<<endl;
    }
    for (size_t i = 0; i < children.size(); i++)
    {
        archivo << children[i] << endl;
    }
    archivo.close();
}
