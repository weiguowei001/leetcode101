#pragma once

#include <vector>

using namespace std;

namespace algorithm {
namespace search {
namespace dfs {
namespace stack {

int maxAreaOfIsLand(vector<vector<int> > &grid);

} // namespace stack

namespace recursive {

int maxAreaOfIsLand_1(vector<vector<int> > &grid);
int maxAreaOfIsLand_2(vector<vector<int> > &grid);
int findCircleNum(vector<vector<int> > &friends);
vector<vector<int> > pacificAtlantic(
	vector<vector<int> > &matrix);

} // namespace recursive
} // namespace dfs
} // namespace search
} // namespace algorithm
