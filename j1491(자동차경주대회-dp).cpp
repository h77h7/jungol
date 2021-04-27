//dp(분할정복)
#include <iostream>

using namespace std;

const int MAX_N = 100;
const int INFINITI = 987654321;
int t[MAX_N + 2] = { 0 };
int d[MAX_N + 2] = { 0 };
int p[MAX_N + 2] = { 0 };
int dp[MAX_N + 2] = { 0 };

int main() {
	int limit, n;
	scanf("%d %d", &limit, &n);
	for (int i = 1; i <= n+1; i++) {
		int cur;
		scanf("%d", &cur);
		d[i] = d[i - 1] + cur;
	}

	for (int i = 1; i <= n; i++) {
		scanf("%d", &t[i]);
	}

	for (int i = 1; i < n + 2; i++) {
		dp[i] = INFINITI;
	}

	for (int i = 1; i < n + 2; i++) {
		if (d[i] <= limit) {
			dp[i] = t[i];
			p[i] = i;
		}
		else {
			for (int j = 1; j < i; j++) {
				if (d[i] - d[j] <= limit) {
					if (dp[i] > dp[j]) {
						dp[i] = dp[j];
						p[i] = j;
					}
				}
			}
			dp[i] += t[i];
		}
	}
	int idx = n + 1;
	int parents[MAX_N] = { 0 };
	int pNum = 0;
	while (p[idx] != idx) {
		parents[pNum++] = p[idx];
		idx = p[idx];
	}

	printf("%d\n", dp[n + 1]);
	if (pNum) {
		printf("%d\n", pNum);
	}
	for (int i = pNum - 1; i >= 0; i--) {
		printf("%d ", parents[i]);
	}
	printf("\n");

	return 0;
}
