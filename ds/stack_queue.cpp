#include "stack_queue.hpp"

#include <stack>

namespace algorithm {
namespace ds {

bool
isValid(string s)
{
	stack<char> parsed;
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] == '{' || s[i] == '[' || s[i] == '(') {
			parsed.push(s[i]);
		} else {
			if (parsed.empty()) {
				return false;
			}
			char c = parsed.top();
			if ((s[i] == '}' && c == '{') || (s[i] == ']' && c == '[') ||
				(s[i] == ')' && c == '(')) {
				parsed.pop();
			} else {
				return false;
			}
		}
	}
	return parsed.empty();
}
} // namespace ds
} // namespace algorithm