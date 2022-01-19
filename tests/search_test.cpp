#include <iostream>

#include "../search/dfs.hpp"
#include "../search/backtracking.hpp"

using namespace std;
using namespace algorithm::search;

int
main()
{
	vector<vector<int> > friends_dfs_recursive{
		{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
	cout << "dfs::recursive::findCircleNum: "
			  << dfs::recursive::findCircleNum(friends_dfs_recursive) << "\n";

	vector<vector<int> > combine = backtracking::combine(4, 2);
	cout << "backtracking::combine:\n";
	for (auto &&v : combine)
	{
		cout << v[0] << v[1] << "\n";
	}
	
	return 0;
}