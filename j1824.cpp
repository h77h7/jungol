#include <iostream>

using namespace std;

const int EMPTY_SIZE = 82;

int ex[EMPTY_SIZE] = { 0, };
int ey[EMPTY_SIZE] = { 0, };
int sdoku[9][9] = { 0, };

void processSolution(int k, int n) {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << sdoku[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int makeCandidate(int x, int y, int* c) {
	bool check[10] = { false, };
	int candiNum = 0;

	for (int i = 0; i < 9; i++) {
		check[sdoku[i][x]] = true;
		check[sdoku[y][i]] = true;
	}

	int x_start = x - (x % 3);
	int	y_start = y - (y % 3);
	int x_end = x_start + 3;
	int y_end = y_start + 3;

	for (int i = y_start; i < y_end; i++) {
		for (int j = x_start; j < x_end; j++) {
			check[sdoku[i][j]] = true;
		}
	}
	
	for (int i = 1; i < 10; i++) {
		if (!check[i]) c[candiNum++] = i;
	}
	return candiNum;
}

bool backTrack(int k, int n) {
	int c[9] = { 0, };
	int candi_num;

	if (k == n) {
		processSolution(k, n);
		return true;
	}
	else {
		k++;

		candi_num = makeCandidate(ex[k], ey[k], c);

		for (int i = 0; i < candi_num; i++) {
			sdoku[ey[k]][ex[k]] = c[i];
			if (backTrack(k, n)) return true;
		}
		sdoku[ey[k]][ex[k]] = 0;
		return false;
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int empty_num = 0;

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> sdoku[i][j];
			if (sdoku[i][j] == 0) {
				empty_num++;	//ºóÄ­ °³¼ö ¼¼±â
				ex[empty_num] = j;	//ºóÄ­ ÀÎµ¦½º ÀúÀå
				ey[empty_num] = i;
			}
		}
	}

	backTrack(0, empty_num);
}