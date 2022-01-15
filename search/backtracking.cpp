#include "backtracking.hpp"
#include <utility>

namespace algorithm {
namespace search {
namespace backtracking {

void
backtracking(
	std::vector<int> nums, int level, std::vector<std::vector<int> > &ans)
{
	if (level == nums.size() - 1) {
		ans.push_back(nums);
		return;
	}
	using namespace std;
	for (int i = level; i < nums.size(); ++i) {
		swap(nums[i], nums[level]);			// 修改当前节点状态
		backtracking(nums, level + 1, ans); // 递归子节点
		swap(nums[i], nums[level]);			// 回改当前节点状态
	}
}

std::vector<std::vector<int> >
permute(std::vector<int> &nums)
{
	std::vector<std::vector<int> > ans;
	backtracking(nums, 0, ans);
	return ans;
}

} // namespace backtracking
} // namespace search
} // namespace algorithm