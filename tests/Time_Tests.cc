#include <gtest/gtest.h>
#include <SearchTree.h>
#include <iostream>
#include <fstream>
#include <chrono>
#include "../AISD-2.cpp"

using namespace std;
using namespace mysearchtree;

const int attempts = 100;
ofstream results_file;

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
	results_file.open("../../../results.txt");
	create_test_trees();

	::testing::InitGoogleTest(&argc, argv);
	::testing::UnitTest* all_tests = ::testing::UnitTest::GetInstance();
	auto result(RUN_ALL_TESTS());
	::testing::internal::TimeInMillis elapsed(all_tests->elapsed_time());
	cout << result << endl;

	results_file.close();
}


//The average filling time is 1000, 10000 and 100000 unique random numbers (100 tries);
TEST(AverageFillingTime, 1000_numbers) {

	double my_set_average;
	double vector_average;

	ASSERT_NO_THROW(my_set_average = get_average_interaction_time(attempts, 1000, fill_set));
	ASSERT_NO_THROW(vector_average = get_average_interaction_time(attempts, 1000, fill_vector));

	results_file << this->test_info_->test_case_name() << " " << this->test_info_->name() << endl;
	results_file << "my_set_average: " << my_set_average << endl;
	results_file << "vector_average: " << vector_average << endl;
	cout << "my_set_average: " << my_set_average << endl;
	cout << "vector_average: " << vector_average << endl;
}

TEST(AverageFillingTime, 10000_numbers) {
	double my_set_average;
	double vector_average;

	ASSERT_NO_THROW(my_set_average = get_average_interaction_time(attempts, 10000, fill_set));
	ASSERT_NO_THROW(vector_average = get_average_interaction_time(attempts, 10000, fill_vector));

	results_file << this->test_info_->test_case_name() << " " << this->test_info_->name() << endl;
	results_file << "my_set_average: " << my_set_average << endl;
	results_file << "vector_average: " << vector_average << endl;
	cout << "my_set_average: " << my_set_average << endl;
	cout << "vector_average: " << vector_average << endl;
}

TEST(AverageFillingTime, 100000_numbers) {
	double my_set_average;
	double vector_average;

	ASSERT_NO_THROW(my_set_average = get_average_interaction_time(attempts, 100000, fill_set));
	ASSERT_NO_THROW(vector_average = get_average_interaction_time(attempts, 100000, fill_vector));

	results_file << this->test_info_->test_case_name() << " " << this->test_info_->name() << endl;
	results_file << "my_set_average: " << my_set_average << endl;
	results_file << "vector_average: " << vector_average << endl;
	cout << "my_set_average: " << my_set_average << endl;
	cout << "vector_average: " << vector_average << endl;
}

TEST(AverageSearchTime, 1000_numbers) {
	double my_set_average;
	double vector_average;

	ASSERT_NO_THROW(my_set_average = get_average_interaction_time(attempts, 1000, search_set));
	ASSERT_NO_THROW(vector_average = get_average_interaction_time(attempts, 1000, search_vector));

	results_file << this->test_info_->test_case_name() << " " << this->test_info_->name() << endl;
	results_file << "my_set_average: " << my_set_average << endl;
	results_file << "vector_average: " << vector_average << endl;
	cout << "my_set_average: " << my_set_average << endl;
	cout << "vector_average: " << vector_average << endl;
}

TEST(AverageSearchTime, 10000_numbers) {
	double my_set_average;
	double vector_average;

	ASSERT_NO_THROW(my_set_average = get_average_interaction_time(attempts, 10000, search_set));
	ASSERT_NO_THROW(vector_average = get_average_interaction_time(attempts, 10000, search_vector));

	results_file << this->test_info_->test_case_name() << " " << this->test_info_->name() << endl;
	results_file << "my_set_average: " << my_set_average << endl;
	results_file << "vector_average: " << vector_average << endl;
	cout << "my_set_average: " << my_set_average << endl;
	cout << "vector_average: " << vector_average << endl;
}

TEST(AverageSearchTime, 100000_numbers) {
	double my_set_average;
	double vector_average;

	ASSERT_NO_THROW(my_set_average = get_average_interaction_time(attempts, 100000, search_set));
	ASSERT_NO_THROW(vector_average = get_average_interaction_time(attempts, 100000, search_vector));

	results_file << this->test_info_->test_case_name() << " " << this->test_info_->name() << endl;
	results_file << "my_set_average: " << my_set_average << endl;
	results_file << "vector_average: " << vector_average << endl;
	cout << "my_set_average: " << my_set_average << endl;
	cout << "vector_average: " << vector_average << endl;
}

TEST(AverageDeleteTime, 1000_numbers) {
	double my_set_average;
	double vector_average;

	ASSERT_NO_THROW(my_set_average = get_average_interaction_time(attempts, 1000, erase_from_set));
	ASSERT_NO_THROW(vector_average = get_average_interaction_time(attempts, 1000, erase_from_vector));

	results_file << this->test_info_->test_case_name() << " " << this->test_info_->name() << endl;
	results_file << "my_set_average: " << my_set_average << endl;
	results_file << "vector_average: " << vector_average << endl;
	cout << "my_set_average: " << my_set_average << endl;
	cout << "vector_average: " << vector_average << endl;
}

TEST(AverageDeleteTime, 10000_numbers) {
	double my_set_average;
	double vector_average;

	ASSERT_NO_THROW(my_set_average = get_average_interaction_time(attempts, 10000, erase_from_set));
	ASSERT_NO_THROW(vector_average = get_average_interaction_time(attempts, 10000, erase_from_vector));

	results_file << this->test_info_->test_case_name() << " " << this->test_info_->name() << endl;
	results_file << "my_set_average: " << my_set_average << endl;
	results_file << "vector_average: " << vector_average << endl;
	cout << "my_set_average: " << my_set_average << endl;
	cout << "vector_average: " << vector_average << endl;
}

TEST(AverageDeleteTime, 100000_numbers) {
	double my_set_average;
	double vector_average;

	ASSERT_NO_THROW(my_set_average = get_average_interaction_time(attempts, 100000, erase_from_set));
	ASSERT_NO_THROW(vector_average = get_average_interaction_time(attempts, 100000, erase_from_vector));

	results_file << this->test_info_->test_case_name() << " " << this->test_info_->name() << endl;
	results_file << "my_set_average: " << my_set_average << endl;
	results_file << "vector_average: " << vector_average << endl;
	cout << "my_set_average: " << my_set_average << endl;
	cout << "vector_average: " << vector_average << endl;
}


