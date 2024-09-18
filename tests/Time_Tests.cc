#include <gtest/gtest.h>
#include <SearchTree.h>
#include <iostream>
#include <fstream>
#include <chrono>
#include "../Functions.cpp"

using namespace std;
using namespace mysearchtree;

const int attempts = 100;
ofstream results_file;


double get_average_interaction_time(int attempts_n, SearchTree& container, void(*function)(SearchTree&), int interactions_n = 1) {
	double average_duration = 0;

	for (int i = 0; i < attempts_n; i++)
	{
		cout << "attempt" << i << ":\n";

		auto start = chrono::steady_clock::now();
		for (int j = 0; j < interactions_n; j++)
		{
			function(container);
		}
		auto end = chrono::steady_clock::now();

		chrono::duration<double> duration = end - start;
		average_duration += duration.count();
	}

	average_duration /= attempts;
	return average_duration;
}

double get_average_interaction_time(int attempts_n, vector<int>& container, void(*function)(vector<int>&), int interactions_n = 1) {
	double average_duration = 0;

	for (int i = 0; i < attempts_n; i++)
	{
		cout << "attempt" << i << ":\n";

		auto start = chrono::steady_clock::now();
		for (int j = 0; j < interactions_n; j++)
		{
			function(container);
		}
		auto end = chrono::steady_clock::now();

		chrono::duration<double> duration = end - start;
		average_duration += duration.count();
	}

	average_duration /= attempts;
	return average_duration;
}

int main(int argc, char* argv[])
{	
	results_file.open("../../../results.txt");

	::testing::InitGoogleTest(&argc, argv);
	::testing::UnitTest* all_tests = ::testing::UnitTest::GetInstance();
	auto result(RUN_ALL_TESTS());
	::testing::internal::TimeInMillis elapsed(all_tests->elapsed_time());
	cout << result << endl;

	results_file << "Total time in milisecs: " << elapsed;
	results_file.close();
}


TEST(AverageEraseTime, 1000_numbers) {
	double my_set_average;
	double vector_average;

	SearchTree my_set = create_test_tree(1000);
	vector<int> v = create_test_vector(1000);

	ASSERT_NO_THROW(my_set_average = get_average_interaction_time(attempts, my_set, erase_from_set));
	ASSERT_NO_THROW(vector_average = get_average_interaction_time(attempts, v, erase_from_vector));

	results_file << this->test_info_->test_case_name() << " " << this->test_info_->name() << endl;
	results_file << "my_set_average: " << my_set_average << endl;
	results_file << "vector_average: " << vector_average << endl;
	cout << "my_set_average: " << my_set_average << endl;
	cout << "vector_average: " << vector_average << endl;
}

TEST(AverageEraseTime, 10000_numbers) {
	double my_set_average;
	double vector_average;

	SearchTree my_set = create_test_tree(10000);
	vector<int> v = create_test_vector(10000);

	ASSERT_NO_THROW(my_set_average = get_average_interaction_time(attempts, my_set, erase_from_set));
	ASSERT_NO_THROW(vector_average = get_average_interaction_time(attempts, v, erase_from_vector));

	results_file << this->test_info_->test_case_name() << " " << this->test_info_->name() << endl;
	results_file << "my_set_average: " << my_set_average << endl;
	results_file << "vector_average: " << vector_average << endl;
	cout << "my_set_average: " << my_set_average << endl;
	cout << "vector_average: " << vector_average << endl;
}

TEST(AverageEraseTime, 100000_numbers) {
	double my_set_average;
	double vector_average;

	SearchTree my_set = SearchTree();
	my_set = create_test_tree(100000);
	vector<int> v = create_test_vector(100000);

	ASSERT_NO_THROW(my_set_average = get_average_interaction_time(attempts, my_set, erase_from_set));
	ASSERT_NO_THROW(vector_average = get_average_interaction_time(attempts, v, erase_from_vector));

	results_file << this->test_info_->test_case_name() << " " << this->test_info_->name() << endl;
	results_file << "my_set_average: " << my_set_average << endl;
	results_file << "vector_average: " << vector_average << endl;
	cout << "my_set_average: " << my_set_average << endl;
	cout << "vector_average: " << vector_average << endl;
}


//The average filling time is 1000, 10000 and 100000 unique random numbers (100 tries);
TEST(AverageFillingTime, 1000_numbers) {

	double my_set_average;
	double vector_average;

	SearchTree my_set = SearchTree();
	vector<int> v;

	ASSERT_NO_THROW(my_set_average = get_average_interaction_time(attempts, my_set, insert_into_set, 1000));
	ASSERT_NO_THROW(vector_average = get_average_interaction_time(attempts, v, insert_into_vector, 1000));

	results_file << this->test_info_->test_case_name() << " " << this->test_info_->name() << endl;
	results_file << "my_set_average: " << my_set_average << endl;
	results_file << "vector_average: " << vector_average << endl;
	cout << "my_set_average: " << my_set_average << endl;
	cout << "vector_average: " << vector_average << endl;
}

TEST(AverageFillingTime, 10000_numbers) {
	double my_set_average;
	double vector_average;

	SearchTree my_set = SearchTree();
	vector<int> v;

	ASSERT_NO_THROW(my_set_average = get_average_interaction_time(attempts, my_set, insert_into_set, 10000));
	ASSERT_NO_THROW(vector_average = get_average_interaction_time(attempts, v, insert_into_vector, 10000));

	results_file << this->test_info_->test_case_name() << " " << this->test_info_->name() << endl;
	results_file << "my_set_average: " << my_set_average << endl;
	results_file << "vector_average: " << vector_average << endl;
	cout << "my_set_average: " << my_set_average << endl;
	cout << "vector_average: " << vector_average << endl;
}

TEST(AverageFillingTime, 100000_numbers) {
	double my_set_average;
	double vector_average;

	SearchTree my_set = SearchTree();
	vector<int> v;

	ASSERT_NO_THROW(my_set_average = get_average_interaction_time(attempts, my_set, insert_into_set, 100000));
	ASSERT_NO_THROW(vector_average = get_average_interaction_time(attempts, v, insert_into_vector, 100000));

	results_file << this->test_info_->test_case_name() << " " << this->test_info_->name() << endl;
	results_file << "my_set_average: " << my_set_average << endl;
	results_file << "vector_average: " << vector_average << endl;
	cout << "my_set_average: " << my_set_average << endl;
	cout << "vector_average: " << vector_average << endl;
}

TEST(AverageInsertTime, 1000_numbers) {

	double my_set_average;
	double vector_average;

	SearchTree my_set = create_test_tree(1000);
	vector<int> v = create_test_vector(1000);

	ASSERT_NO_THROW(my_set_average = get_average_interaction_time(attempts, my_set, insert_into_set));
	ASSERT_NO_THROW(vector_average = get_average_interaction_time(attempts, v, insert_into_vector));

	results_file << this->test_info_->test_case_name() << " " << this->test_info_->name() << endl;
	results_file << "my_set_average: " << my_set_average << endl;
	results_file << "vector_average: " << vector_average << endl;
	cout << "my_set_average: " << my_set_average << endl;
	cout << "vector_average: " << vector_average << endl;
}

TEST(AverageInsertTime, 10000_numbers) {
	double my_set_average;
	double vector_average;

	SearchTree my_set = create_test_tree(10000);
	vector<int> v = create_test_vector(10000);

	ASSERT_NO_THROW(my_set_average = get_average_interaction_time(attempts, my_set, insert_into_set));
	ASSERT_NO_THROW(vector_average = get_average_interaction_time(attempts, v, insert_into_vector));

	results_file << this->test_info_->test_case_name() << " " << this->test_info_->name() << endl;
	results_file << "my_set_average: " << my_set_average << endl;
	results_file << "vector_average: " << vector_average << endl;
	cout << "my_set_average: " << my_set_average << endl;
	cout << "vector_average: " << vector_average << endl;
}

TEST(AverageInsertTime, 100000_numbers) {
	double my_set_average;
	double vector_average;

	SearchTree my_set = create_test_tree(100000);
	vector<int> v = create_test_vector(100000);

	ASSERT_NO_THROW(my_set_average = get_average_interaction_time(attempts, my_set, insert_into_set));
	ASSERT_NO_THROW(vector_average = get_average_interaction_time(attempts, v, insert_into_vector));

	results_file << this->test_info_->test_case_name() << " " << this->test_info_->name() << endl;
	results_file << "my_set_average: " << my_set_average << endl;
	results_file << "vector_average: " << vector_average << endl;
	cout << "my_set_average: " << my_set_average << endl;
	cout << "vector_average: " << vector_average << endl;
}

TEST(AverageSearchTime, 1000_numbers) {
	double my_set_average;
	double vector_average;

	SearchTree my_set = create_test_tree(1000);
	vector<int> v = create_test_vector(1000);

	ASSERT_NO_THROW(my_set_average = get_average_interaction_time(attempts, my_set, search_set));
	ASSERT_NO_THROW(vector_average = get_average_interaction_time(attempts, v, search_vector));

	results_file << this->test_info_->test_case_name() << " " << this->test_info_->name() << endl;
	results_file << "my_set_average: " << my_set_average << endl;
	results_file << "vector_average: " << vector_average << endl;
	cout << "my_set_average: " << my_set_average << endl;
	cout << "vector_average: " << vector_average << endl;
}

TEST(AverageSearchTime, 10000_numbers) {
	double my_set_average;
	double vector_average;

	SearchTree my_set = create_test_tree(10000);
	vector<int> v = create_test_vector(10000);

	ASSERT_NO_THROW(my_set_average = get_average_interaction_time(attempts, my_set, search_set));
	ASSERT_NO_THROW(vector_average = get_average_interaction_time(attempts, v, search_vector));

	results_file << this->test_info_->test_case_name() << " " << this->test_info_->name() << endl;
	results_file << "my_set_average: " << my_set_average << endl;
	results_file << "vector_average: " << vector_average << endl;
	cout << "my_set_average: " << my_set_average << endl;
	cout << "vector_average: " << vector_average << endl;
}

TEST(AverageSearchTime, 100000_numbers) {
	double my_set_average;
	double vector_average;

	SearchTree my_set = create_test_tree(100000);
	vector<int> v = create_test_vector(100000);

	ASSERT_NO_THROW(my_set_average = get_average_interaction_time(attempts, my_set, search_set));
	ASSERT_NO_THROW(vector_average = get_average_interaction_time(attempts, v, search_vector));

	results_file << this->test_info_->test_case_name() << " " << this->test_info_->name() << endl;
	results_file << "my_set_average: " << my_set_average << endl;
	results_file << "vector_average: " << vector_average << endl;
	cout << "my_set_average: " << my_set_average << endl;
	cout << "vector_average: " << vector_average << endl;
}

TEST(LabTask, Variant3) {
	vector<int> a;
	a.push_back(1);
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	a.push_back(3);
	a.push_back(5);
	a.push_back(4);
	a.push_back(5);

	vector<int> b = get_all_duplicates(a);
	for (int i : b) {
		cout << endl << i << " ";
	}
	ASSERT_EQ(b[0], 1);
	ASSERT_EQ(b[1], 3);
	ASSERT_EQ(b[2], 5);
	cout << endl;
}