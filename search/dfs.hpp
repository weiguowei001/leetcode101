#pragma once

#include <vector>

namespace algorithm {
namespace search {
namespace dfs {
namespace stack {

int maxAreaOfIsLand(std::vector<std::vector<int> > &grid);

} // namespace stack

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
} // namespace search
} // namespace algorithm
