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
#include "sort/topk.hpp"

#include "search/search.hpp"

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

	std::vector<std::vector<int> > grid = {
		{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
		{0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
		{0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};
	std::cout << "maxAreaOfIsLand" << maxAreaOfIsLand(grid) << "\n";

	std::cout << "\033[1;31mbold red text\033[0m\n";
}

int
main()
{
	std::cout << "Hello World\n";
	sort();

	topKFrequent(std::vector<int>{1, 1, 1, 1, 7, 7, 3}, 2);
	return 0;
}