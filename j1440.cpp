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
 
    int v1Parents[TREE_SIZE] = { 0, };
    int v2Parents[TREE_SIZE] = { 0, };
 
    v1Parents[0] = v1;
    v2Parents[0] = v2;
    for (int i = 1; i < TREE_SIZE; i++) {
        if (!v1Parents[i - 1] && !v2Parents[i - 1]) break;
        v1Parents[i] = tree[v1Parents[i - 1]];
        v2Parents[i] = tree[v2Parents[i - 1]];
    }
 
    int commonP = 0;
    for (int i = 0; i < TREE_SIZE; i++) {
        for (int j = 0; j < TREE_SIZE; j++) {
            if (v1Parents[i] == v2Parents[j]) {
                commonP = v1Parents[i];
                break;
            }
        }
        if (commonP) break;
    }
 
    cout << commonP << endl;
 
    return 0;
}
