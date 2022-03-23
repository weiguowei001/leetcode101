
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

pair<int, int>
count(const string &s)
{
	int count0 = s.length(), count1 = 0;
	for (const char &c : s) {
		if (c == '1') {
			++count1;
			--count0;
		}
	}
	return make_pair(count0, count1);
}

int
findMaxForm(vector<string> &strs, int m, int n)
{
	vector<vector<int> > dp(m + 1, vector<int>(n + 1, 0));
	for (const string &str : strs) {
		auto [count0, count1] = count(str);
		for (int i = m; i >= count0; --i) {
			for (int j = n; j >= count1; --j) {
				dp[i][j] = max(dp[i][j], 1 + dp[i - count0][j - count1]);
			}
		}
	}
	return dp[m][n];
}

int
coinChange(vector<int> &coins, int amount)
{
	if (coins.empty())
		return -1;
	vector<int> dp(amount + 1, amount + 1);
	dp[0] = 0;
	for (int i = 1; i <= amount; ++i) {
		for (const int &coin : coins) {
			if (i >= coin) {
				dp[i] = min(dp[i], dp[i - coin] + 1);
			}
		}
	}
	return dp[amount] == amount + 1 ? -1 : dp[amount];
}

int
minDistance(string word1, string word2)
{
	int m = word1.length(), n = word2.length();
	vector<vector<int> > dp(m + 1, vector<int>(n + 1, 0));
	for (int i = 0; i <= m; ++i) {
		for (int j = 0; j <= n; ++j) {
			if (i == 0) {
				dp[i][j] = j;
			} else if (j == 0) {
				dp[i][j] = i;
			} else {
				dp[i][j] = min(
					dp[i - 1][j - 1] + ((word1[i - 1] == word2[j - 1]) ? 0 : 1),
					min(dp[i - 1][j] + 1, dp[i][j - 1] + 1));
			}
		}
	}
	return dp[m][n];
}

int
minSteps(int n)
{
	vector<int> dp(n + 1);
	for (int i = 2; i <= n; ++i) {
		dp[i] = i;
		for (int j = 2; j * j <= i; ++j) {
			if (i % j == 0) {
				dp[i] = dp[j] + dp[i / j];
				break;
			}
		}
	}
	return dp[n];
}

bool
isMatch(string s, string p)
{
	int m = s.size(), n = p.size();
	vector<vector<bool> > dp(m + 1, vector<bool>(n + 1, false));
	dp[0][0] = true;
	for (int i = 1; i < n + 1; ++i) {
		if (p[i - 1] == '*') {
			dp[0][i] = dp[0][i - 2];
		}
	}
	for (int i = 1; i < m + 1; ++i) {
		for (int j = 1; j < n + 1; ++j) {
			if (p[j - 1] == '.') {
				dp[i][j] = dp[i - 1][j - 1];
			} else if (p[j - 1] != '*') {
				dp[i][j] = dp[i - 1][j - 1] && p[j - 1] == s[i - 1];
			} else if (p[j - 2] != s[i - 1] && p[j - 2] != '.') {
				dp[i][j] = dp[i][j - 2];
			} else {
				dp[i][j] = dp[i][j - 1] || dp[i - 1][j] || dp[i][j - 2];
			}
		}
	}
	return dp[m][n];
}

int
maxProfit_1(vector<int> &prices)
{
	int sell = 0, buy = INT_MIN;
	for (int i = 0; i < prices.size(); ++i) {
		buy = max(buy, -prices[i]);
		sell = max(sell, buy + prices[i]);
	}
	return sell;
}

int
maxProfitUnlimited(vector<int> prices)
{
	int maxProfit = 0;
	for (int i = 1; i < prices.size(); ++i) {
		if (prices[i] > prices[i - 1]) {
			maxProfit += prices[i] - prices[i - 1];
		}
	}
	return maxProfit;
}

int
maxProfit_2(int k, vector<int> &prices)
{
	int days = prices.size();
	if (days < 2) {
		return 0;
	}
	if (k * 2 >= days) {
		return maxProfitUnlimited(prices);
	}
	vector<int> buy(k + 1, INT_MIN), sell(k + 1, 0);
	for (int i = 0; i < days; ++i) {
		for (int j = 1; j <= k; ++j) {
			buy[j] = max(buy[j], sell[j - 1] - prices[i]);
			sell[j] = max(sell[j], buy[j] + prices[i]);
		}
	}
	return sell[k];
}

int
maxProfit(vector<int> &prices)
{
	int n = prices.size();
	if (n == 0) {
		return 0;
	}
	vector<int> buy(n), sell(n), s1(n), s2(n);
	s1[0] = buy[0] = -prices[0];
	sell[0] = s2[0] = 0;
	for (int i = 1; i < n; i++) {
		buy[i] = s2[i - 1] - prices[i];
		s1[i] = max(buy[i - 1], s1[i - 1]);
		sell[i] = max(buy[i - 1], s1[i - 1]) + prices[i];
		s2[i] = max(s2[i - 1], sell[i - 1]);
	}
	return max(sell[n - 1], s2[n - 1]);
}

} // namespace dp
} // namespace algorithm
