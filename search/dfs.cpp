#include "dfs.hpp"

#include <stack>
#include <queue>
#include <utility>

vector<int> direction{-1, 0, 1, 0, -1};

namespace algorithm {
namespace search {
namespace dfs {
namespace stack {

int
maxAreaOfIsLand(vector<vector<int> > &grid)
{
	size_t n = grid.size(), m = n ? grid[0].size() : 0;
	int area = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (!grid[i][j]) {
				continue;
			}
			std::stack<pair<int, int> > island;
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
			area = max(area, local_area);
		}
	}
	return area;
}

} // namespace stack

namespace recursive {

// 辅助函数
int
dfs_1(vector<vector<int> > &grid, int r, int c)
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
maxAreaOfIsLand_1(vector<vector<int> > &grid)
{
	if (grid.empty() || grid[0].empty())
		return 0;
	int max_area = 0;
	for (int i = 0; i < grid.size(); ++i) {
		for (int j = 0; j < grid[0].size(); ++j) {
			if (grid[i][j] == 1) {
				max_area = max(max_area, dfs_1(grid, i, j));
			}
		}
	}

	return max_area;
}

// 辅助函数
int
dfs_2(vector<vector<int> > &grid, int r, int c)
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
maxAreaOfIsLand_2(vector<vector<int> > &grid)
{
	if (grid.empty() || grid[0].empty())
		return 0;
	int max_area = 0;
	for (int i = 0; i < grid.size(); ++i) {
		for (int j = 0; j < grid[0].size(); ++j) {
			max_area = max(max_area, dfs_2(grid, i, j));
		}
	}
	return max_area;
}

void
dfs_3(vector<vector<int> > &friends, int i, vector<bool> &visited)
{
	visited[i] = true;
	for (int k = 0; k < friends.size(); ++k) {
		if (friends[i][k] == 1 && !visited[k]) {
			dfs_3(friends, k, visited);
		}
	}
}

int
findCircleNum(vector<vector<int> > &friends)
{
	size_t n = friends.size(), count = 0;
	vector<bool> visited(n, false);
	for (int i = 0; i < n; ++i) {
		if (!visited[i]) {
			dfs_3(friends, i, visited);
			++count;
		}
	}
	return static_cast<int>(count);
}


void
dfs_4(const vector<vector<int> > &matrix, vector<vector<bool> > &can_reach,
	int r, int c)
{
	if (can_reach[r][c]) {
		return;
	}
	can_reach[r][c] = true;
	int x, y;
	for (int i = 0; i < 4; ++i) {
		x = r + direction[i], y = c + direction[i + 1];
		if (x >= 0 && x < matrix.size() && y >= 0 && y < matrix[0].size() &&
			matrix[r][c] <= matrix[x][y]) {
			dfs_4(matrix, can_reach, x, y);
		}
	}
}

vector<vector<int> >
pacificAtlantic(vector<vector<int> > &matrix)
{
	if (matrix.empty() || matrix[0].empty()) {
		return {};
	}

	vector<vector<int> > ans;
	int m = matrix.size(), n = m ? matrix[0].size() : 0;
	vector<vector<bool> > can_reach_p(m, vector<bool>(n, false));
	vector<vector<bool> > can_reach_a(m, vector<bool>(n, false));
	for (int i = 0; i < m; ++i) {
		dfs_4(matrix, can_reach_p, i, 0);
		dfs_4(matrix, can_reach_a, i, n - 1);
	}
	for (int i = 0; i < n; ++i) {
		dfs_4(matrix, can_reach_p, 0, i);
		dfs_4(matrix, can_reach_a, m - 1, i);
	}
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (can_reach_p[i][j] && can_reach_a[i][j]) {
				ans.push_back(vector<int>{i, j});
			}
		}
	}
	return ans;
}

} // namespace recursive
} // namespace dfs
} // namespace search
} // namespace algorithm
