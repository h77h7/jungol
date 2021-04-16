#include <iostream>

using namespace std;

const int MAX_N = 100;
float points[MAX_N][3] = {0};

int main(){
	int N;
	scanf("%d",&N);

	int minY = 0;
	for (int i=0; i<N; i++){
		scanf("%d %d",points[i][0],points[i][1]);
		if(points[minY][1] > points[i][1]) minY = i;
	}

	int tmpx = points[minY][0];
	int tmpy = points[minY][1];
	points[minY][0] = points[0][0];
	points[minY][1] = points[0][1];
	points[0][0] = tmpx;
	points[0][1] = tmpy;

	for(int i=1; i<N; i++){
		points[i][3] = (points[i][1]-points[0][1])/(points[i][0]-points[0][0]);
		printf("%f\n", points[i][3]);
	}


	return 0;
}
