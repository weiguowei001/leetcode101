#include "bubble_sort.hpp"
#include <utility>

void
bubble_sort(std::vector<int> &nums, int n)
{
	using namespace std;
	bool swapped;
	for (int i = 1; i < n; ++i) {
		swapped = false;
		for (int j = 1; j < n - i + 1; ++j) {
			if (nums[j] < nums[j - 1]) {
				swap(nums[j], nums[j - 1]);
				swapped = true;
			}
		}
		if (!swapped) {
			break;
		}
	}
}