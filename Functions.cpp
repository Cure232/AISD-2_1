// AISD-2.cpp: определяет точку входа для приложения.
//

#include "include/SearchTree.h"
#include <vector>
#include <string>

using namespace mysearchtree;
using namespace std;


size_t lcg() {
	static size_t x = 0;
	x = (1021 * x + 24631) % 116640;
	return x;
}

vector<int> get_all_duplicates(const vector<int>& v) {
	SearchTree st = SearchTree();
	vector<int> result;
	for (int i : v)
	{
		if (st.contains(i)) {
			result.push_back(i);
		}
		else st.insert(i);
	}
	return result;
}

SearchTree create_test_tree(int size) {
	SearchTree test_tree = SearchTree();
	for (int i = 0; i < size; i++)
	{
		int x = lcg();
		test_tree.insert(x);
	}
	return test_tree;
}

vector<int> create_test_vector(int size) {
	vector<int> test_vector;
	for (int i = 0; i < size; i++)
	{
		int x = lcg();
		test_vector.push_back(x);
	}
	return test_vector;
}

void insert_into_set(SearchTree& st) {
	int x = lcg();
	bool result = st.insert(x);
	//cout << "insert status - " << result << endl;
}

void insert_into_vector(vector<int>& v) {
	int x = lcg();
	v.push_back(x);
	//cout << "vector insert successful" << endl;
}

void search_set(SearchTree& st) {
	int x = lcg();
	bool result = st.contains(x);
	cout << "set contains " << x << " - " << result << endl;
}

void search_vector(vector<int>& v) {
	int x = lcg();

	bool result = false;
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

void erase_from_set(SearchTree& st) {
	int x = lcg();
	bool result = st.erase(x);
	cout << x << " was erased from set" << " - " << result << endl;
}

void erase_from_vector(vector<int>& v) {
	int x = lcg();
	bool result = false;

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
