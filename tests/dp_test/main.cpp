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
	return 0;
}