#include "search.hpp"

#include <stack>
#include <utility>

namespace algorithm {
namespace search {

std::vector<int> direction{-1, 0, 1, 0, -1};

int
maxAreaOfIsLand(std::vector<std::vector<int> > &grid)
{
	size_t m = grid.size(), n = m ? grid[0].size() : 0, local_area, area = 0, x, y;
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
	return area;
}

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

} // namespace search
} // namespace algorithm