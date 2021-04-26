//각자의 부모를 기록한 배열을 생성
//부모를 따라가며 촌수 찾기
//예외처리(ex 직계) 주의

#include <iostream>
 
using namespace std;
 
const int MAX_N = 100;
int pArr[MAX_N + 1] = { 0 };
 
int main() {
    int n, x, y, m;
    scanf("%d %d %d %d", &n, &x, &y, &m);
 
    int p, c;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &p, &c);
        pArr[c] = p;
    }
 
    int xP[MAX_N] = { 0 };
    int yP[MAX_N] = { 0 };
    int xNum = 0;
    int yNum = 0;
    int nx = x;
    int ny = y;
    int answer = -1;
 
    xP[xNum++] = x;
    yP[yNum++] = y;
    while (pArr[nx]) {
        xP[xNum++] = pArr[nx];
        nx = pArr[nx];
    }
    while (pArr[ny]) {
        yP[yNum++] = pArr[ny];
        ny = pArr[ny];
    }
     
    for (int i = 0; i < xNum; i++) {
        for (int j = 0; j < yNum; j++) {
            if (xP[i] == yP[j]) {
                answer = i + j;
                break;
            }
        }
        if (answer >= 0) break;
    }
 
 
    printf("%d\n", answer);
 
    return 0;
}
