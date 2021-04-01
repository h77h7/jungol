#include <iostream>

using namespace std;

const int STACK_SIZE = 10000;
const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };
int Y, X;
int cheese[100][100] = { 0, };
bool roundCheck[100][100] = { false, };

bool visit[100][100] = { false, };

struct Node {
	int x;
	int y;

	Node(int x, int y) {
		this->x = x;
		this->y = y;
	}
};

Node* stack[STACK_SIZE];
int front = -1;

bool isEmpty() {
	if (front < 0) return true;
	else return false;
}

void push(int x, int y) {
	if (front + 1 < STACK_SIZE) {
		stack[++front]->x = x;
		stack[front]->y = y;
	}
}

Node* pop() {
	if (!isEmpty()) return stack[front--];
	return nullptr;
}

int dfs_loop(int x, int y) {
	push(x, y);
	int count = 0;

	while (!isEmpty()) {
		Node* cur = pop();

		if (!visit[cur->y][cur->x]) {
			visit[cur->y][cur->x] = true;

			int nxtx[4] = { 0, };
			int nxty[4] = { 0, };

			for (int i = 0; i < 4; i++) {
				nxtx[i] = cur->x + dx[i];
				nxty[i] = cur->y + dy[i];

				if (cheese[nxty[i]][nxtx[i]] == 1) {
					cheese[nxty[i]][nxtx[i]] = 0;
					visit[nxty[i]][nxtx[i]] = true;
					count++;
				}
			}

			for (int i = 0; i < 4; i++) {
				if (nxtx[i] >= 0 && nxtx[i] < X && nxty[i] >= 0 && nxty[i] < Y && !visit[nxty[i]][nxtx[i]] && cheese[nxty[i]][nxtx[i]] == 0) {
					push(nxtx[i], nxty[i]);
				}
			}
		}
	}
	return count;
}

int dfs_recursive(int x, int y) {
	visit[y][x] = true;
	int nxtx[4] = { 0, };
	int nxty[4] = { 0, };
	int count = 0;

	for (int i = 0; i < 4; i++) {
		nxtx[i] = x + dx[i];
		nxty[i] = y + dy[i];

		if (nxtx[i] >= 0 && nxtx[i] < X && nxty[i] >= 0 && nxty[i] < Y && !visit[nxty[i]][nxtx[i]] && cheese[nxty[i]][nxtx[i]] == 0) {
			count += dfs_recursive(nxtx[i], nxty[i]);
		}
	}
	for (int i = 0; i < 4; i++) {
		if (cheese[nxty[i]][nxtx[i]] == 1) {
			cheese[nxty[i]][nxtx[i]] = 0;
			visit[nxty[i]][nxtx[i]] = true;
			count++;
		}
	}
	return count;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	for (int i = 0; i < STACK_SIZE; i++) {
		stack[i] = new Node(0, 0);
	}

	int removed_cheese = 0;
	int cheese_num = 0;
	cin >> Y >> X;

	for (int i = 0; i < Y; i++) {
		for (int j = 0; j < X; j++) {
			cin >> cheese[i][j];
			if (cheese[i][j] == 1) cheese_num++;
		}
	}

	int round = 0;
	int remain_cheese = 0;

	while (removed_cheese != cheese_num) {
		round++;
		remain_cheese = cheese_num - removed_cheese;
		removed_cheese += dfs_loop(0, 0);
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				visit[i][j] = false;
			}
		}
	}
	cout << round << endl << remain_cheese << endl;

	return 0;

}