//MST를 이용한 tsp 근사방법 시도중
#include <iostream>

using namespace std;

const int MAX_N = 19;
const int INFINITI = 9999;

int g[MAX_N][MAX_N] = { 0 };
int mst[2][MAX_N] = { 0 };
int tspArr[MAX_N - 1][MAX_N] = { 0 };
bool inHeap[MAX_N] = { true };
int heap[MAX_N+1] = { 0 };
int heapCount = 0;

void heapify() {
	for (int i = heapCount >> 1; i > 0; i--) {
		int parent = i;
		int child = parent << 1;
		if (child + 1 <= heapCount) child = mst[1][heap[child]] < mst[1][heap[child + 1]] ? child : child + 1;

		if (mst[1][heap[parent]] > mst[1][heap[child]]) {
			int temp = heap[parent];
			heap[parent] = heap[child];
			heap[child] = temp;
		}
	}
}

int pop() {
	int parent = 1;
	int ret = heap[parent];
	heap[parent] = heap[heapCount--];

	int child = parent << 1;
	if (child + 1 <= heapCount) child = mst[1][heap[child]] < mst[1][heap[child + 1]] ? child : child + 1;

	while (child <= heapCount && mst[1][heap[parent]] > mst[1][heap[child]]) {
		int temp = heap[parent];
		heap[parent] = heap[child];
		heap[child] = temp;

		parent = child;
		child = parent << 1;
		if (child + 1 <= heapCount) child = mst[1][heap[child]] < mst[1][heap[child + 1]] ? child : child + 1;
	}
	return ret;
}

void prim(int N) {
	for (int i = 0; i < N; i++) {
		mst[1][i] = INFINITI;
		mst[0][i] = i;
		heap[++heapCount] = i;
		inHeap[i] = true;
	}
	mst[1][0] = 0;

	while (heapCount > 0) {
		int u = pop();
		inHeap[u] = false;

		for (int i = 0; i < N; i++) {
			if (g[u][i]) {
				if (inHeap[i] && g[u][i] < mst[1][i]) {
					mst[1][i] = g[u][i];
					mst[0][i] = u;
				}
			}
		}
		heapify();
	}
}

int tsp(int N, int cur) {
	for (int i = 0; i < N; i++) {

	}
	
}

int main() {
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &g[i][j]);
		}
	}

	prim(N);

	return 0;
}
