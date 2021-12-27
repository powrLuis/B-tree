// B+tree.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
//probar clonacion
#include <iostream>
#include <vector>
#include "btree.h"
#include "bplus.h"
int main()
{
	bplus bp;
	btree bt;
	std::string data = "zxmnpoiyqwertyuip07632123";
	for (auto v : data)
	{
		bt.insert(v);
	}
	bt.print();

	std::cout << "======busqueda=======" << std::endl;
	std::string consulta = "5my23";
	for (auto c : consulta)
	{
		if (bt.find(c))
		{
			std::cout << "valor " << c << " se encontro" << std::endl;
		}
		else
		{
			std::cout << "valor " << c << " no se encontro" << std::endl;
		}
	}
	std::cout << "==busqueda por rango====" << std::endl;
	auto r = bt.find_range('l', 't');
	std::cout << "valores entre l y t" << std::endl;
	for (auto v : r)
	{
		std::cout << (char)v << " ";
	}

}

