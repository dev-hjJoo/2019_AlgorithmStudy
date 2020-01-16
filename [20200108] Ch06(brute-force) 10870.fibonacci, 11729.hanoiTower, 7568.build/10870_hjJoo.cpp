#include<stdio.h>
int fibonacci(int n){
    // 0과 1은 기저 사례로 제외 시키기
    if(n==0) return 0;
    if(n==1) return 1;
    // 재귀 함수를 통해 피보나치 개념을 그대로 반영하기
    return fibonacci(n-1)+fibonacci(n-2);
}
int main()
{
    int n;
    scanf("%d",&n);
    printf("%d",fibonacci(n));
}
