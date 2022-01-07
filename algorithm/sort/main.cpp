#include <iostream>
#include <vector>
#include <algorithm>

#include "quick_sort/quick_sort.hpp"
#include "merge_sort/merge_sort.hpp"
#include "insertion_sort/insertion_sort.hpp"
#include "bubble_sort/bubble_sort.hpp"
#include "selection_sort/selection_sort.hpp"

#define PRINT                                                                  \
	std::copy(                                                                 \
		nums.begin(), nums.end(), std::ostream_iterator<int>(std::cout, " ")); \
	std::cout << "\n";

void
sort()
{
	std::vector<int> nums = {
		1, 3, 5, 7, 2, 6, 4, 8, 9, 2, 8, 7, 6, 0, 3, 5, 9, 4, 1, 0};
	std::vector<int> temp(nums.size());

	std::random_shuffle(nums.begin(), nums.end());
	PRINT
	std::sort(nums.begin(), nums.end());
	PRINT

	std::random_shuffle(nums.begin(), nums.end());
	PRINT
	quick_sort(nums, 0, static_cast<int>(nums.size()));
	PRINT

	std::random_shuffle(nums.begin(), nums.end());
	PRINT
	merge_sort(nums, 0, static_cast<int>(nums.size()), temp);
	PRINT
}

int
main()
{
	std::cout << "Hello World\n";
	sort();
	return 0;
}