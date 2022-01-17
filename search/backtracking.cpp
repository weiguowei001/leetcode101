#include "backtracking.hpp"
#include <utility>

namespace algorithm {
namespace search {
namespace backtracking {

void
backtracking_1(
	std::vector<int> nums, int level, std::vector<std::vector<int> > &ans)
{
	if (level == nums.size() - 1) {
		ans.push_back(nums);
		return;
	}
	using namespace std;
	for (int i = level; i < nums.size(); ++i) {
		swap(nums[i], nums[level]);			  // 修改当前节点状态
		backtracking_1(nums, level + 1, ans); // 递归子节点
		swap(nums[i], nums[level]);			  // 回改当前节点状态
	}
}

std::vector<std::vector<int> >
permute(std::vector<int> &nums)
{
	std::vector<std::vector<int> > ans;
	backtracking_1(nums, 0, ans);
	return ans;
}

void
backtracking_2(vector<vector<int> > &ans, vector<int> &comb, int &count,
	int pos, int n, int k)
{
	if (count == k) {
		ans.push_back(comb);
		return;
	}
	for (int i = 0; i < n; ++i) {
		comb[count++] = i; // 修改当前节点状态
		backtracking_2(ans, comb, count, i + 1, n, k); // 递归子节点
		--count; // 回改当前节点状态
	}
}

std::vector<std::vector<int> >
combine(int n, int k)
{
	vector<vector<int> > ans;
	vector<int> comb(k, 0);
	int count = 0;
	backtracking_2(ans, comb, count, 1, n, k);
	return ans;
}

void
backtracking_3(int i, int j, vector<vector<char> > &board, string &word,
	bool &find, vector<vector<bool> > &visited, int pos)
{
	if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) {
		return;
	}
	if (visited[i][j] || find || board[i][j] != word[pos]) {
		return;
	}
	if (pos == word.size() - 1) {
		find = true;
		return;
	}
	visited[i][j] = true; // 修改当前节点状态
	// 递归子节点
	backtracking_3(i + 1, j, board, word, find, visited, pos + 1);
	backtracking_3(i - 1, j, board, word, find, visited, pos + 1);
	backtracking_3(i, j + 1, board, word, find, visited, pos + 1);
	backtracking_3(i, j - 1, board, word, find, visited, pos + 1);
	visited[i][j] = false;
}

bool
exist(std::vector<std::vector<char> > &board, std::string word)
{
	if (board.empty())
		return false;
	int m = board.size(), n = board[0].size();
	vector<vector<bool> > visited(m, vector<bool>(n, false));
	bool find = false;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			backtracking_3(i, j, board, word, find, visited, 0);
		}
	}
	return find;
}

void
backtracing_4(vector<vector<string> > &ans, vector<string> &board,
	vector<bool> &column, vector<bool> &ldiag, vector<bool> rdiag, int row,
	int n)
{
	if (row == n) {
		ans.push_back(board);
		return;
	}
	for (int i = 0; i < n; ++i) {
		if (column[i] || ldiag[n - row + i - 1] || rdiag[row + i]) {
			continue;
		}
		// 修改当前节点状态
		board[row][i] = 'Q';
		column[i] = ldiag[n - row + i - 1] = rdiag[row + i] = true;
		// 递归子节点
		backtracing_4(ans, board, column, ldiag, rdiag, row + 1, n);
		// 回改当前节点状态
		board[row][i] = '.';
		column[i] = ldiag[n - row + i - 1] = rdiag[row + i] = false;
	}
}

std::vector<std::vector<std::string> >
solveNQueens(int n)
{
	vector<vector<string> > ans;
	if (n == 0) {
		return ans;
	}
	vector<string> board(n, string(n, '.'));
	vector<bool> column(n, false), ldiag(2 * n - 1, false),
		rdiag(2 * n - 1, false);
	backtracing_4(ans, board, column, ldiag, rdiag, 0, n);
	return ans;
}

} // namespace backtracking
} // namespace search
} // namespace algorithm