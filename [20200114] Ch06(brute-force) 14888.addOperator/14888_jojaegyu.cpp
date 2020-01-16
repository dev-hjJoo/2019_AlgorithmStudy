#include <stdio.h>
#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <cstdlib>
#include <queue>
#include <algorithm>
#include <cmath>
#include <list>

using namespace std;

vector<int> arr;
int N;
int minimum = 1000000000;
int maximum = -1000000000;
vector<int> oper_list;

int insert_operator(int cal, vector<int> oper, int arr_number) {
	arr_number++;
	if (arr_number == N) {
		if (minimum > cal) {
			minimum = cal;
		}
		if (maximum < cal) {
			maximum = cal;
		}
		return 0;
	}
	// 모든 연산이 끝나고 난 뒤 최대값과 최소값을 갱신
	if (oper[0] != 0) {
		oper[0] -= 1;
		insert_operator(cal + arr[arr_number], oper, arr_number);
		oper[0] += 1;
	}
	if (oper[1] != 0) {
		oper[1] -= 1;
		insert_operator(cal - arr[arr_number], oper, arr_number);
		oper[1] += 1;
	}
	if (oper[2] != 0) {
		oper[2] -= 1;
		insert_operator(cal * arr[arr_number], oper, arr_number);
		oper[2] += 1;
	}
	if (oper[3] != 0) {
		oper[3] -= 1;
		insert_operator(cal / arr[arr_number], oper, arr_number);
		oper[3] += 1;
	}
	return 0;
}
// 각 연산자를 한번 사용하면 해당 연산자의 개수를 하나 줄인뒤 재귀호출함.


int main() {
	int num;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num;
		arr.push_back(num);
	}
	for (int i = 0; i < 4; i++) {
		cin >> num;
		oper_list.push_back(num);
	}
	insert_operator(arr[0], oper_list, 0);
	cout << maximum << "\n" << minimum;
	//연산자 리스트는 oper_list에 숫자 리스트는 arr에
}
