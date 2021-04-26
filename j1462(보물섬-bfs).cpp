//L만날때마다 bfs해서 거리 

#include <iostream>
 
using namespace std;
 
const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };
 
const int MAX_N = 50;
char map[MAX_N][MAX_N] = { 0 };
bool visit[MAX_N][MAX_N] = { false };
 
const int qSize = MAX_N * MAX_N * 3 * 2;
int q[qSize] = { 0 };
int front = 0;
int rear = 0;
 
int maxD = 0;
 
void bfs(int m, int n) {
    while (front != rear) {
        int x = q[(rear++) % qSize];
        int y = q[(rear++) % qSize];
        int c = q[(rear++) % qSize];
        if (!visit[y][x]) {
            visit[y][x] = true;
            if (c > maxD)
                maxD = c;
 
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                if (map[ny][nx] == 'L' && !visit[ny][nx]) {
                    q[(front++) % qSize] = nx;
                    q[(front++) % qSize] = ny;
                    q[(front++) % qSize] = c + 1;
                }
            }
        }
 
    }
}
 
int main() {
    int m, n;
    scanf("%d %d", &m, &n);
 
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf(" %c", &map[i][j]);
        }
    }
 
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i][j] == 'L') {
                q[front++] = j;
                q[front++] = i;
                q[front++] = 0;
 
                bfs(m, n);
                front = 0;
                rear = 0;
                for (int i = 0; i < m; i++) {
                    for (int j = 0; j < n; j++) {
                        visit[i][j] = false;
                    }
                }
            }
        }
    }
 
    printf("%d\n", maxD);
 
    return 0;
}
