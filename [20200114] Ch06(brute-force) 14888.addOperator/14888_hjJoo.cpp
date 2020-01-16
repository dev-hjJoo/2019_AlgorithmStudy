#include<stdio.h>
#include<queue>
using namespace std;
//MARK: 전역변수 선언부
int maxValue = -1000000000;
int minValue = 1000000000;
//MARK: 연산 함수
void findResult(queue<int> value, int plus, int minus, int mul, int div, int result){
    // 값이 들어있는 큐 내부가 비면(피연산자 모두 연산 완료 시) 최대/최소값 구별 후 함수 종료
    if(value.empty()){
        maxValue=max(maxValue,result);
        minValue=min(minValue,result);
        return;
    }
    // 연산자 우선순위와 상관없이 앞에서부터 진행하므로 앞의 숫자를 뽑아준다.
    int temp = value.front();
    value.pop();
    // 각 연산에 대해 모두 탐색
    if(plus!=0) findResult(value, plus-1, minus, mul, div, result+temp);
    if(minus!=0) findResult(value, plus, minus-1, mul, div, result-temp);
    if(mul!=0) findResult(value, plus, minus, mul-1, div, result*temp);
    if(div!=0) findResult(value, plus, minus, mul, div-1, result/temp);
    
}
//MARK: main 함수
int main()
{
    int N;                  // 피연산자 개수
    int n;                  // 입력(피연산자)
    int operate[4];         // 각 연산자 개수(0:+, 1:-, 2:*, 3:/)
    queue<int> value;
    
    scanf("%d",&N);
    // 피연산자 값 입력
    for(int i=0; i<N; i++){
        scanf("%d",&n);
        value.push(n);
    }
    // 연산자 수 입력
    for(int i=0; i<4; i++){
        scanf("%d",&operate[i]);
    }
    // 값 처리
    int temp=value.front();
    value.pop();
    findResult(value, operate[0], operate[1], operate[2], operate[3], temp);
    printf("%d\n%d\n",maxValue,minValue);
}
