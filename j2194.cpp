#include <iostream>
 
using namespace std;
 
int main() {
    int n = 0, s = 0;
    int pre_c = 0;
    int cur_c = 0;
    int y = 0;
 
    cin >> n >> s;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> cur_c >> y;
        if (pre_c) cur_c = cur_c > pre_c + s ? pre_c + s : cur_c;
        sum += cur_c * y;
        pre_c = cur_c;
    }
 
    cout << sum << endl;
}
