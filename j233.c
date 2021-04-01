#include <stdio.h>
 
int arr[10] = { 0, };
int index = 0;
 
int re(int n, int m) {
    for (int i = 1; i < 7; i++) {
        arr[index] = i;
        if (index == n - 1) {
            int temp = 0;
            for (int j = 0; j <= index; j++) {
                temp += arr[j];
            }
            if (temp == m) {
                for (int j = 0; j <= index; j++) {
                    printf("%d ", arr[j]);
                }
                printf("\n");
                return 0;
            }
        }
        else {
            index++;
            re(n, m);
            index--;
        }
         
    }
 
}
 
int main() {
    int n = 0, m= 0;
 
    scanf("%d %d", &n, &m);
    re(n,m);
    //printf("\n");
 
    return 0;
}
