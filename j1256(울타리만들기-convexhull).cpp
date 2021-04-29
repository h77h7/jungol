/**************************************************************
    Problem: 1256
    User: hjee17
    Language: C++
    Result: Success
    Time:0 ms
    Memory:2088 kb
    
    !!기울기 비교할때 기울기 같을 때도 꼭 고려해야함!!
****************************************************************/
 
 
#include <iostream>
#include <algorithm>
#include <queue>
 
using namespace std;
 
const int MAX_N = 100;
 
int sx, sy = 987654321; //가장 밑에 있는 점의 x,y좌표
 
struct Point {
    int x;
    int y;
}pArr[MAX_N];
 
deque<Point*> q;
 
int ccw(int x1, int y1, int x2, int y2, int x3, int y3) {
    long long a = x1 * y2 + x2 * y3 + x3 * y1;
    long long b = x2 * y1 + x3 * y2 + x1 * y3;
    return a - b;
}
 
bool comp(Point a, Point b) {
    long long m = 1LL * (a.y - sy)*(b.x - sx);
    long long n = 1LL * (b.y - sy)*(a.x - sx);
    if (m != n) {
        return m < n;
    }
    return a.y > b.y;
}
 
int main() {
    int n;
    scanf("%d", &n);
 
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &pArr[i].x, &pArr[i].y);
        if (sy > pArr[i].y) {
            sx = pArr[i].x;
            sy = pArr[i].y;
        }
    }
 
    sort(pArr, pArr + n, comp);
 
    q.push_back(&pArr[n - 1]);  //정렬 후 sx,sy는 pArr의 마지막에 옴
    q.push_back(&pArr[0]);
 
    for (int i = 1; i < n - 1; i++) {
        Point *a, *b, *c;
        b = q.back();   q.pop_back();
        a = q.back();
        c = &pArr[i];
        while (ccw(a->x, a->y, b->x, b->y, c->x, c->y) <= 0) {
            b = a;  q.pop_back();
            a = q.back();
        }
        q.push_back(b);
        q.push_back(c);
    }
 
    printf("%d\n", q.size());
    while (!q.empty()) {
        printf("%d %d\n", q.front()->x, q.front()->y);
        q.pop_front();
    }
    return 0;
}
