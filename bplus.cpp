#include "bplus.h"
#include <iostream>

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
    print(root, 0);
}

void bplus::print(node* ptr, int level)
{
	if (ptr)
	{
		int i;
		for (i = ptr->values.size() - 1; i >= 0; i--)
		{
            if(!ptr->is_leaf)
			    print(ptr->children[i + 1], level + 1);
			for (size_t k = 0; k < level; k++)
			{
				std::cout << "   ";
			}
			std::cout << ptr->values[i] << "\n";
		}
        if(!ptr->is_leaf)
		    print(ptr->children[i + 1], level + 1);
	}
}

// busca el nodo hoja al cual meter el valor
node* bplus::findleaf(int val)
{
   node* actual = root;
    while (!actual->is_leaf)
    {
      int temp = 0;
      for (int a=0; a<actual->values.size(); a++){
          if (actual->values[a] < val){
            temp++;
          }            
      }       
      actual = actual->children[temp];
    }
    return actual;
}


// informa si el elemento buscado esta en el arbol
bool bplus::find(int val)
{
      node* actual = findleaf(val);
      for (int a=0; a<actual->values.size(); a++){
        if (actual->values[a] == val){
          return true;
        }
      }
    return false;
}


// busqueda por rango
std::vector<int> bplus::find_range(int min, int max)
{
  std::vector<int> vec = {};
  node* actual = findleaf(min);
  int temp = 0;
  bool mantieneBucle = true;
    while (mantieneBucle)
    {
      for (int a=0; a<actual->values.size(); a++){
          if (actual->values[a] < min ){continue;}
          if(actual->values[a] > max){mantieneBucle = false;          break;}
          vec.push_back(actual->values[a]);
      }
      if (actual->next == nullptr){ break;}     
      actual = actual->next;
    }
    return vec;
}
