#include "insertion_sort.hpp"

#include <utility>

namespace algorithm {
namespace sort {

void
insertion_sort(std::vector<int> &nums, int n)
{
	using namespace std;
	for (int i = 1; i < n; ++i) {
		for (int j = i; j > 0 && nums[j] < nums[j - 1]; --j) {
			swap(nums[j], nums[j - 1]);
		}
	}
}

} // namespace sort
} // namespace algorithm