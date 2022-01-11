#include "search.hpp"

#include <stack>
#include <utility>

std::vector<int> direction{-1, 0, 1, 0, -1};

namespace algorithm {
namespace search {

int
findCircleNum(std::vector<std::vector<int> > &friends)
{
	return -1;
}

std::vector<std::vector<int> >
permute(std::vector<int> &nums)
{
	return std::vector<std::vector<int> >{{}};
}

namespace stack {

int
maxAreaOfIsLand(std::vector<std::vector<int> > &grid)
{
	size_t m = grid.size(), n = m ? grid[0].size() : 0;
	int local_area, area = 0, x, y;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (grid[i][j]) {
				local_area = 1;
				grid[i][j] = 0;
				std::stack<std::pair<int, int> > island;
				island.push({i, j});
				while (!island.empty()) {
					auto [r, c] = island.top();
					island.pop();
					for (int k = 0; k < 4; ++k) {
						x = r + direction[k], y = c + direction[k + 1];
						if (x >= 0 && x < m && y >= 0 && y < n &&
							grid[x][y] == 1) {
							grid[x][y] = 0;
							++local_area;
							island.push({x, y});
						}
					}
				}
				area = std::max(area, local_area);
			}
		}
	}
	return static_cast<int>(area);
}
} // namespace stack

namespace recursive {

// 辅助函数
int
dfs_1(std::vector<std::vector<int> > &grid, int r, int c)
{
	if (grid[r][c] == 0)
		return 0;
	grid[r][c] = 0;
	int x, y, area = 1;
	for (int i = 0; i < 4; ++i) {
		x = r + direction[i], y = c + direction[i + 1];
		if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size()) {
			area += dfs_1(grid, x, y);
		}
	}
	return area;
}

// 主函数
int
maxAreaOfIsLand_1(std::vector<std::vector<int> > &grid)
{
	if (grid.empty() || grid[0].empty())
		return 0;
	int max_area = 0;
	for (int i = 0; i < grid.size(); ++i) {
		for (int j = 0; j < grid[0].size(); ++j) {
			if (grid[i][j] == 1) {
				max_area = std::max(max_area, dfs_1(grid, i, j));
			}
		}
	}

	return max_area;
}

// 辅助函数
int
dfs_2(std::vector<std::vector<int> > &grid, int r, int c)
{
	if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() ||
		grid[r][c] == 0) {
		return 0;
	}
	grid[r][c] = 0;
	return 1 + dfs_2(grid, r + 1, c) + dfs_2(grid, r - 1, c) +
		   dfs_2(grid, r, c + 1) + dfs_2(grid, r, c - 1);
}

// 主函数
int
maxAreaOfIsLand_2(std::vector<std::vector<int> > &grid)
{
	if (grid.empty() || grid[0].empty())
		return 0;
	int max_area = 0;
	for (int i = 0; i < grid.size(); ++i) {
		for (int j = 0; j < grid[0].size(); ++j) {
			max_area = std::max(max_area, dfs_2(grid, i, j));
		}
	}
	return max_area;
}

} // namespace recursive

} // namespace search
} // namespace algorithm
