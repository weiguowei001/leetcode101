#include "bfs.hpp"

#include <queue>
#include <unordered_set>
#include <unordered_map>

namespace algorithm {
namespace search {
namespace bfs {
namespace queue {

vector<int> direction{-1, 0, 1, 0, -1};

int
maxAreaOfIsLand(vector<vector<int> > &grid)
{
	size_t m = grid.size(), n = m ? grid[0].size() : 0;
	int area = 0;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; j++) {
			if (!grid[i][j]) {
				continue;
			}
			std::queue<pair<int, int> > island;
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
			area = max(area, local_area);
		}
	}
	return area;
}

void
dfs_1(std::queue<std::pair<int, int> > &points, vector<vector<int> > &grid,
	int m, int n, int i, int j)
{
	if (i < 0 || j < 0 || i == m || j == n || grid[i][j] == 2) {
		return;
	}
	if (grid[i][j] == 0) {
		points.push({i, j});
		return;
	}
	grid[i][j] = 2;
	dfs_1(points, grid, m, m, i - 1, j);
	dfs_1(points, grid, m, m, i + 1, j);
	dfs_1(points, grid, m, m, i, j - 1);
	dfs_1(points, grid, m, m, i, j + 1);
}

int
shortestBridge(vector<vector<int> > &grid)
{
	int m = grid.size(), n = grid[0].size();
	std::queue<pair<int, int> > points;
	// dfs寻找第一个岛屿，并把1全部赋值为2
	bool flipped = false;
	for (int i = 0; i < m; ++i) {
		if (flipped)
			break;
		for (int j = 0; j < n; ++j) {
			if (grid[i][j] == 1) {
				dfs_1(points, grid, m, n, i, j);
				flipped = true;
				break;
			}
		}
	}
	// bfs寻找第二个岛屿，并把过程中的0赋值为2
	int x, y;
	int level = 0;
	while (!points.empty()) {
		++level;
		int n_points = points.size();
		while (n_points--) {
			auto [r, c] = points.front();
			points.pop();
			for (int k = 0; k < 4; ++k) {
				x = r + direction[k], y = c + direction[k + 1];
				if (x >= 0 && y >= 0 && x < m && y < n) {
					if (grid[x][y] == 2) {
						continue;
					}
					if (grid[x][y] == 1) {
						return level;
					}
					points.push({x, y});
					grid[x][y] = 2;
				}
			}
		}
	}
	return 0;
}

void
backtracking_3(const string &src, const string &dst,
	unordered_map<string, vector<string> > &next, vector<string> &path,
	vector<vector<string> > &ans)
{
	if (src == dst) {
		ans.push_back(path);
		return;
	}
	for (const auto &s : next[src]) {
		path.push_back(s);
		backtracking_3(s, dst, next, path, ans);
		path.pop_back();
	}
}

vector<vector<string> >
findLadders(string beginWord, string endWord, vector<string> &wordList)
{
	vector<vector<string> > ans;
	unordered_set<string> dict;
	for (const auto &w : wordList) {
		dict.insert(w);
	}
	if (!dict.count(endWord)) {
		return ans;
	}
	dict.erase(beginWord);
	dict.erase(endWord);
	unordered_set<string> q1{beginWord}, q2{endWord};
	unordered_map<string, vector<string> > next;
	bool reversed = false, found = false;
	while (!q1.empty()) {
		unordered_set<string> q;
		for (const auto &w : q1) {
			string s = w;
			for (size_t i = 0; i < s.size(); i++) {
				char ch = s[i];
				for (int j = 0; j < 26; j++) {
					s[i] = j + 'a';
					if (q2.count(s)) {
						reversed ? next[s].push_back(w) : next[w].push_back(s);
						found = true;
					}
					if (dict.count(s)) {
						reversed ? next[s].push_back(w) : next[w].push_back(s);
						q.insert(s);
					}
				}
				s[i] = ch;
			}
		}
		if (found) {
			break;
		}
		for (const auto &w : q) {
			dict.erase(w);
		}
		if (q.size() <= q2.size()) {
			q1 = q;
		} else {
			reversed = !reversed;
			q1 = q2;
			q2 = q;
		}
	}
	if (found) {
		vector<string> path{beginWord};
	}
	return ans;
}

} // namespace queue
} // namespace bfs
} // namespace search
} // namespace algorithm