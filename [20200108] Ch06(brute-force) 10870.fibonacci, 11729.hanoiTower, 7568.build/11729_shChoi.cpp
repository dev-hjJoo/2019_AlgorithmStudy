#include <iostream>
using namespace std;

void hanoi(int n, int from, int tmp, int to){                     //하노이 탑 호출 함수 (n = 옮긴 횟수, from = 1번 위치, tmp = 2번 위치, to = 3번 위치)
	if(n==1){                                                     //n = 1 즉 마지막 단계를 
		printf("%d %d \n", from, to);
	}
	else {                                                        //n = 1 일 때 까지 계속 재귀적으로 함수를 호출함                                  
		hanoi(n-1, from, to, tmp);                                  //1번 위치에서 2번 위치로 옮기도록 유도    
		printf("%d %d \n", from, to);                               //1번 위치에서 2번 위치로 이동한 것 출력
		hanoi(n-1, tmp, from, to);                                  //1번 위치에서 3번 위치로 옮기도록 유도  
	}
}
int main() {
	int n;
	int count = 1;
	cin >> n;
	for(int i =0; i < n; i++)
		count = count * 2;
	cout << count - 1 << endl;
	hanoi(n , 1, 2, 3);
}

//여기서 가장 깨달은 것: cout의 속도가 느려서 계속 시간 초과가 나왔다. 해결 방법은 그보다 빠른 출력인 printf를 사용하는 것이다.
