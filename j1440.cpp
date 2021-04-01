#include <iostream>
 
using namespace std;
 
const int TREE_SIZE = 10001;
int tree[TREE_SIZE];
 
int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
 
    //트리 초기화
    for (int i = 0; i < TREE_SIZE; i++) {
        tree[i] = 0;
    }
 
    int N;
    cin >> N;
 
    int parent, child;
    for (int i = 0; i < N-1; i++) {
        cin >> parent >> child;
        tree[child] = parent;
    }
 
    int v1, v2;
 
    cin >> v1 >> v2;
 
    int commonP = 0;
    bool visit1[TREE_SIZE] = { false, };
    bool visit2[TREE_SIZE] = { false, };
 
    for (int i = 0; i < TREE_SIZE; i++) {
        if (v1 == v2) {
            commonP = v1;
            break;
        }
        if (visit2[v1]) {
            commonP = v1;
            break;
        }
        else if (visit1[v2]) {
            commonP = v2;
            break;
        }
        visit1[v1] = true;
        visit2[v2] = true;
        v1 = tree[v1];
        v2 = tree[v2];
    }
 
    cout << commonP << endl;
 
    return 0;
}
