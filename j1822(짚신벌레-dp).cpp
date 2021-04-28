//dp 테이블의 0행은 죽는 벌레를 고려하지 않은 벌레 수
//dp 테이블의 1행은 죽는 벌레를 고려한 수
#include <iostream>

using namespace std;

const int MAX_N = 1000000;
const int DEV = 1000;

int dp[MAX_N + 1][2] = { 0 };

int main() {
	int a, b, d, N;
	scanf("%d %d %d %d", &a, &b, &d, &N);

	dp[0][0] = 1;
	dp[0][1] = 1;

	for (int i = 1; i <= N; i++) {
		if (i - a < 0) {
			dp[i][0] = 1;
			dp[i][1] = 1;
		}
		else {
			if (i - b < 0) {
				dp[i][0] = (dp[i - 1][0] + dp[i - a][0])%DEV;
				dp[i][1] = dp[i][0];
			}
			else {
				dp[i][0] = (dp[i - 1][0] + dp[i - a][0] - dp[i - b][0])%DEV;
				if (dp[i][0] < 0) dp[i][0] += 1000;
				if (i - d < 0) {
					dp[i][1] = dp[i][0];
				}
				else {
					dp[i][1] = dp[i][0] - dp[i - d][0];
					if (dp[i][1] < 0) dp[i][1] += 1000;
				}
			}
		}
	}

	printf("%d\n", dp[N][1]);

	return 0;
}
