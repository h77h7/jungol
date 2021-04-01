#include <iostream>
 
using namespace std;
 
int main() {
    int N = 0;
    int stack[80000] = { 0, };
    int heights[80000] = { 0, };
    int nums[80000] = { 0, };
    int top = -1;
    long long sum = 0;
 
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> heights[i];
    }
 
    int idx = 0;
    for (int i = 0; i < N; i++) {
        if (top < 0) stack[++top] = i;
        else {
            while (top > -1 && heights[stack[top]] <= heights[i]) {
                sum += i - stack[top] - 1;
                stack[top] = 0;
                top--;
            }
            stack[++top] = i;
        }
    }
    /*while(heights[idx]) {
        if (top < 0) stack[++top] = idx;
        else {
            while (top > -1 && heights[stack[top]] <= heights[idx]) {
                sum += idx - stack[top] - 1;
                stack[top] = 0;
                top--;
            }
            stack[++top] = idx;
        }
        idx++;
    }*/
    while (top > -1) {
        sum += N - stack[top--] - 1;
    }
    cout << sum << endl;
}
