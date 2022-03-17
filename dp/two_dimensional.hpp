#pragma once

#include <vector>
#include <string>

using namespace std;

namespace algorithm {
namespace dp {

int longestCommonSubsequence(string text1, string text2);
// 0-1背包问题
int knapsack_1(vector<int> weights, vector<int> values, int N, int W);
int knapsack_2(vector<int> weights, vector<int> values, int N, int W);
// 完全背包问题
int knapsack_3(vector<int> weights, vector<int> values, int N, int W);
int knapsack_4(vector<int> weights, vector<int> values, int N, int W);

bool canPartition_1(vector<int> &nums);
bool canPartition_2(vector<int> &nums);

} // namespace dp
} // namespace algorithm
