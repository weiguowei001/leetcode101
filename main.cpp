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

using namespace algorithm::sort;
using namespace algorithm::search;

#define PRINT                                                                  \
	std::copy(                                                                 \
		nums.begin(), nums.end(), std::ostream_iterator<int>(std::cout, " ")); \
	std::cout << "\n";

void
sort()
{
	// use random device to initiate vector
	std::random_device rd;
	std::mt19937 g(rd());
	std::vector<int> nums;
	std::generate_n(std::inserter(nums, nums.end()), 10,
		[&]() -> int { return g() % 100; });
	std::vector<int> temp(nums.size());

	std::shuffle(nums.begin(), nums.end(), g);
	PRINT
	std::sort(nums.begin(), nums.end());
	PRINT

	std::shuffle(nums.begin(), nums.end(), g);
	PRINT
	quick_sort(nums, 0, static_cast<int>(nums.size()));
	PRINT

	std::shuffle(nums.begin(), nums.end(), g);
	PRINT
	merge_sort(nums, 0, static_cast<int>(nums.size()), temp);
	PRINT

	std::shuffle(nums.begin(), nums.end(), g);
	PRINT
	insertion_sort(nums, static_cast<int>(nums.size()));
	PRINT

	std::shuffle(nums.begin(), nums.end(), g);
	PRINT
	bubble_sort(nums, static_cast<int>(nums.size()));
	PRINT

	std::shuffle(nums.begin(), nums.end(), g);
	PRINT
	bubble_sort(nums, static_cast<int>(nums.size()));
	PRINT

	std::vector<std::vector<int> > grid_stack = {
		{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
		{0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
		{0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};
	std::cout << "dfs::stack::maxAreaOfIsLand: "
			  << dfs::stack::maxAreaOfIsLand(grid_stack) << "\n";

	std::vector<std::vector<int> > grid_recurisive_1 = {
		{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
		{0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
		{0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};

	std::cout << "dfs::recurisive::maxAreaOfIsLand_1: "
			  << dfs::recursive::maxAreaOfIsLand_1(grid_recurisive_1) << "\n";

	std::vector<std::vector<int> > grid_recurisive_2 = {
		{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
		{0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
		{0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};

	std::cout << "dfs::recurisive::maxAreaOfIsLand_2: "
			  << dfs::recursive::maxAreaOfIsLand_2(grid_recurisive_2) << "\n";


	std::vector<std::vector<int> > grid_bfs_queue = {
		{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
		{0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
		{0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};

	std::cout << "bfs::queue::maxAreaOfIsLand: "
			  << bfs::queue::maxAreaOfIsLand(grid_bfs_queue) << "\n";

	std::vector<std::vector<int> > friends_dfs_recursive{
		{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
	std::cout << "dfs::recursive::findCircleNum: "
			  << dfs::recursive::findCircleNum(friends_dfs_recursive) << "\n";

	std::cout << "\033[1;31mbold red text\033[0m\n";
}

int
main()
{
	std::cout << "Hello World\n";
	sort();

	std::vector<int> nums{1, 1, 1, 1, 7, 7, 3};
	topKFrequent(nums, 2);
	return 0;
}