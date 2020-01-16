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

int fibonacci(int n) {
	if (n == 0) {
		return 0;
	}
	else if (n == 1) {
		return 1;
	}
	else {
		return fibonacci(n - 1) + fibonacci(n - 2);
	}
	// n이 0인경우와 1인경우는 기저사례
	// 그 외의 경우에는 피보나치 수를 더함
}

int main() {
	int N;
	cin >> N;
	cout << fibonacci(N);
}
