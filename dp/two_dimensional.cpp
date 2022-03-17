
#include "two_dimensional.hpp"
#include <numeric>

namespace algorithm {
namespace dp {

int
longestCommonSubsequence(string text1, string text2)
{
	int m = text1.length(), n = text2.length();
	vector<vector<int> > dp(m + 1, vector<int>(n + 1, 0));
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (text1[i - 1] == text2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			} else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	return dp[m][n];
}

int
knapsack_1(vector<int> weights, vector<int> values, int N, int W)
{
	vector<vector<int> > dp(N + 1, vector<int>(W + 1, 0));
	for (int i = 1; i <= N; ++i) {
		int w = weights[i - 1], v = values[i - 1];
		for (int j = 1; j <= W; ++j) {
			if (j >= w) {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w] + v);
			} else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	return dp[N][W];
}

int
knapsack_2(vector<int> weights, vector<int> values, int N, int W)
{
	vector<int> dp(W + 1, 0);
	for (int i = 1; i <= N; ++i) {
		int w = weights[i - 1], v = values[i - 1];
		for (int j = W; j >= w; --j) {
			dp[j] = max(dp[j], dp[j - w] + v);
		}
	}
	return dp[W];
}

int
knapsack_3(vector<int> weights, vector<int> values, int N, int W)
{
	vector<vector<int> > dp(N + 1, vector<int>(W + 1, 0));
	for (int i = 1; i <= N; ++i) {
		int w = weights[i - 1], v = values[i - 1];
		for (int j = 1; j <= W; ++j) {
			if (j >= w) {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - w] + v);
			} else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	return dp[N][W];
}

int
knapsack_4(vector<int> weights, vector<int> values, int N, int W)
{
	vector<int> dp(W + 1, 0);
	for (int i = 1; i <= N; ++i) {
		int w = weights[i - 1], v = values[i - 1];
		for (int j = w; j <= W; ++j) {
			dp[j] = max(dp[j], dp[j - w] + v);
		}
	}
	return dp[W];
}

bool
canPartition_1(vector<int> &nums)
{
	int sum = accumulate(nums.begin(), nums.end(), 0);
	if (sum % 2)
		return false;
	int target = sum / 2, n = nums.size();
	vector<vector<bool> > dp(n + 1, vector<bool>(target + 1, false));
	dp[0][0] = true;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= target; ++j) {
			if (j < nums[i - 1]) {
				dp[i][j] = dp[i - 1][j];
			} else {
				dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
			}
		}
	}
	return dp[n][target];
}

bool
canPartition_2(vector<int> &nums)
{
	int sum = accumulate(nums.begin(), nums.end(), 0);
	if (sum % 2)
		return false;
	int target = sum / 2, n = nums.size();
	vector<bool> dp(target + 1, false);
	dp[0] = true;
	for (int i = 1; i <= n; ++i) {
		for (int j = target; j >= nums[i - 1]; --j) {
			dp[j] = dp[j] || dp[j - nums[i - 1]];
		}
	}
	return dp[target];
}

} // namespace dp
} // namespace algorithm
