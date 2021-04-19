//table 만들어서 풀음
//그리디도 해볼것

#include <iostream>

using namespace std;
const int MAX_N = 100001;
int w[MAX_N][2] = { 0 };
int r[MAX_N][2] = { 0 };
int heap[MAX_N] = { 0 };
int heapCount = 0;

void push(int v) {
	heap[++heapCount] = v;
	int child = heapCount;
	int parent = child >> 1;
	while (parent > 0 && w[heap[parent]][0] > w[heap[child]][0]) {
		int tmp = heap[parent];
		heap[parent] = heap[child];
		heap[child] = tmp;

		child = parent;
		parent = child >> 1;
	}
}

int pop() {
	int parent = 1;
	int ret = heap[parent];
	heap[parent] = heap[heapCount--];

	int child = parent << 1;
	if (child + 1 <= heapCount) child = w[heap[child]][0] < w[heap[child + 1]][0] ? child : child + 1;

	while (child <= heapCount && w[heap[parent]][0] > w[heap[child]][0]) {
		int tmp = heap[parent];
		heap[parent] = heap[child];
		heap[child] = tmp;

		parent = child;
		child = parent << 1;
		if (child + 1 <= heapCount) child = w[heap[child]][0] < w[heap[child + 1]][0] ? child : child + 1;
	}
	return ret;
}

int main() {
	int n, q;
	scanf("%d %d", &n, &q);

	for (int i = 1; i <= n; i++) {
		int h;
		scanf("%d %d %d", &w[i][0], &w[i][1], &h);
		push(i);
	}

	int u = pop();
	r[0][0] = w[u][0];
	r[0][1] = w[u][1];

	int rNum = 0;
	while (heapCount > 0) {
		int u = pop();

		if (r[rNum][1] >= w[u][0]) {
			if(r[rNum][1] < w[u][1]) r[rNum][1] = w[u][1];
		}
		else {
			rNum++;
			r[rNum][0] = w[u][0];
			r[rNum][1] = w[u][1];
		}
	}

	for (int i = 0; i < q; i++) {
		bool ans = false;
		int from, to;
		scanf("%d %d", &from, &to);

		int m, n;

		if (w[from][0] > w[to][0]) {
			m = w[to][0];
			n = w[from][0];
		}
		else {
			m = w[from][0];
			n = w[to][0];
		}

		for (int j = rNum; j >= 0; j--) {
			if (m >= r[j][0]) {
				if (n <= r[j][1]) {
					ans = true;
				}
				break;
			}
		}
		if (ans) printf("1\n");
		else printf("0\n");
	}

	return 0;
}
