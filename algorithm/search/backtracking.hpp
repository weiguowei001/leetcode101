#pragma once

#include <vector>

namespace algorithm {
namespace search {
namespace backtracking {

void backtracking(
	std::vector<int> nums, int level, std::vector<std::vector<int> > &ans);
std::vector<std::vector<int> > permute(std::vector<int> &nums);

} // namespace backtracking
} // namespace search
} // namespace algorithm