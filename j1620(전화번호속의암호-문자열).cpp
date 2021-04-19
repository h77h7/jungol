//문자열 조작
#include <iostream>

using namespace std;

const int MAX_LEN = 101;
const char* error = { "INPUT ERROR!\n" };
char s[MAX_LEN] = { 0 };

int main() {
	
	char psw[5] = { 0 };
	int hypenIdx[50] = { 0 };
	
	int p, m;

	scanf("%s %d %d", s, &p, &m);

	int idx = 0;
	int hIdx = 0;
	int numN = 0;

	while (*(s + idx)) {
		if (*(s + idx) == '-') {
			if (numN > 4) {
				printf("%s", error);
				return 0;
			}
			hypenIdx[hIdx++] = idx;
			numN = 0;
		}
		else numN++;
		idx++;
	}
	hypenIdx[hIdx++] = idx;

	if (!hypenIdx[m-1]) {
		printf("%s", error);
		return 0;
	}
	else idx = hypenIdx[m-1]-1;

	int pswIdx = 3;
	while (*(s + idx) != '-' && idx>=0) {
		psw[pswIdx--] = *(s + idx);
		idx--;
	}
	while (pswIdx >= 0) {
		psw[pswIdx--] = '0';
	}

	for (int i = 0; i < 4; i++) {
		int tmp = psw[i] - '0';
		tmp += p;
		tmp %= 10;
		psw[i] = tmp + '0';
	}

	printf("%s\n", psw);
	return 0;
}
