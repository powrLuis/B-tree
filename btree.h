#pragma once
#include <iostream>
#include <vector>
constexpr auto ORDER = 3;

enum class state_t
{
	Overflow,
	Underflow,
	OK
};
class btree
{
	struct node
	{
		std::vector<char> values;
		std::vector<node*> children;
		int count{ 0 };
		node() :values(ORDER + 1), children(ORDER + 2, nullptr) {}
		void insert_into(int index, int value)
		{
			int i = count;
			for (; i > index; i--)
			{
				values[i] = values[i - 1];
				children[i + 1] = children[i];
			}
			values[i] = value;
			children[i + 1] = children[i];
			this->count++;
		}
		state_t insert(int value)
		{
			//base
			int children_index = 0;
			while (value > values[children_index] && children_index < count)
			{
				children_index++;
			}
			if (children[children_index] == nullptr)
			{//leaf node
				insert_into(children_index, value);
			}
			else
			{//index node
				auto state = children[children_index]->insert(value);
				if (state == state_t::Overflow)
				{
					split(this, children_index);
				}
			}
			return count > ORDER ? state_t::Overflow : state_t::OK;
		}
		void split(node* ptr, int index)
		{
			node* node_in_overflow = ptr->children[index];
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
			ptr->insert_into(index, node_in_overflow->values[i]);
			i++;//skip middle
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
			//ptr->count = 1;
		}
		bool find(int value)
		{
			int index = 0;
			while (value > values[index] && index < count)
			{
				index++;
			}
			if (value == values[index])
			{
				return true;
			}
			else
			{
				if (children[index] == nullptr)
				{
					return false;
				}
				else
				{
					return children[index]->find(value);
				}
			}
		}
		void find_range(std::vector<int>& result, int min, int max)
		{
			int left = 0;
			int right = count - 1;
			//reducimos el espacio de busqueda
			while (min > values[left] && left < right)
			{
				left++;
			}
			while (max < values[right] && right>0)
			{
				right--;
			}
			for (size_t i = left; i <= right; i++)
			{
				if (children[i] != nullptr)
				{
					children[i]->find_range(result, min, max);
				}
				if (min < values[i] && values[i] < max)
				{
					result.push_back(values[i]);
				}
			}
			if (children[right + 1] != nullptr)
			{
				children[right + 1]->find_range(result, min, max);
			}
		}
	};

public:
	void insert(int value);
	void splitRoot();
	void print();
	void print(node* ptr, int level);
	bool find(int value);
	std::vector<int> find_range(int min, int max);
private:
	node root;
};