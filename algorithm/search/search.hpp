#pragma once

#include <vector>

namespace algorithm {
namespace search {

int findCircleNum(std::vector<std::vector<int> > &friends);
std::vector<std::vector<int> > permute(std::vector<int> &nums);

namespace stack {

int maxAreaOfIsLand(std::vector<std::vector<int> > &grid);

}

namespace recursive {

int dfs(std::vector<std::vector<int> > &grid, int r, int c);
int maxAreaOfIsLand(std::vector<std::vector<int> > &grid);

} // namespace recursive

} // namespace search
} // namespace algorithm
