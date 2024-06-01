// AISD-2.cpp: определяет точку входа для приложения.
//

#include "LinkedList.h"

using namespace std;


int main()
{
	cout << "Insert test \n";
	int array[9];
	for (int i = 0; i < 9; i++)
	{
		array[i] = i;
	}
	SearchTree test = SearchTree();
	test.insert_all(array, 9);
	test.print_all();

	cout << "\nDelete test\n";
	cout << test.erase(5) << "\n";
	test.print_all();
}
