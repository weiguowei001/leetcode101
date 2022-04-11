#pragma once

#include <vector>

using namespace std;

namespace algorithm {
namespace ds {

vector<int> heap;
// 获得最大值
int
top()
{
	return heap[0];
}

// 插入任意值：把新的数字放在最后一位，然后上浮
void
push(int k)
{
	heap.push_back(k);
	swim(heap.size() - 1);
}

// 删除最大值：把最后一个数字挪到开头，然后下沉
void
pop()
{
	heap[0] = heap.back();
	heap.pop_back();
	sink(0);
}

// 上浮
void
swim(int pos)
{
	while (pos > 1 && heap[pos / 2] < heap[pos]) {
		swap(heap[pos / 2], heap[pos]);
		pos /= 2;
	}
}

// 下沉
void
sink(int pos)
{
	while (2 * pos <= N) {
		int i = 2 * pos;
		if (i < N && heap[i] < heap[i + 1])
			++i;
		if (heap[pos] >= heap[i])
			break;
		swap(heap[pos], heap[i]);
		pos = i;
	}
}

} // namespace ds
} // namespace algorithm