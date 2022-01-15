#include "dfs.hpp"

#include <stack>
#include <queue>
#include <utility>

std::vector<int> direction{-1, 0, 1, 0, -1};

namespace algorithm {
namespace search {
namespace dfs {
namespace stack {

int
maxAreaOfIsLand(std::vector<std::vector<int> > &grid)
{
	size_t n = grid.size(), m = n ? grid[0].size() : 0;
	int area = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (!grid[i][j]) {
				continue;
			}
			std::stack<std::pair<int, int> > island;
			island.push({i, j});
			int local_area = 0;
			while (!island.empty()) {
				auto [r, c] = island.top();
				island.pop();
				if (!grid[r][c]) {
					continue;
				}
				++local_area;
				grid[r][c] = 0;
				for (int k = 0; k < 4; ++k) {
					int x = r + direction[k], y = c + direction[k + 1];
					if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y]) {
						island.push({x, y});
					}
				}
			}
			area = std::max(area, local_area);
		}
	}
	return area;
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

void
dfs_3(
	std::vector<std::vector<int> > &friends, int i, std::vector<bool> &visited)
{
	visited[i] = true;
	for (int k = 0; k < friends.size(); ++k) {
		if (friends[i][k] == 1 && !visited[k]) {
			dfs_3(friends, k, visited);
		}
	}
}

int
findCircleNum(std::vector<std::vector<int> > &friends)
{
	size_t n = friends.size(), count = 0;
	std::vector<bool> visited(n, false);
	for (int i = 0; i < n; ++i) {
		if (!visited[i]) {
			dfs_3(friends, i, visited);
			++count;
		}
	}
	return static_cast<int>(count);
}
} // namespace recursive
} // namespace dfs
} // namespace search
} // namespace algorithm
