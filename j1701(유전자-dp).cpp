/**************************************************************
    Problem: 1701
    User: hjee17
    Language: C++
    Result: Success
    Time:70 ms
    Memory:3064 kb
    
    dp[i][j] : i번째 부터 j번째 사이의 최대 KOI 유전자 수
****************************************************************/
 
 
#include <iostream>
 
#define UMAX(x,y) (x<y?y:x)
 
using namespace std;
 
const int MAX_N = 500;
char dna[MAX_N + 1] = { 0 };
int dp[MAX_N][MAX_N] = { 0 };
 
int main() {
    scanf("%s", dna);
 
    int n = 0;
    while (dna[n]) n++;
 
    for (int j = 1; j < n; j++) {
        for (int i = j-1; i >= 0; i--) {
            if ((dna[i] == 'a' && dna[j] == 't') || (dna[i] == 'g' && dna[j] == 'c')) { //i와 j가 유전자 끝이면 dp[i+1][j-1]+2
                dp[i][j] = dp[i + 1][j - 1] + 2;
            }
            int m = 0;
            for (int k = i + 1; k < j; k++) {     //i~j사이에서 XY인 유전자의 길이 찾기
                m = UMAX(m, dp[i][k] + dp[k][j]); 
            }
            dp[i][j] = UMAX(m, dp[i][j]);
        }
    }
 
    printf("%d\n", dp[0][n - 1]);
 
    return 0;
}
