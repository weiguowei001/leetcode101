#include "selection_sort.hpp"

#include <utility>

namespace algorithm {
namespace sort {

void
selection_sort(vector<int> &nums, int n)
{
	using namespace std;
	for (int i = 0; i < n; ++i) {
		int min = i;
		for (int j = i + 1; j < n; ++j) {
			if (nums[j] < nums[min]) {
				min = j;
			}
		}
		swap(nums[i], nums[min]);
	}
}

} // namespace sort
} // namespace algorithm
