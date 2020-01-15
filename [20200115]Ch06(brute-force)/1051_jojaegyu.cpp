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

vector<vector<int>> arr(50, vector<int>(50, 0));

int main() {
	int N,M;
	string str;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> str;
		for (int k = 0; k < M; k++) {
			arr[i][k] = str[k]-'0';
		}
	}
	
	for (int i = min(N, M); i != 0; i--) {
		if (i == 1) {
			cout << 1;
			return 0;
		}
		int distance = i - 1,y=0,x=0;
		while (N != y+distance) {
			while (M != x+distance) {
				if (arr[y][x] == arr[y][x + distance] && arr[y][x] == arr[y + distance][x] && arr[y][x] == arr[y + distance][x + distance]) {
					cout << i * i;
					return 0;
				}
				x++;
				}
			x = 0;
			y++;
		}
	}
}
