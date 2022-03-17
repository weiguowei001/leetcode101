#pragma once

#include <vector>
#include <string>

using namespace std;

namespace algorithm {
namespace dp {

int longestCommonSubsequence(string text1, string text2);
int knapsack_1(vector<int> weights, vector<int> values, int N, int W);
int knapsack_2(vector<int> weights, vector<int> values, int N, int W);

} // namespace dp
} // namespace algorithm
