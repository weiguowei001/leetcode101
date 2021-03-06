#include <iostream>

#include "../../dp/dp.hpp"
#include "../../dp/one_dimensional.hpp"
#include "../../dp/two_dimensional.hpp"
#include <vector>

using namespace std;
using namespace algorithm::dp;

int
main()
{
	std::vector<int> nums{1, 5, 11, 5};
	canPartition_1(nums);

	vector<string> strs{"10", "0001", "111001", "1", "0"};
	findMaxForm(strs, 5, 3);
	isMatch("aab", "c*d*.*");
	vector<int> prices{7, 1, 5, 3, 6, 4};
	maxProfit_1(prices);
	return 0;
}