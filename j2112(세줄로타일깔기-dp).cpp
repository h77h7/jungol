/****************************
f(n) = f(n-2) + 2*g(n-1)
g(n) = f(n-1) + g(n-2)
g는 한 구석의 타일이 없는 모양
 ex)  ****  : g(3)
      ****
       ***
***************************/
#include <iostream>

using namespace std;

const int MAX_N = 30;

int fArr[MAX_N + 1] = { 0 };
int gArr[MAX_N + 1] = { 0 };

int g(int n);

int f(int n) {
	if (n < 2) return fArr[n];
	if (fArr[n]) return fArr[n];
	fArr[n] = f(n - 2) + 2 * g(n - 1);
	return fArr[n];
}

int g(int n) {
	if (n < 2) return gArr[n];
	if (gArr[n]) return gArr[n];
	gArr[n] = f(n - 1) + g(n - 2);
	return gArr[n];
}

int main() {
	int N;
	scanf("%d", &N);

	fArr[0] = 1;
	fArr[1] = 0;
	gArr[0] = 0;
	gArr[1] = 1;

	if (N & 1) printf("0\n");
	else printf("%d\n", f(N));

	return 0;
}
