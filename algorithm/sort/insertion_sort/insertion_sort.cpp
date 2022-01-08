#include "insertion_sort.hpp"

#include <utility>

void
insertion_sort(std::vector<int> &nums, int n)
{
	for (int i = 1; i < n; ++i) {
		for (int j = i; j > 0 && nums[j] < nums[j - 1]; --j) {
            std::swap(nums[j], nums[j-1]);
        }
	}
}