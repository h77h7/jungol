#include <iostream>
 
using namespace std;
 
int r, c;
char arr[20][20] = { 0, };
bool alpha_check[128] = { false, };
bool visit[20][20] = { false, };
int maxNum = 0;
 
const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };
 
void dfs_recursive(int x, int y, int count) {
    visit[y][x] = true;
    alpha_check[(int)arr[y][x]] = true;
 
    for (int i = 0; i < 4; i++) {
        int nxtx = x + dx[i];
        int nxty = y + dy[i];
 
        if (nxtx >= 0 && nxtx < c && nxty >= 0 && nxty < r && !alpha_check[(int)arr[nxty][nxtx]] && !visit[nxty][nxtx]) {
            dfs_recursive(nxtx, nxty, count + 1);
        }
    }
    if (count > maxNum) maxNum = count;
    visit[y][x] = false;
    alpha_check[(int)arr[y][x]] = false;
}
 
int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
 
    cin >> r >> c;
 
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> arr[i][j];
        }
    }
    dfs_recursive(0, 0, 1);
    cout << maxNum << endl;
    return 0;
}
