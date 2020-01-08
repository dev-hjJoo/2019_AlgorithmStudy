#include <stdio.h>
#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <cstdlib>
#include <queue>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
vector<vector<int>> arr(22, vector<int>(22, 7653));
int L_shape[4][3][2] = {
	 { {0,0},{1,0},{1,1} }
	,{ {0,0},{1,0},{0,1} }
	,{ {0,0},{0,1},{1,1} }
	,{ {0,0},{1,0},{1,-1} }
};
//y,x

int check_L(int shape_number,int H,int W,vector<vector<int>> arr) {
	for (int k = 0; k < 3; k++) {
		if (arr[H + L_shape[shape_number][k][0]][W + L_shape[shape_number][k][1]] != 0 ) {
			return 0;
		}
	}
	return 1;
}


//L 에서 시계방향으로 돌리기
int H, W;


int game(vector<vector<int>> arr) {
	int first_white_H, first_white_W,ret=0,count=0;
	/*for (int i = 1; i <= H; i++) {
		for (int k = 1; k <= W; k++) {
			cout << arr[i][k] << " ";
		}
		cout << "\n";
	}
	cout << "\n";*/

	for (int i = 1; i <= H; i++) {
		for (int k = 1; k <= W; k++) {
			if (arr[i][k] == 0) {
				count += 1;
			}
		}
	}
	if (count % 3 != 0) {
		return 0;
	}
	if (count == 0) {
		return 1;
	}
	//test
	bool end = false;
	for (int i = 1; i <= H; i++) {
		for (int k = 1; k <= W; k++) {
			if (arr[i][k] == 0) {
				first_white_H = i;
				first_white_W = k;
				end = true;
				break;
			}
		}
		if (end) {
			break;
		}
	}
	// 가장 윗쪽과 왼쪽에 있는 하얀 칸 찾기
	

	for (int i = 0; i < 4; i++) {
		if (check_L(i, first_white_H, first_white_W, arr)) {
			for (int k = 0; k < 3; k++) {
				arr[first_white_H + L_shape[i][k][0]]
					[first_white_W + L_shape[i][k][1]] = 1;
			}
			ret += game(arr);
			for (int k = 0; k < 3; k++) {
				arr[first_white_H + L_shape[i][k][0]]
					[first_white_W + L_shape[i][k][1]] = 0;
			}
		}
	}
	return ret;
}
int main() {
	string str;
	cin >> H >> W;
	// H,W

	for (int i = 0; i < H; i++) {
		cin >> str;
		for (int k = 0; k < str.size(); k++) {
			if (str[k] == '#') {
				arr[i + 1][k + 1] = 1;
			}
			else {
				arr[i + 1][k + 1] = 0;
			}
		}
	}
	// #인경우 검은칸 .인경우 하얀칸

	for (int i = 1; i <= H; i++) {
		for (int k = 1; k <= W; k++) {
			cout << arr[i][k] << " ";
		}
		cout << "\n";
	}
	cout << game(arr);
}
