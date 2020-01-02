#include <stdio.h>
#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <cstdlib>
#include <queue>

using namespace std;

int arr[300000] = {};

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N,count=0;
	fill_n(arr, 300000-1, 1);
	arr[1] = 0;

	for (int i = 2; i <= 548; i++) {
		if (arr[i] == 1) {
			for (int k = i+i; k < 300000; k += i) {
				arr[k] = 0;
			}
		}
	}
  // 에라토네스의 체를 구현하여 소수찾기
	
	while (1) {
		cin >> N;
		count = 0;
		if (N == 0) {
			break;
		}

		for (int i = N + 1; i <= 2 * N; i++) {
			if (arr[i] == 1) {
				count += 1;
			}
		}
		cout << count << "\n";
	}	
  // N+1 부터 2N까지의 소수의 갯수 
}
