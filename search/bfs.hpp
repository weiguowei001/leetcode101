#pragma once

#include <vector>
#include <string>

using namespace std;

namespace algorithm {
namespace search {
namespace bfs {
namespace queue {

int maxAreaOfIsLand(vector<vector<int> > &grid);
int shortestBridge(vector<vector<int> > &grid);
vector<vector<string> > findLadders(
	string beginWord, string endWord, vector<string> &wordList);

} // namespace queue
} // namespace bfs
} // namespace search
} // namespace algorithm