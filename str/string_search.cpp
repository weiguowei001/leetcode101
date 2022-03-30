#include "string_search.hpp"

namespace algorithm {
namespace str {

// 辅函数 - 计算next数组
void
calNext(const string &needle, vector<int> &next)
{
	for (int j = 1, p = -1; j < needle.length(); ++j) {
		while (p > -1 && needle[p + 1] != needle[j]) {
			p = next[p]; // 如果下一位不同，往前回溯
		}
		if (needle[p + 1] == needle[j]) {
			++p; // 如果下一位相同，更新相同的最大前缀和最大后缀长
		}
		next[j] = p;
	}
}

// 主函数
int
strStr(string haystack, string needle)
{
	int k = -1, n = haystack.length(), p = needle.length();
	if (p == 0)
		return 0;
	vector<int> next(p, -1); // -1表示不存在相同的最大前缀和后缀
	calNext(needle, next);	 // 计算next数组
	for (int i = 0; i < n; ++i) {
		while (k > -1 && needle[k + 1] != haystack[i]) {
			k = next[k]; // 有部分匹配，往前回溯
		}
		if (needle[k + 1] == haystack[i]) {
			++k;
		}
		if (k == p - 1) {
			return i - p + 1; // 说明k移动到needle的最末端，返回相应的位置
		}
	}
	return -1;
}


} // namespace str
} // namespace algorithm
