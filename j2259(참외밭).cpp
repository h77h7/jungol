//밭 모양대로 조건 잘 따지기
#include <iostream>

using namespace std;

int map[7][2] = { 0 };

int main() {
	int K;
	scanf("%d", &K);

	int maxXIdx = 6;
	int maxYIdx = 6;
	for (int i = 0; i < 6; i++) {
		scanf("%d %d", &map[i][0], &map[i][1]);
		
		if (map[i][0] == 1 || map[i][0] == 2) {
			if (map[maxXIdx][1] < map[i][1]) maxXIdx = i;
		}
		else {
			if (map[maxYIdx][1] < map[i][1]) maxYIdx = i;
		}
	}

	int x1 = map[maxXIdx][1];
	int y1 = map[maxYIdx][1];
	int x2 = 0;
	int y2 = 0;
	if ((maxXIdx + 1) % 6 == maxYIdx) {
		x2 = map[(maxXIdx + 4) % 6][1];
	}
	else x2 = map[(maxXIdx + 2) % 6][1];
	if ((maxYIdx + 1) % 6 == maxXIdx) {
		y2 = map[(maxYIdx + 4) % 6][1];
	}
	else y2 = map[(maxYIdx + 2) % 6][1];

	int area = x1 * y1 - x2 * y2;
	printf("%d\n", area*K);

	return 0;
}
