//disjoint set 
#include <iostream>

using namespace std;

int find_set(int x,int* p) {
	if (p[x] != x) {
		p[x] = find_set(p[x],p);
	}
	return p[x];
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	int* p = new int[n+1] {0};
	int* rank = new int[n+1] {0};
	bool* check = new bool[n + 1]{ false };
	/*int p[11] = { 0 };
	int rank[11] = { 0 };
	bool check[11] = { false };*/

	for (int i = 1; i <= n; i++) {
		p[i] = i;
		rank[i] = 0;
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);

		int x = find_set(a,p);
		int y = find_set(b,p);

		if (rank[x] > rank[y]) {
			p[y] = x;
		}
		else {
			p[x] = y;
			if (rank[x] == rank[y]) rank[y]++;
		}
	}

	for (int i = 1; i <= n; i++) {
		check[find_set(i,p)] = true;
	}
	int ret = 0;
	for (int i = 1; i <= n; i++) {
		if (check[i]) ret++;
	}
	printf("%d\n", ret);

	return 0;
}
