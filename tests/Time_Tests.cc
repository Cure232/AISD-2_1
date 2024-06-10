#include <gtest/gtest.h>
#include <SearchTree.h>
#include <chrono>

using namespace std;
using namespace mysearchtree;


SearchTree test_tree1000 = SearchTree();
SearchTree test_tree10000 = SearchTree();
SearchTree test_tree100000 = SearchTree();
vector<int> test_v1000 = vector<int>();
vector<int> test_v10000 = vector<int>();
vector<int> test_v100000 = vector<int>();
int attempts = 100;


size_t lcg() {
	static size_t x = 0;
	x = (1021 * x + 24631) % 116640;
	return x;
}

double get_average_interaction_time(int attempts, int size, void(*function)(int)) {
	double average_duration = 0;

	for (int i = 0; i < attempts; i++)
	{
		cout << "attempt" << i << ":\n";

		auto start = chrono::steady_clock::now();
		function(size);
		auto end = chrono::steady_clock::now();

		chrono::duration<double> duration = end - start;
		average_duration += duration.count();
	}

	average_duration /= attempts;
	return average_duration;
}


int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	::testing::UnitTest* all_tests = ::testing::UnitTest::GetInstance();
	int average_time[9];
	for (int i = 0; i < 9; i++) average_time[i] = 0;
	int attempts = 10;

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

	auto result(RUN_ALL_TESTS());
	::testing::internal::TimeInMillis elapsed(all_tests->elapsed_time());
	cout << result << endl;
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

//The average filling time is 1000, 10000 and 100000 unique random numbers (100 tries);
TEST(AverageFillingTime, 1000_numbers) {

	double my_set_average;
	double vector_average;

	ASSERT_NO_THROW(my_set_average = get_average_interaction_time(attempts, 1000, fill_set));
	ASSERT_NO_THROW(vector_average = get_average_interaction_time(attempts, 1000, fill_vector));

	cout << "my_set_average: " << my_set_average << endl;
	cout << "vector_average: " << vector_average << endl;
}

TEST(AverageFillingTime, 10000_numbers) {
	double my_set_average;
	double vector_average;

	ASSERT_NO_THROW(my_set_average = get_average_interaction_time(attempts, 10000, fill_set));
	ASSERT_NO_THROW(vector_average = get_average_interaction_time(attempts, 10000, fill_vector));

	cout << "my_set_average: " << my_set_average << endl;
	cout << "vector_average: " << vector_average << endl;
}

TEST(AverageFillingTime, 100000_numbers) {
	double my_set_average;
	double vector_average;

	ASSERT_NO_THROW(my_set_average = get_average_interaction_time(attempts, 100000, fill_set));
	ASSERT_NO_THROW(vector_average = get_average_interaction_time(attempts, 100000, fill_vector));

	cout << "my_set_average: " << my_set_average << endl;
	cout << "vector_average: " << vector_average << endl;
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

TEST(AverageSearchTime, 1000_numbers) {
	double my_set_average;
	double vector_average;

	ASSERT_NO_THROW(my_set_average = get_average_interaction_time(attempts, 1000, search_set));
	ASSERT_NO_THROW(vector_average = get_average_interaction_time(attempts, 1000, search_vector));

	cout << "my_set_average: " << my_set_average << endl;
	cout << "vector_average: " << vector_average << endl;
}

TEST(AverageSearchTime, 10000_numbers) {
	double my_set_average;
	double vector_average;

	ASSERT_NO_THROW(my_set_average = get_average_interaction_time(attempts, 10000, search_set));
	ASSERT_NO_THROW(vector_average = get_average_interaction_time(attempts, 10000, search_vector));

	cout << "my_set_average: " << my_set_average << endl;
	cout << "vector_average: " << vector_average << endl;
}

TEST(AverageSearchTime, 100000_numbers) {
	double my_set_average;
	double vector_average;

	ASSERT_NO_THROW(my_set_average = get_average_interaction_time(attempts, 100000, search_set));
	ASSERT_NO_THROW(vector_average = get_average_interaction_time(attempts, 100000, search_vector));

	cout << "my_set_average: " << my_set_average << endl;
	cout << "vector_average: " << vector_average << endl;
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

TEST(AverageDeleteTime, 1000_numbers) {
	double my_set_average;
	double vector_average;

	ASSERT_NO_THROW(my_set_average = get_average_interaction_time(attempts, 1000, erase_from_set));
	ASSERT_NO_THROW(vector_average = get_average_interaction_time(attempts, 1000, erase_from_vector));

	cout << "my_set_average: " << my_set_average << endl;
	cout << "vector_average: " << vector_average << endl;
}

TEST(AverageDeleteTime, 10000_numbers) {
	double my_set_average;
	double vector_average;

	ASSERT_NO_THROW(my_set_average = get_average_interaction_time(attempts, 10000, erase_from_set));
	ASSERT_NO_THROW(vector_average = get_average_interaction_time(attempts, 10000, erase_from_vector));

	cout << "my_set_average: " << my_set_average << endl;
	cout << "vector_average: " << vector_average << endl;
}

TEST(AverageDeleteTime, 100000_numbers) {
	double my_set_average;
	double vector_average;

	ASSERT_NO_THROW(my_set_average = get_average_interaction_time(attempts, 100000, erase_from_set));
	ASSERT_NO_THROW(vector_average = get_average_interaction_time(attempts, 100000, erase_from_vector));

	cout << "my_set_average: " << my_set_average << endl;
	cout << "vector_average: " << vector_average << endl;
}


