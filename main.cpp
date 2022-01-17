#include <random>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <vector>

#include "sort/quick_sort/quick_sort.hpp"
#include "sort/merge_sort/merge_sort.hpp"
#include "sort/insertion_sort/insertion_sort.hpp"
#include "sort/bubble_sort/bubble_sort.hpp"
#include "sort/selection_sort/selection_sort.hpp"
#include "sort/quick_selection.hpp"
#include "sort/bucket_sort.hpp"

#include "search/dfs.hpp"
#include "search/bfs.hpp"

using namespace std;
using namespace algorithm::sort;
using namespace algorithm::search;

#define PRINT                                                                  \
	copy(                                                                 \
		nums.begin(), nums.end(), ostream_iterator<int>(cout, " ")); \
	cout << "\n";

void
sort()
{
	// use random device to initiate vector
	random_device rd;
	mt19937 g(rd());
	vector<int> nums;
	generate_n(inserter(nums, nums.end()), 10,
		[&]() -> int { return g() % 100; });
	vector<int> temp(nums.size());

	shuffle(nums.begin(), nums.end(), g);
	PRINT
	sort(nums.begin(), nums.end());
	PRINT

	shuffle(nums.begin(), nums.end(), g);
	PRINT
	quick_sort(nums, 0, static_cast<int>(nums.size()));
	PRINT

	shuffle(nums.begin(), nums.end(), g);
	PRINT
	merge_sort(nums, 0, static_cast<int>(nums.size()), temp);
	PRINT

	shuffle(nums.begin(), nums.end(), g);
	PRINT
	insertion_sort(nums, static_cast<int>(nums.size()));
	PRINT

	shuffle(nums.begin(), nums.end(), g);
	PRINT
	bubble_sort(nums, static_cast<int>(nums.size()));
	PRINT

	shuffle(nums.begin(), nums.end(), g);
	PRINT
	bubble_sort(nums, static_cast<int>(nums.size()));
	PRINT

	vector<vector<int> > grid_stack = {
		{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
		{0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
		{0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};
	cout << "dfs::stack::maxAreaOfIsLand: "
			  << dfs::stack::maxAreaOfIsLand(grid_stack) << "\n";

	vector<vector<int> > grid_recurisive_1 = {
		{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
		{0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
		{0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};

	cout << "dfs::recurisive::maxAreaOfIsLand_1: "
			  << dfs::recursive::maxAreaOfIsLand_1(grid_recurisive_1) << "\n";

	vector<vector<int> > grid_recurisive_2 = {
		{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
		{0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
		{0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};

	cout << "dfs::recurisive::maxAreaOfIsLand_2: "
			  << dfs::recursive::maxAreaOfIsLand_2(grid_recurisive_2) << "\n";


	vector<vector<int> > grid_bfs_queue = {
		{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
		{0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
		{0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};

	cout << "bfs::queue::maxAreaOfIsLand: "
			  << bfs::queue::maxAreaOfIsLand(grid_bfs_queue) << "\n";

	vector<vector<int> > friends_dfs_recursive{
		{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
	cout << "dfs::recursive::findCircleNum: "
			  << dfs::recursive::findCircleNum(friends_dfs_recursive) << "\n";

	cout << "\033[1;31mbold red text\033[0m\n";
}

int
main()
{
	cout << "Hello World\n";
	sort();

	vector<int> nums{1, 1, 1, 1, 7, 7, 3};
	topKFrequent(nums, 2);
	return 0;
}