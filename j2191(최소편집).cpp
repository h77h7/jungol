//Edit distance 문제

#include <iostream>

#define MIN_DIS(x,y,z) ((x<y) ? ((x<z) ? x : z) : ((y<z) ? y : z))
using namespace std;

const int MAX_N = 1001;

int main() {
	int N,M;
	char a[MAX_N];
	char b[MAX_N];
	
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf(" %c", &a[i]);
	}
	scanf(" %d", &M);
	for (int i = 1; i <= M; i++) {
		scanf(" %c", &b[i]);
	}

	int editDistance[MAX_N][MAX_N] = { 0 };

	for (int i = 1; i <= N; i++) {
		editDistance[i][0] = i;
	}
	for (int i = 1; i <= M; i++) {
		editDistance[0][i] = i;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (a[i] == b[j]) editDistance[i][j] = editDistance[i - 1][j - 1];
			else editDistance[i][j] = MIN_DIS(editDistance[i - 1][j], editDistance[i][j - 1], editDistance[i - 1][j - 1]) + 1;
		}
	}
	printf("%d\n", editDistance[N][M]);

	return 0;
}
