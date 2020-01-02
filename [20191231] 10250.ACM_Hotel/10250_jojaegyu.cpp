#include <stdio.h>
#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <cstdlib>
#include <queue>

using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int H, W, N, T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> H >> W >> N;
		if (N == H * W) {
			cout << H;
			if (W < 10) {
				cout << 0 << W << "\n";
			}
			else {
				cout << W << "\n";
			}
		}
		//마지막 경우의 수 예외 처리
		else if (N % H == 0) {
			cout << H;
			if (N / H + 1 > 10) {
				cout << N / H << "\n";
			}
			else {
				cout << 0 << N / H << "\n";
			}
		}
		// 나머지 가 0인경우 H층이 되어야 함
		else {
			cout << N % H;
			if (N / H + 1 >= 10) {
				cout << N / H + 1 << "\n";
			}
			else {
				cout << 0 << N / H + 1 << "\n";
			}
		}
		// N 번째 손님이 들어갈 방 연산
	}


}
