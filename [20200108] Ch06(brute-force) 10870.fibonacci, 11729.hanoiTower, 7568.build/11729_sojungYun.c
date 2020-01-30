#include <stdio.h>
int dp[21];

void hanoi(int n, int a, int b, int left){
	if (n == 1){
		printf("%d %d\n", a, b);
	}
	else{
		hanoi(n - 1, a, left, b); //원판 n-1개를 a에서 left로 이동
		hanoi(1, a, b, left); //a에 남은 원판 1개를 a에서 b로 이동
		hanoi(n - 1, left, b, a); //left에 있는 원판 n-1개를 b로 이동
	}
}

int main(){
	int N;
	scanf("%d", &N); //원판의 개수 N을 입력받는다.
	dp[1] = 1;
	for (int i = 2; i <= N; ++i){
		dp[i] = dp[i - 1] * 2 + 1; //원판 이동 횟수를 배열에 저장
	}
	printf("%d\n", dp[N]); //원판이 N개일 때, 총 이동 횟수를 출력
	hanoi(N, 1, 3, 2);
}

