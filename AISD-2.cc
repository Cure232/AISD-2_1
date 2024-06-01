// AISD-2.cpp: определяет точку входа для приложения.
//

#include "include/SearchTree.h"

using namespace std;

size_t lcg() {
	static size_t x = 0;
	x = (1021 * x + 24631) % 116640;
	return x;
}
