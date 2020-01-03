#include <stdio.h>
#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <cstdlib>
#include <queue>
#include <algorithm>
#include <cmath>

#define pi 3.141592653589793238;
using namespace std;


int main(){
	int T,x1, y1, r1, x2, y2, r2;
	double d;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		d = sqrt((pow(abs(x2 - x1), 2) + pow(abs(y2 - y1), 2))); // 두 수 거리 계산

		if (x1 == x2 && y1 == y2 && r1 == r2) {
			cout << -1 << "\n";
		}
		// 원이 겹치는 경우
		else if (d + min(r1, r2) == max(r1, r2)) {
			cout << 1 << "\n";
		}
		// 원이 원안에 있고 교점이 1개인 경우
		else if (d + min(r1, r2) < max(r1, r2)) {
			cout << 0 << "\n";
		}
		// 원이 원안에 있고 교점이 생기지 않는 경우
		else if (d == r1 + r2) {
			cout << 1 << "\n";
		}
		// 원이 원밖에 있고 교점이 1개인 경우
		else if (d > r1 + r2) {
			cout << 0 << "\n";
		}
		// 원이 원 밖에 있고 교점이 없는 경우
		else {
			cout << 2 << "\n";
		}
		// 원이 원 밖에 있고 교점이 2개인 경우
	}

}
