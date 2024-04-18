// AISD-2.cpp: определяет точку входа для приложения.
//

#include "LinkedList.h"

using namespace std;

template <typename T>
ostream& operator<<(ostream& os, const LinkedList<T>& ll) {
	if (ll.get_length() == 0) {
		return cout << endl;
	}
	else {
		for (int i = 0; i < ll.get_length(); i++) {
			cout << ll[i] << " ";
		}
	}
	return cout << endl;
}


int main()
{
	
	LinkedList<int> number1 = LinkedList<int>();
	number1.push_tail(1);
	number1.push_tail(2);
	number1.push_tail(3);
	cout << number1.pop_head() << number1.pop_tail() << number1.pop_tail() << endl;
	number1.push_tail(1);
	LinkedList<int> number2 = LinkedList<int>();
	number2.push_tail(2);
	number2.push_tail(2);
	number2.push_tail(2);
	
	number1.push_head(number2);
	cout << number1;
	number1.delete_node(2);
	cout << number1;

	number1.~LinkedList();
	number2.~LinkedList();

	number1.push_tail(3);
	number1.push_tail(3);
	number1.push_tail(3);

	number2.push_tail(2);
	number2.push_tail(2);

	cout << "Hard Task 2" << endl;
	int diff = number1.get_length() - number2.get_length();
	if (diff > 0) {
		for (;diff > 0; diff--)
			number2.push_head(0);
	}
	else {
		for (; diff < 0; diff++)
			number1.push_head(0);
	}

	for (int i = 0; i < number1.get_length(); i++)
		cout << number1[i]+number2[i];
}
