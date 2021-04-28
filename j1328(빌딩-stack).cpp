/*************
stack 사용
stack의 top보다 작거나 같은 값만 스택에 넣어줌
stack의 top보다 큰값 만나면 stack에서 빼고 answer배열의 해당 인덱스에 현재 값의 인덱스 넣어줌
**************/
#include <iostream>

using namespace std;

const int MAX_N = 100000;

int buildings[MAX_N + 1] = { 0 };
int answer[MAX_N + 1] = { 0 };
int stack[MAX_N] = { 0 };
int front = -1;

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &buildings[i]);
	}

	for (int i = 1; i <= n; i++) {
		if (front < 0) stack[++front] = i;
		else {
			int tmp = stack[front];
			while (buildings[tmp] < buildings[i]) {
				answer[tmp] = i;
				front--;
				if (front < 0) break;
				else tmp = stack[front];
			}
			stack[++front] = i;
		}
	}
	for (int i = 1; i <= n; i++) {
		printf("%d\n", answer[i]);
	}
	return 0;
}
