#include <stdio.h>
 
int main() {
    setbuf(stdout, NULL);
 
    short dis_x[] = { 1,1,1,0 }; //오위,오,오아,아
    short dis_y[] = { -1,0,1,1 };
 
    int arr[19][19] = { 0, };
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            scanf(" %d", &arr[i][j]);
        }
    }
    int winner = 0;
    int winner_x = -1;
    int winner_y = -1;
    int flag = 1; //winner 찾았는지 체크
    for (int i = 0; i < 19 && flag; i++) { //flag를 for문의 조건부에 넣기
        for (int j = 0; j < 19 && flag; j++) {
            //1 발견
            if (arr[i][j] == 1) {
                for (int k = 0; k < 4; k++) {
                    //이전에 같은 방향에 이미 있었는지 체크
                    if (arr[i - dis_y[k]][j - dis_x[k]] == 1) continue;
 
                    int count = 1;
                    int nxt_x = j + dis_x[k];
                    int nxt_y = i + dis_y[k];
                    while (arr[nxt_y][nxt_x] == 1) {
                        count++;
                        nxt_x += dis_x[k];
                        nxt_y += dis_y[k];
                        //범위체크
                        if (nxt_x > 18 || nxt_y > 18) break;
                    }
                    //오목일때만 승리
                    if (count == 5) {
                        winner = 1;
                        winner_x = j;
                        winner_y = i;
                        flag = 0;
                        break;
                    }
                }
            }
            else if (arr[i][j] == 2) {
                for (int k = 0; k < 4; k++) {
                    if (arr[i - dis_y[k]][j - dis_x[k]] == 2) continue;
                    int count = 1;
                    int nxt_x = j + dis_x[k];
                    int nxt_y = i + dis_y[k];
                    while (arr[nxt_y][nxt_x] == 2) {
                        count++;
                        nxt_x += dis_x[k];
                        nxt_y += dis_y[k];
                        if (nxt_x > 18 || nxt_y > 18) break;
                    }
                    if (count == 5) {
                        winner = 2;
                        winner_x = j;
                        winner_y = i;
                        flag = 0;
                        break;
                    }
                }
            }
        }
    }
    printf("%d\n", winner);
    winner ? printf("%d %d\n", winner_y + 1, winner_x + 1) : printf("\n");
    return 0;
}
