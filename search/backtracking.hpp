#pragma once

#include <vector>
#include <string>

using namespace std;

namespace algorithm {
namespace search {
namespace backtracking {

vector<vector<int> > permute(vector<int> &nums);
vector<vector<int> > combine(int n, int k);
bool exist(vector<vector<char> > &board, string word);
vector<vector<string> > solveNQueens(int n);

} // namespace backtracking
} // namespace search
} // namespace algorithm