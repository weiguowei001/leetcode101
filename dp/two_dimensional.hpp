#pragma once

#include <vector>
#include <string>

using namespace std;

namespace algorithm {
namespace dp {

int longestCommonSubsequence(string text1, string text2);
// 背包问题

// 0-1 背包问题
int knapsack_1(vector<int> weights, vector<int> values, int N, int W);
int knapsack_2(vector<int> weights, vector<int> values, int N, int W);
// 完全背包问题
int knapsack_3(vector<int> weights, vector<int> values, int N, int W);
int knapsack_4(vector<int> weights, vector<int> values, int N, int W);
// 
bool canPartition_1(vector<int> &nums);
bool canPartition_2(vector<int> &nums);
// 多维费用的 0-1 背包问题
int findMaxForm(vector<string> &strs, int m, int n);
int coinChange(vector<int> &coins, int amount);

// 字符串编辑
int minDistance(string word1, string word2);
int minSteps(int n);
bool isMatch(string s, string p);

// 股票交易
int maxProfit_1(vector<int> &prices);
int maxProfit_2(int k, vector<int> &prices);
int maxProfit(vector<int> &prices);

} // namespace dp
} // namespace algorithm
