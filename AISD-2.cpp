// AISD-2.cpp: определяет точку входа для приложения.
//

#include "include/SearchTree.h"
#include <vector>

using namespace mysearchtree;
using namespace std;


SearchTree test_tree1000 = SearchTree();
SearchTree test_tree10000 = SearchTree();
SearchTree test_tree100000 = SearchTree();
vector<int> test_v1000 = vector<int>();
vector<int> test_v10000 = vector<int>();
vector<int> test_v100000 = vector<int>();


size_t lcg() {
	static size_t x = 0;
	x = (1021 * x + 24631) % 116640;
	return x;
}

void create_test_trees() {
	for (int i = 0; i < 1000; i++)
	{
		int x = lcg();
		test_tree1000.insert(x);
		test_v1000.push_back(x);
	}
	for (int i = 0; i < 10000; i++)
	{
		int x = lcg();
		test_tree10000.insert(x);
		test_v10000.push_back(x);
	}
	for (int i = 0; i < 100000; i++)
	{
		int x = lcg();
		test_tree100000.insert(x);
		test_v100000.push_back(x);
	}
}

void fill_set(int size) {
	SearchTree st = SearchTree();
	for (int i = 0; i < size; i++)
	{
		int x = lcg();
		st.insert(x);
	}
	cout << "set filled" << endl;
}

void fill_vector(int size) {
	vector<int> v = vector<int>();
	for (int i = 0; i < size; i++)
	{
		int x = lcg();
		v.push_back(x);
	}
	cout << "vector filled" << endl;
}

void search_set(int size) {
	int x = lcg();
	bool result;
	if (size == 1000) {
		result = test_tree1000.contains(x);
	}
	else if (size == 10000) {
		result = test_tree10000.contains(x);
	}
	else if (size == 100000) {
		result = test_tree100000.contains(x);
	}
	cout << "set contains " << x << " - " << result << endl;
}

void search_vector(int size) {
	int x = lcg();
	vector<int> v;
	bool result = false;

	if (size == 1000) {
		v = test_v1000;
	}
	else if (size == 10000) {
		v = test_v10000;
	}
	else if (size == 100000) {
		v = test_v100000;
	}

	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] == x)
		{
			result = true;
			break;
		}
	}
	cout << "vector contains " << x << " - " << result << endl;
}

void erase_from_set(int size) {
	int x = lcg();
	bool result;
	if (size == 1000) {
		result = test_tree1000.erase(x);
	}
	else if (size == 10000) {
		result = test_tree10000.erase(x);
	}
	else if (size == 100000) {
		result = test_tree100000.erase(x);
	}
	cout << x << " was erased from set" << " - " << result << endl;
}

void erase_from_vector(int size) {
	int x = lcg();
	vector<int> v;
	bool result = false;

	if (size == 1000) {
		v = test_v1000;
	}
	else if (size == 10000) {
		v = test_v10000;
	}
	else if (size == 100000) {
		v = test_v100000;
	}

	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] == x)
		{
			v.erase(v.begin() + i);
			result = true;
			break;
		}
	}
	cout << x << " was erased from vector" << " - " << result << endl;
}
