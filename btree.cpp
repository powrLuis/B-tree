#include "btree.h"

void btree::insert(int value)
{
	auto state = root.insert(value);
	if (state == state_t::Overflow)
	{
		splitRoot();
	}
}
void btree::splitRoot()
{
	std::cout << "======ROOT SPLIT==========\n";

	node* node_in_overflow = &root;
	int index = 0;
	node* ptr = new node();
	node* node1 = new node();
	node* node2 = new node();
	int n = node_in_overflow->count;
	int i;
	for (i = 0; i < n / 2; i++)
	{
		node1->children[i] = node_in_overflow->children[i];
		node1->values[i] = node_in_overflow->values[i];
		node1->count++;
	}
	node1->children[i] = node_in_overflow->children[i];
	ptr->values[index] = node_in_overflow->values[i];

	i++;
	int j = 0;
	for (; i < n; i++, j++)
	{
		node2->children[j] = node_in_overflow->children[i];
		node2->values[j] = node_in_overflow->values[i];
		node2->count++;
	}
	node2->children[j] = node_in_overflow->children[i];
	ptr->children[index] = node1;
	ptr->children[index + 1] = node2;
	ptr->count = 1;
	root = *ptr;
}
void btree::print()
{
	std::cout << "========PRINT Tree========\n";
	print(&root, 0);
	std::cout << "\n";
}
void btree::print(node* ptr, int level)
{
	if (ptr)
	{
		int i;
		for (i = ptr->count - 1; i >= 0; i--)
		{
			print(ptr->children[i + 1], level + 1);
			for (size_t k = 0; k < level; k++)
			{
				std::cout << "   ";
			}
			std::cout << ptr->values[i] << "\n";
		}
		print(ptr->children[i + 1], level + 1);
	}
}
bool btree::find(int value)
{
	return root.find(value);
}
std::vector<int> btree::find_range(int min, int max)
{
	std::vector<int> resultado;
	root.find_range(resultado, min, max);
	return resultado;
}