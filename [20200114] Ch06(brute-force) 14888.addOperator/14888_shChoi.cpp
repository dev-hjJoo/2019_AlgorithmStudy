#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 1000000000 + 1;
int N;
int Data[11];
int Operator[4];

int result_max = -MAX;                                                       //최대값 비교를 위해
int result_min = MAX;                                                        //최솟값 비교를 위해

void DFS (int plus, int minus, int multiply, int divide, int cnt, int sum) {            //재귀함수를 이용
	if (N == cnt){
		result_max = max(result_max, sum);                                         //최댓값 재귀를 돌며 체크
		result_min = min(result_min, sum);                                         //최솟값 재귀를 돌며 체크 
	}

	if (plus > 0)                                                                //더하기 값이 주어졌을 때
		DFS(plus - 1, minus, multiply, divide, cnt + 1, sum + Data[cnt]); 
	if (minus > 0)                                                               //빼기 값이 주어졌을 때
		DFS(plus, minus - 1, multiply, divide, cnt + 1, sum - Data[cnt]);
	if (multiply > 0)                                                            //곱하기 값이 주어졌을 때
		DFS(plus, minus, multiply - 1, divide, cnt + 1, sum * Data[cnt]);
	if (divide > 0)                                                              //나누기 값이 주어졌을 때
		DFS(plus, minus, multiply, divide - 1, cnt + 1, sum / Data[cnt]);
}

int main() {

	cin >> N;
	
	for (int i = 0; i < N; i++)
		cin >> Data[i];                                                             //N값 만큼 데이터를 입력 받음
	
	for (int i = 0; i < 4; i++)
		cin >> Operator[i];                                                         // + - * / 순서대로 갯수를 입력 

	DFS (Operator[0], Operator[1], Operator[2], Operator[3], 1, Data[0]);         //재귀 함수 사용
	
	cout << result_max << endl;
	cout << result_min << endl;
}
