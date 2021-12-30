// B+tree.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
// demo1
//probar clonacion
//nuevo comentario dasd

//probar creacion de ueva rama
//ingresando desde la web


#include <iostream>
#include <vector>
#include "btree.h"
#include "bplus.h"
#include "bplus_doc.h"

int main()
{
	bplus_doc bp(5);
	btree bt;
	std::string data = "zxmnpoiyqwertyuip07632123";
	for (auto v : data)
	{
		bp.insert(v);
	}
	bp.print();

	std::cout << "======busqueda=======" << std::endl;
	std::string consulta = "5my23";
	for (auto c : consulta)
	{
		if (bp.find(c))
		{
			std::cout << "valor " << c << " se encontro" << std::endl;
		}
		else
		{
			std::cout << "valor " << c << " no se encontro" << std::endl;
		}
	}
	std::cout << "==busqueda por rango====" << std::endl;
	auto r = bp.find_range('l', 't');
	std::cout << "valores entre l y t" << std::endl;
	for (auto v : r)
	{
		std::cout << (char)v << " ";
	}
}

