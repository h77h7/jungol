/**************************************************************
    Problem: 1318
    User: hjee17
    Language: C++
    Result: Success
    Time:1 ms
    Memory:2132 kb
    
    minheap 이용해서 못생긴 수들 구함
    STL priority queue 사용하려면 중복제거 넣어줘야함
****************************************************************/
 
 
#include <iostream>
#include <queue>
 
using namespace std;
 
const int MAX_N = 1500;
 
long long nums[MAX_N+1] = { 0 };
long long heap[MAX_N * 3] = { 0 };
int heapCount = 0;
 
void push(long long v) {
    heap[++heapCount] = v;
    int child = heapCount;
    int parent = child >> 1;
 
    while (parent > 0 && heap[parent] > heap[child]) {
        long long tmp = heap[parent];
        heap[parent] = heap[child];
        heap[child] = tmp;
 
        child = parent;
        parent = child >> 1;
    }
}
 
long long pop() {
    int parent = 1;
    long long ret = heap[parent];
    heap[parent] = heap[heapCount--];
    int child = parent << 1;
    if (child + 1 <= heapCount) child = heap[child] < heap[child + 1] ? child : child + 1;
 
    while (child <= heapCount && heap[parent] > heap[child]) {
        long long tmp = heap[parent];
        heap[parent] = heap[child];
        heap[child] = tmp;
 
        parent = child;
        child = parent << 1;
        if (child + 1 <= heapCount) child = heap[child] < heap[child + 1] ? child : child + 1;
    }
    return ret;
}
int main() {
 
    push(1);
 
    int n = 0; int idx = 0;
    scanf("%d", &n);
 
    while (n) {
        if (nums[n]) printf("%lld\n", nums[n]);
        else {
            while (!nums[n]) {
                long long tmp = pop();
                if (tmp > nums[idx]) {
                    nums[++idx] = tmp;
                    push(tmp * 2);
                    push(tmp * 3);
                    push(tmp * 5);
                }
            }
            printf("%lld\n", nums[n]);
        }
        scanf("%d", &n);
    }
 
    return 0;
}
