#include <iostream>

using namespace std;

const int MAX = 14;
int cnt = 0;

int make_candidates(int* a, int k, int n, int* c) {
	int candiNum = 0;
	bool check[MAX] = { false, };

	for (int i = 1; i < k; i++) {	
		check[a[i]] = true;		//이미 queen이 놓인 row 제외
		
		int colCha = k - i;		//대각선 체크
		int plus = a[i] + colCha;
		int minus = a[i] - colCha;
		if (plus <= n) check[plus] = true;
		if (minus > 0) check[minus] = true;
	}
	
	for (int i = 1; i <= n; i++) {
		if (!check[i]) c[candiNum++] = i;
	}

	return candiNum;
}

void back_track(int* a, int k, int n) {
	int c[MAX] = { 0, };
	int candiNum = 0;

	if (k == n) {
		cnt++;
	}

	else {
		k++;

		candiNum = make_candidates(a, k, n, c);
		for (int i = 0; i < candiNum; i++) {
			a[k] = c[i];
			back_track(a, k, n);
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	int a[MAX] = { 0, };

	back_track(a, 0, N);

	cout << cnt << endl;
}