#include <stdio.h>
#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <cstdlib>
#include <queue>

using namespace std;

int arr[30000] = {};
vector<int> prime_number;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, T, min = 20001, answer_a = 0, answer_b = 0;
	fill_n(arr, 30000 - 1, 1);
	arr[1] = 0;

	for (int i = 2; i <= 174; i++) {
		if (arr[i] == 1) {
			for (int k = i + i; k < 30000; k += i) {
				arr[k] = 0;
			}
		}
	}

	for (int i = 1; i < 10001; i++) {
		if (arr[i] == 1) {
			prime_number.push_back(i);
		}
	}

	//prime_number 라는 소수 10000이하의 소수를 넣은 배열 생성
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		min = 20001;
		for (int i = 0; i < prime_number.size(); i++) {
			if (prime_number[i] > N) {
				break;
			}
			for (int k = 0; k < prime_number.size(); k++) {
				if (prime_number[k] > N) {
					break;
				}
				if (prime_number[i] + prime_number[k] == N) {
					if (min > abs(prime_number[i] - prime_number[k])) {
						min = abs(prime_number[i] - prime_number[k]);
						answer_a = prime_number[i];
						answer_b = prime_number[k];
					}
				}
			}
		}
		cout << answer_a << " " << answer_b << "\n";
		// N보다 작은 소수의 차이의 최소가 되는 a와 b를 a와 b의 모든 경우의 수를 세서 찾음
		// a는 항상 b보다 같거나 작기떄문에 두 수의 차가 더 크지 않으면 갱신할필요 없음
	}
}
