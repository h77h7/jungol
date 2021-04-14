//LIS(최장증가부분수열)
//이진탐색 사용( O(nlogn) )
//문제와 LIS사이 관계를 파악하는게 중요
#include <iostream>

using namespace std;

const int MAX_N = 201;

int main() {
	int N;
	scanf("%d", &N);

	int C[MAX_N] = { 0 };
	int s[MAX_N];

	for (int i = 0; i < N; i++) {
		scanf("%d", &s[i]);
	}

	int lis = 0;
	C[0] = s[0];

	for (int i = 1; i < N; i++) {
		int low = 0;
		int high = lis;

		while (low <= high) {
			int mid = (low + high) / 2;
			if (C[mid] < s[i]) low = mid + 1;
			else high = mid - 1;
		}
		C[low] = s[i];
		lis = lis < low ? low : lis;
	}

	printf("%d\n", N - (lis + 1));
	return 0;
}
