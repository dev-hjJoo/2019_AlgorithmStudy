#include <stdio.h>
#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <cstdlib>
#include <queue>
#include <algorithm>
#include <list>
#include <cmath>

using namespace std;

vector<int> v;

void hanoi(int a,int b,int n) {
	if (n == 1) {
		v.push_back(a);
		v.push_back(b);
	}
	else {
		hanoi(a, 6 - b - a, n - 1); // a,b가 1,3인경우 1,2로 만들어야 하고 1,2 인 경우 1,3으로 만들어야 함
		v.push_back(a);
		v.push_back(b);
		hanoi(6 - a - b, b, n - 1); // a,b가 2,3인 경우 1,3으로 만들어야 하고 1,3인 경우 2,3으로 만들어야 함
	}
}


int main() {
	int N;
	cin >> N;
	hanoi(1, 3, N);
	cout << v.size() / 2 << "\n";
	for (int i = 0; i < v.size(); i += 2) {
		cout << v[i] << " " << v[i + 1] << "\n";
	}
//출력
}
