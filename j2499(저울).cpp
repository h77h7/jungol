//정렬을 먼저 하고 새로운 수가 minweigh보다 작거나 같을때만 측정 가능한 무게가 연속적이라는 점 이용
//ex) 예시 : 20 < 30이기 때문에 20까지가 연속적으로 측정가능한 무게의 끝
#include <iostream>

using namespace std;

const int MAX_N = 1000;
int w[MAX_N] = { 0 };

void quickSort(int start, int end) {
	if (start < end) {
		int pivot = w[start];
		int i = start + 1;
		int j = end;
	

		while (i <= j) {
			while (i <= end && w[i] <= pivot) i++;
			while (j >= start && w[j] > pivot) j--;

			if (i < j) {
				int tmp = w[i];
				w[i] = w[j];
				w[j] = tmp;
			}
		}
		int tmp = w[j];
		w[j] = pivot;
		w[start] = tmp;
		quickSort(start, j-1);
		quickSort(j+1, end);
	}
}

int main() {
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &w[i]);
	}

	quickSort(0, N - 1);

	if (w[0] > 1) {
		printf("1\n");
		return 0;
	}

	int minWeight = 1;
	for (int i = 1; i < N; i++) {
		if (w[i] > minWeight + 1) {
			break;
		}
		minWeight += w[i];
	}
	minWeight++;
	printf("%d\n", minWeight);


	return 0;
}
