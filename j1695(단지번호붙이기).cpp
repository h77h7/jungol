//탐색할때 범위 잘 체크하기

#include <iostream>

using namespace std;

const int MAX_N = 25;

int m[MAX_N][MAX_N] = { 0 };
int g[512] = { 0 };
int gIdx = 0;
int N = 0;
int cnt = 0;

const int dx[4] = { 1,0,-1,0 }; //오아왼위
const int dy[4] = { 0,1,0,-1 };

int move(int sX, int sY) {
	int ret = 1;
	m[sY][sX]++;
	cnt++;
	for (int i = 0; i < 4; i++) {
		int nx = sX + dx[i];
		int ny = sY + dy[i];
		if (nx >= 0 && ny >= 0 && nx < N && ny < N && m[ny][nx] == 1) ret += move(nx, ny);  //범위체크!!!
	}
	return ret;
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%1d", &m[i][j]);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (m[i][j] == 1) {
				cnt = 0;
				g[gIdx++] = move(j, i);
			}
		}
	}

	for (int i = 0; i < gIdx - 1; i++) {
		for (int j = i + 1; j < gIdx; j++) {
			if (g[i] > g[j]) {
				int tmp = g[j];
				g[j] = g[i];
				g[i] = tmp;
			}
		}
	}
		
	printf("%d\n", gIdx);
	for (int i = 0; i < gIdx; i++) {
		printf("%d\n", g[i]);
	}

	return 0;
}
