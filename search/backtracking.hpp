#pragma once

#include <vector>
#include <string>

namespace algorithm {
namespace search {
namespace backtracking {

std::vector<std::vector<int> > permute(std::vector<int> &nums);
std::vector<std::vector<int> > combine(int n, int k);
bool exist(std::vector<std::vector<char> > &board, std::string word);
std::vector<std::vector<std::string> > solveNQueens(int n);
} // namespace backtracking
} // namespace search
} // namespace algorithm