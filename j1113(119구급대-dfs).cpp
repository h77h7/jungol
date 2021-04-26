//코너를 돈 횟수를 기록하는 cor배열
//dfs를 하면서 더 작은 코너수로 갱신
#include <iostream>
 
using namespace std;
 
const int MAX_N = 100;
const int INFINITI = 99999;
const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };
 
int map[MAX_N + 2][MAX_N + 2] = { 0 };
int cor[MAX_N + 2][MAX_N + 2];
 
int fx, fy;
 
void dfs(int cx, int cy, int d) {
    for (int i = 0; i < 4; i++) {
        int nx = cx + dx[i];
        int ny = cy + dy[i];
 
        if (map[ny][nx]) {
            if (i == d) {
                if (cor[ny][nx] > cor[cy][cx]) {
                    cor[ny][nx] = cor[cy][cx];
                    if (nx != fx || ny != fy) dfs(nx, ny, d);
                }
            }
            else {
                if (cor[ny][nx] > cor[cy][cx] + 1) {
                    cor[ny][nx] = cor[cy][cx] + 1;
                    if (nx != fx || ny != fy) dfs(nx, ny, i);
                }
            }
        }
    }
}
 
int main() {
    int M, N;
    scanf("%d %d", &M, &N);
 
    scanf("%d %d", &fy, &fx);
    fx++;
    fy++;
 
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            scanf("%d", &map[i][j]);
            cor[i][j] = INFINITI;
        }
    }
    cor[1][1] = -1;
 
    dfs(1, 1,4);
    printf("%d\n", cor[fy][fx]);
 
    return 0;
}
