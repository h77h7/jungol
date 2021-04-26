//최단거리니까 bfs

#include <iostream>

using namespace std;

const int MAX_N = 50;
const int dx[4] = { 1,0,-1,0 }; // 우하좌상
const int dy[4] = { 0,1,0,-1 };

char map[MAX_N+2][MAX_N+2] = { 0 };
int fx[MAX_N*MAX_N] = { 0 };
int fy[MAX_N*MAX_N] = { 0 };
int fStart = 0;
int fNum = 0;

int minC = 987654321;

const int qSize = MAX_N * MAX_N * 3 * 2;
int q[qSize] = { 0 };
int front = 0;
int rear = 0;

int main() {
	int r, c;
	scanf("%d %d", &r, &c);

	for (int i = 0; i <= c+1; i++) {
		map[0][i] = 'X';
		map[r + 1][i] = 'X';
	}
	for (int i = 0; i <= r + 1; i++) {
		map[i][0] = 'X';
		map[i][c + 1] = 'X';
	}

	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			scanf(" %c", &map[i][j]);
			if (map[i][j] == 'S') {
				q[front++] = j;
				q[front++] = i;
				q[front++] = 0;
			}
			else if (map[i][j] == '*') {
				fx[fNum] = j;
				fy[fNum++] = i;
			}
		}
	}

	int stage = 1;
	while(front != rear) {
		int x = q[rear++];
		int y = q[rear++];
		int cnt = q[rear++];

		if (stage == cnt) {
			int tmpIdx = 0;
			for (int i = fStart; i < fNum; i++) {
				for (int j = 0; j < 4; j++) {
					if(map[fy[i] + dy[j]][fx[i] + dx[j]] == '.' || map[fy[i] + dy[j]][fx[i] + dx[j]] == 'O') {
						map[fy[i] + dy[j]][fx[i] + dx[j]] = '*';
						fx[fNum + tmpIdx] = fx[i] + dx[j];
						fy[fNum + tmpIdx++] = fy[i] + dy[j];
					}
				}
			}
			fStart = fNum;
			fNum += tmpIdx;
			stage++;
		}

		if (map[y][x] != '*') {
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (map[ny][nx] == '.') {
					q[front++] = nx;
					q[front++] = ny;
					q[front++] = cnt + 1;
					map[ny][nx] = 'O';  //여기서 방문 마킹해야지 queue 사이즈 줄일 수 있음
				}
				else if (map[ny][nx] == 'D') {
					printf("%d\n", cnt + 1);
					return 0;
				}
			}
		}

	}	

	printf("impossible\n");

	return 0;
}
