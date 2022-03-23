#include <iostream>

#include "../search/dfs.hpp"
#include "../search/bfs.hpp"
#include "../search/backtracking.hpp"

using namespace std;
using namespace algorithm::search;

int
main()
{
	vector<vector<int> > friends_dfs_recursive{{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
	cout << "dfs::recursive::findCircleNum: "
		 << dfs::recursive::findCircleNum(friends_dfs_recursive) << "\n";

	vector<vector<int> > combine = backtracking::combine(4, 2);
	cout << "backtracking::combine:\n";
	for (auto &&v : combine) {
		cout << v[0] << v[1] << "\n";
	}
	auto r = backtracking::solveNQueens(4);

	vector<vector<int> > grid{{1, 1, 1, 1, 1}, {1, 0, 0, 0, 1}, {1, 0, 1, 0, 1},
		{1, 0, 0, 0, 1}, {1, 1, 1, 1, 1}};
	bfs::queue::shortestBridge(grid);
	vector<string> wordList{"hot", "dot", "dog", "lot", "log", "cog"};
	bfs::queue::findLadders("hit", "dog", wordList);
	return 0;
}