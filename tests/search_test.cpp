#include <iostream>

#include "../search/dfs.hpp"

using namespace std;
using namespace algorithm::search;

int
main()
{
	vector<vector<int> > friends_dfs_recursive{
		{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
	cout << "dfs::recursive::findCircleNum: "
			  << dfs::recursive::findCircleNum(friends_dfs_recursive) << "\n";

	return 0;
}