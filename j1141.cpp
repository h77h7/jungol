#include <iostream>
 
using namespace std;
 
int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
 
    int N = 0;
    //int heights[80000] = { 0, };
    long long sum = 0;
    int idx = -1;
 
    cin >> N;
    int* heights = new int[N] {0};
    for (int i = 0; i < N; i++) {
        int temp = 0;
        cin >> temp;
        while (idx >= 0 && temp >= heights[idx]) {
            sum += idx;
            idx--;
        }
        heights[++idx] = temp;
    }
    while (idx > 0) {
        sum += idx;
        idx--;
    }
 
    cout << sum << endl;
    if(heights != nullptr) delete[] heights;
}
