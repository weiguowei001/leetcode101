﻿#pragma once

#include <stack>

using namespace std;

namespace algorithm {
namespace ds {
// 设计一个最小栈，除了需要支持常规栈的操作外，还需要支持在 O(1) 时间内查询栈内最小
// 值的功能。
class MinStack {
	stack<int> s, min_s;

public:
	MinStack() {}

	void
	push(int x)
	{
		s.push(x);
		if (min_s.empty() || min_s.top() >= x) {
			min_s.push(x);
		}
	}

	void
	pop()
	{
		if (!min_s.empty() && min_s.top() == s.top()) {
			min_s.pop();
		}
		s.pop();
	}

	int
	top()
	{
		return s.top();
	}

	int
	getMin()
	{
		return min_s.top();
	}
};

} // namespace ds
} // namespace algorithm