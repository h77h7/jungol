//플로이드말고 dijkstra를 N번 반복하는 방법 사용
#include <iostream>

using namespace std;

const int MAX_N = 500;
const int INFINITI = 99999;
int g[MAX_N][MAX_N] = { 0 };
int heap[MAX_N] = { 0 };
int heapCount = 0;

int pop(int u) {
	int parent = 1;
	int ret = heap[parent];
	heap[parent] = heap[heapCount--];

	int child = parent << 1;
	if (child + 1 <= heapCount) {
		child = g[u][heap[child]] < g[u][heap[child + 1]] ? child : child + 1;
	}
	while (child <= heapCount && g[u][heap[parent]] > g[u][heap[child]]) {
		int tmp = heap[parent];
		heap[parent] = heap[child];
		heap[child] = tmp;

		parent = child;
		int child = parent << 1;
		if (child + 1 <= heapCount) {
			child = g[u][heap[child]] < g[u][heap[child + 1]] ? child : child + 1;
		}
	}
	return ret;
}

void push(int value, int u) {
	heap[++heapCount] = value;
	int child = heapCount;
	int parent = child >> 1;

	while (parent > 0 && g[u][heap[parent]] > g[u][heap[child]]) {
		int tmp = heap[parent];
		heap[parent] = heap[child];
		heap[child] = tmp;

		child = parent;
		parent = child >> 1;
	}
}

void dijkstra(int start, int N) {
	
	g[start][start] = 0;

	push(start,start);

	for (int i = 1; i < N; i++) {
		if (g[start][i] == 1) push(i, start);
	}
	while (heapCount > 0) {
		int u = pop(start);
		
		for (int i = 1; i < N; i++) {
			if (g[u][i]!=INFINITI && g[start][i] > g[start][u] + g[u][i]) {
				g[start][i] = g[start][u] + g[u][i];
				push(i,start);
			}
		}
	}
}

int main() {
	int N, maxPage;
	scanf("%d", &N);
	maxPage = 0;

	for (int i = 0; i < MAX_N; i++) {
		for (int j = 0; j < MAX_N; j++) {
			g[i][j] = INFINITI;
		}
	}

	for (int i = 0; i < N; i++) {
		int from, to;
		scanf("%d %d", &from, &to);

		g[from][to] = 1;

		if (from > maxPage) maxPage = from;
		if (to > maxPage) maxPage = to;
	}

	int ret = 0;
	for (int i = 1; i <= maxPage; i++) {
		dijkstra(i, maxPage + 1);
		g[i][0] = 0;
		for (int j = 1; j <= maxPage; j++) {
			ret += g[i][j];
		}
	}

	printf("%.3f\n", (float)ret / (maxPage*(maxPage - 1)));

	return 0;
}
