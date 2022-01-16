#pragma once

#include <vector>

namespace algorithm {
namespace search {
namespace dfs {
namespace stack {

int maxAreaOfIsLand(std::vector<std::vector<int> > &grid);

} // namespace stack

namespace recursive {

int maxAreaOfIsLand_1(std::vector<std::vector<int> > &grid);

int maxAreaOfIsLand_2(std::vector<std::vector<int> > &grid);

int findCircleNum(std::vector<std::vector<int> > &friends);

std::vector<std::vector<int> > pacificAtlantic(
	std::vector<std::vector<int> > &matrix);

} // namespace recursive
} // namespace dfs
} // namespace search
} // namespace algorithm
