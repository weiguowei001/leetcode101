#pragma once

#include <vector>

namespace algorithm {
namespace search {

std::vector<std::vector<int> > permute(std::vector<int> &nums);


namespace dfs {
namespace stack {
int maxAreaOfIsLand(std::vector<std::vector<int> > &grid);
}

namespace recursive {
int dfs_1(std::vector<std::vector<int> > &grid, int r, int c);
int maxAreaOfIsLand_1(std::vector<std::vector<int> > &grid);

int dfs_2(std::vector<std::vector<int> > &grid, int r, int c);
int maxAreaOfIsLand_2(std::vector<std::vector<int> > &grid);

void dfs_3(
	std::vector<std::vector<int> > &friends, int i, std::vector<bool> &visited);
int findCircleNum(std::vector<std::vector<int> > &friends);
} // namespace recursive
} // namespace dfs

namespace bfs {
namespace queue {
int maxAreaOfIsLand(std::vector<std::vector<int> > &grid);
} // namespace queue
} // namespace bfs

} // namespace search
} // namespace algorithm
