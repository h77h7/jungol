//knapsack 문제
//DP
//보석 1개씩만 있음
#include <iostream>

#define MAX_VALUE(x,y) (x>y?x:y)

using namespace std;

const int MAX_N = 1001;
const int MAX_W = 10001;
int gems[MAX_N][2] = { 0 };
int k[MAX_N][MAX_W] = { 0 };

int main() {
	int N, W;
	cin >> N >> W;

	for (int i = 1; i <= N; i++) {
		cin >> gems[i][0] >> gems[i][1];
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= W; j++) {
			if (gems[i][0] > j) {
				k[i][j] = k[i - 1][j];
			}
			else {
				k[i][j] = MAX_VALUE(k[i-1][j - gems[i][0]] + gems[i][1], k[i - 1][j]);
			}
		}
	}
	cout << k[N][W] << endl;

	return 0;
}
