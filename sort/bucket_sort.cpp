#include "bucket_sort.hpp"

#include <unordered_map>
#include <utility>
namespace algorithm {
namespace sort {

std::vector<int>
topKFrequent(std::vector<int> &nums, int k)
{
	std::unordered_map<int, int> counts;
	int max_count = 0;
	for (int num : nums) {
		max_count = std::max(max_count, ++counts[num]);
	}

	std::vector<std::vector<int> > buckets(max_count + 1);
	for (const auto &p : counts) {
		buckets[p.second].push_back(p.first);
	}

	std::vector<int> ans;
	for (int i = max_count; i >= 0 && ans.size() < k; --i) {
		for (const int &num : buckets[i]) {
			ans.push_back(num);
			if (ans.size() == k) {
				break;
			}
		}
	}

	return ans;
}

} // namespace sort
} // namespace algorithm