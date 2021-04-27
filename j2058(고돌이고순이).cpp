//고돌이는 안움직이고 고순이만 움직이는 경우, 고순이는 안움직이고 고돌이만 움직이는  넣어야함
#include <iostream>
#include <queue>

using namespace std;

const int MAX_N = 25;
const int dx[9] = { 1,1,0,-1,-1,-1,0,1,0 }; //오,오아,아,왼아,왼,왼위,위,오위
const int dy[9] = { 0,1,1,1,0,-1,-1,-1,0 };

int map[MAX_N + 2][MAX_N + 2] = { 0 };
bool visit[MAX_N + 2][MAX_N + 2][MAX_N + 2][MAX_N + 2] = { false };

queue<int> q;

int main() {
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N + 2; i++) {
		map[0][i] = 1;
		map[N + 1][i] = 1;
		map[i][0] = 1;
		map[i][N + 1] = 1;
	}

	int Sx, Sy;
	int shx, shy;
	int Dx, Dy;
	int dhx, dhy;

	scanf("%d %d %d %d", &Dy, &Dx, &dhy, &dhx);
	scanf("%d %d %d %d", &Sy, &Sx, &shy, &shx);

	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	q.push(Sx);
	q.push(Sy);
	q.push(Dx);
	q.push(Dy);
	q.push(0);
	visit[Sx][Sy][Dx][Dy] = true;

	int cnt = 0;
	while (!q.empty()) {
		Sx = q.front();	q.pop();
		Sy = q.front();	q.pop();

		Dx = q.front();	q.pop();
		Dy = q.front();	q.pop();

		cnt = q.front(); q.pop();

		if (Sx == shx && Sy == shy && Dx == dhx && Dy == dhy) {
			printf("%d\n", cnt);
			return 0;
		}

		else {
			for (int i = 0; i < 9; i++) {
				int Snx = Sx + dx[i];
				int Sny = Sy + dy[i];
				if (!map[Sny][Snx]) {
					for (int j = 0; j < 9; j++) {
						int Dnx = Dx + dx[j];
						int Dny = Dy + dy[j];

						if (!map[Dny][Dnx] && !visit[Snx][Sny][Dnx][Dny]) {
							bool flag = true;
							for (int k = 0; k < 9; k++) {
								if (Snx + dx[k] == Dnx && Sny + dy[k] == Dny) flag = false;
							}
							if (flag) {
								q.push(Snx);
								q.push(Sny);
								q.push(Dnx);
								q.push(Dny);
								q.push(cnt + 1);
								visit[Snx][Sny][Dnx][Dny] = true;
							}
						}
					}
				}
			}
		}
	}

	return 0;
}
