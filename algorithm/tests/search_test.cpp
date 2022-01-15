#include <iostream>

#include "../search/dfs.hpp"

using namespace algorithm::search;

int
main()
{
	std::vector<std::vector<int> > friends_dfs_recursive{
		{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
	std::cout << "dfs::recursive::findCircleNum: "
			  << dfs::recursive::findCircleNum(friends_dfs_recursive) << "\n";

	return 0;
}