//dp 테이블 : dp[i][j]는 i번째 추까지 사용했을 때 j번째 무게를 잴 수 있는가
//dp[i-1][j]가 1일때
//1) i번째 추 사용하지 않음 : dp[i][j] = 1
//2) i번째 추를 무게를 재는 물체의 반대편에 놓음 : dp[i][j+(i번째 추의 무게)] = 1
//3) i번째 추를 무게를 재는 물체의 편에 놓음 : dp[i][abs(j-(i번째 추의 무게))] = 1
#include <iostream>
#include <cmath>

using namespace std;

const int MAX_CHU = 30;
const int MAX_WEIGHT = 500;

int dp[MAX_CHU][MAX_CHU*MAX_WEIGHT + 1] = { 0 };

int main() {
	int chuNum, gooNum;
	int weightSum;

	scanf("%d", &chuNum);
	
	int sum = 0;
	for (int i = 0; i < chuNum; i++) {
		scanf("%d", &dp[i][0]);
		sum += dp[i][0];
	}

	dp[0][dp[0][0]] = 1;

	for (int i = 1; i < chuNum; i++) {
		dp[i][dp[i][0]] = 1;
		for (int j = 1; j <= sum; j++) {
			if (dp[i - 1][j]) {
				dp[i][j] = 1;
				dp[i][j + dp[i][0]] = 1;
				int tmp = abs(j - dp[i][0]);
				if (tmp > 0) {
					dp[i][tmp] = 1;
				}
			}
		}
	}

	scanf("%d", &gooNum);

	for (int i = 0; i < gooNum; i++) {
		int gw;
		scanf("%d", &gw);
		if (gw <= sum && dp[chuNum - 1][gw]) printf("Y ");
		else printf("N ");
	}
	printf("\n");


	return 0;
}
