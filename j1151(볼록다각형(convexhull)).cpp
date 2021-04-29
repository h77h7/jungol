/**************************************************************
    Problem: 1151
    User: hjee17
    Language: C++
    Result: Success
    Time:1 ms
    Memory:2088 kb
    
    !!기울기 비교하는 방법!!
****************************************************************/
 
 
#include <iostream>
 
using namespace std;
 
typedef long long ll;
 
const int MAX_N = 100;
int points[MAX_N][4] = { 0 };
int s[MAX_N] = { 0 };
int front = -1;
 
ll ccw(int a, int b, int c)
{
    return ( points[b][0] - points[a][0] )*( points[c][1] - points[a][1] ) - ( points[b][1] - points[a][1] ) *( points[c][0] - points[a][0] );
}
 
int points_cmp(int i, int j)    //1이면 j가 뒤로, -1이면 i가 뒤로 가야함
{
    ll a = 1LL * points[i][3] * points[j][2];
    ll b = 1LL * points[j][3] * points[i][2];
    if ( a != b )
    {
        if ( a < b ) return 1;
        else return -1;
    }
    if ( points[i][1] > points[j][1] ) return 1;
    return -1;
}
 
float cal_area()
{
    ll a = 0, b = 0;
    for ( int i = 0; i < front; i++ )
    {
        a += points[s[i]][0] * points[s[i + 1]][1];
        b += points[s[i]][1] * points[s[i + 1]][0];
    }
    a += points[s[front]][0] * points[s[0]][1];
    b += points[s[0]][0] * points[s[front]][1];
    return (float)( a - b ) / 2;
}
 
int main()
{
    int N;
    scanf("%d", &N);
 
    int minY = 0;
    for ( int i = 0; i < N; i++ )
    {
        scanf("%d %d", &points[i][0], &points[i][1]);
        if ( points[minY][1] > points[i][1] ) minY = i;
    }
 
    int tmpx = points[minY][0];
    int tmpy = points[minY][1];
    points[minY][0] = points[0][0];
    points[minY][1] = points[0][1];
    points[0][0] = tmpx;
    points[0][1] = tmpy;
 
    for ( int i = 1; i < N; i++ )
    {
        points[i][2] = points[i][0] - points[0][0];
        points[i][3] = points[i][1] - points[0][1];
    }
 
    for ( int i = 1; i < N-1; i++ )
    {
        for ( int j = i + 1; j < N; j++ )
        {
            if ( points_cmp(i, j) < 0 )
            {
                int tmpx = points[i][0];
                int tmpy = points[i][1];
                int dx = points[i][2];
                int dy = points[i][3];
                points[i][0] = points[j][0];
                points[i][1] = points[j][1];
                points[i][2] = points[j][2];
                points[i][3] = points[j][3];
                points[j][0] = tmpx;
                points[j][1] = tmpy;
                points[j][2] = dx;
                points[j][3] = dy;
            }
        }
    }
 
    s[++front] = 0;
    s[++front] = 1;
    s[++front] = 2;
    for ( int i = 3; i < N; i++ )
    {
        int a = s[front];
        int b = s[front - 1];
        while ( ccw(b, a, i) <= 0 )
        {
            if ( front > 1 )
            {
                front--;
                a = s[front];
                b = s[front - 1];
            }
 
        }
        s[++front] = i;
    }
 
     
    printf("%d\n", (int)(cal_area()+0.5));
    return 0;
}
