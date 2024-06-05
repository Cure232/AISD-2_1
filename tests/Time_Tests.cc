#include <gtest/gtest.h>
#include <SearchTree.h>

using namespace std;
using namespace mysearchtree;

size_t lcg() {
	static size_t x = 0;
	x = (1021 * x + 24631) % 116640;
	return x;
}

SearchTree test_tree1000 = SearchTree();
SearchTree test_tree10000 = SearchTree();
SearchTree test_tree100000 = SearchTree();

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
	}
	for (int i = 0; i < 10000; i++)
	{
		int x = lcg();
		test_tree10000.insert(x);
	}
	for (int i = 0; i < 100000; i++)
	{
		int x = lcg();
		test_tree100000.insert(x);
	}


	for (int i = 0; i < attempts; i++)
	{
		auto result(RUN_ALL_TESTS());
		::testing::internal::TimeInMillis elapsed(all_tests->elapsed_time());
		cout << result << endl;

		
		for (int i = 0; i < 3; i++)
		{
			average_time[i] += all_tests->GetTestSuite(0)->GetTestInfo(i)->result()->elapsed_time();
		}
		for (int i = 3; i < 6; i++)
		{
			average_time[i] += all_tests->GetTestSuite(1)->GetTestInfo(i - 3)->result()->elapsed_time();
		}
		for (int i = 6; i < 9; i++)
		{
			average_time[i] += all_tests->GetTestSuite(2)->GetTestInfo(i - 6)->result()->elapsed_time();
		}
	}

	for (int i = 0; i < 9; i++)
	{
		average_time[i] /= attempts;
	}
	cout << "AverageFillingTime, 1000_numbers: " << average_time[0] << endl;
	cout << "AverageFillingTime, 10000_numbers: " << average_time[1] << endl;
	cout << "AverageFillingTime, 10000_numbers: " << average_time[2] << endl;

	cout << "AverageSearchTime, 1000_numbers: " << average_time[3] << endl;
	cout << "AverageSearchTime, 10000_numbers: " << average_time[4] << endl;
	cout << "AverageSearchTime, 10000_numbers: " << average_time[5] << endl;

	cout << "AverageDeleteTime, 1000_numbers: " << average_time[6] << endl;
	cout << "AverageDeleteTime, 10000_numbers: " << average_time[7] << endl;
	cout << "AverageDeleteTime, 10000_numbers: " << average_time[8] << endl;
}

//The average filling time is 1000, 10000 and 100000 unique random numbers (100 tries);
TEST(AverageFillingTime, 1000_numbers) {
	SearchTree st = SearchTree();
	for (int i = 0; i < 1000; i++)
	{
		int x = lcg();
		ASSERT_TRUE(st.insert(x));
	}
}

TEST(AverageFillingTime, 10000_numbers) {
	SearchTree st = SearchTree();
	for (int i = 0; i < 10000; i++)
	{
		int x = lcg();
		ASSERT_TRUE(st.insert(x));
	}
}

TEST(AverageFillingTime, 100000_numbers) {
	SearchTree st = SearchTree();
	for (int i = 0; i < 100000; i++)
	{
		int x = lcg();
		ASSERT_TRUE(st.insert(x));
	}
}

TEST(AverageSearchTime, 1000_numbers) {
	ASSERT_NO_THROW(test_tree1000.contains(lcg()));
}

TEST(AverageSearchTime, 10000_numbers) {
	ASSERT_NO_THROW(test_tree10000.contains(lcg()));
}

TEST(AverageSearchTime, 100000_numbers) {
	ASSERT_NO_THROW(test_tree10000.contains(lcg()));
}

TEST(AverageDeleteTime, 1000_numbers) {
	int x = lcg();
	ASSERT_TRUE(test_tree10000.insert(x));
	ASSERT_TRUE(test_tree10000.erase(x));
}

TEST(AverageDeleteTime, 10000_numbers) {
	int x = lcg();
	ASSERT_TRUE(test_tree10000.insert(x));
	ASSERT_TRUE(test_tree10000.erase(x));
}

TEST(AverageDeleteTime, 100000_numbers) {
	int x = lcg();
	ASSERT_TRUE(test_tree10000.insert(x));
	ASSERT_TRUE(test_tree10000.erase(x));
}


