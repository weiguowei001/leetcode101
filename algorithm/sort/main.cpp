#include <iostream>
#include <vector>
#include <algorithm>

#include "quick_sort/quick_sort.hpp"
#include "merge_sort/merge_sort.hpp"
#include "insertion_sort/insertion_sort.hpp"
#include "bubble_sort/bubble_sort.hpp"
#include "selection_sort/selection_sort.hpp"

void
sort()
{
	std::vector<int> nums = {
		1, 3, 5, 7, 2, 6, 4, 8, 9, 2, 8, 7, 6, 0, 3, 5, 9, 4, 1, 0};
	// std::sort(nums.begin(), nums.end());
	quick_sort(nums, 0, nums.size());
	for (auto num : nums) {
		std::cout << num << " ";
	}
	std::cout << "\n";
}

int
main()
{
	std::cout << "Hello World\n";
	sort();
	return 0;
}