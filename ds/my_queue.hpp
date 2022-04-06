#pragma once

#include <stack>

using namespace std;

namespace algorithm {
namespace ds {

// 尝试使用栈（stack）来实现队列（queue）。
class MyQueue {
	stack<int> in, out;

public:
	MyQueue() {}

	void
	push(int x)
	{
		in.push(x);
	}

	int
	pop()
	{
		in2out();
		int x = out.top();
		out.pop();
		return x;
	}

	int
	peek()
	{
		in2out();
		return out.top();
	}

	void
	in2out()
	{
		if (out.empty()) {
			while (!in.empty()) {
				int x = in.top();
				in.pop();
				out.push(x);
			}
		}
	}

	bool
	empty()
	{
		return in.empty() && out.empty();
	}
};

} // namespace ds
} // namespace algorithm