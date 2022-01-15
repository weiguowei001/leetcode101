#include "bfs.hpp"

#include <queue>

namespace algorithm {
namespace search {
namespace bfs {
namespace queue {

std::vector<int> direction{-1, 0, 1, 0, -1};

int
maxAreaOfIsLand(std::vector<std::vector<int> > &grid)
{
	size_t m = grid.size(), n = m ? grid[0].size() : 0;
	int area = 0;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; j++) {
			if (!grid[i][j]) {
				continue;
			}
			std::queue<std::pair<int, int> > island;
			island.push({i, j});
			int local_area = 0;
			while (!island.empty()) {
				auto [r, c] = island.front();
				island.pop();
				if (!grid[r][c]) {
					continue;
				}
				++local_area;
				grid[r][c] = 0;
				for (int k = 0; k < 4; ++k) {
					int x = r + direction[k], y = c + direction[k + 1];
					if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y]) {
						island.push({x, y});
					}
				}
			}
			area = std::max(area, local_area);
		}
	}
	return area;
}

} // namespace queue
} // namespace bfs
} // namespace search
} // namespace algorithm