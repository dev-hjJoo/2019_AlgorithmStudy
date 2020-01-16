#include<stdio.h>
int main()
{
    int t;                  // 테스트 케이스
    int h, w, n;            // 층, 방 개수, 손님 번호
    int x, y, result;       // 결과를 도출하기 위한 변수 (x: 호실, y:층수, y:최종 결과)
    
    scanf("%d",&t);
    for(int i=0; i<t; i++){
        scanf("%d %d %d",&h,&w,&n);
        
        // 호실은 나눈 몫에 1 더한 값(단, 꼭대기 층 제외)
        x = (n/h) + 1;
        // 층은 나눈 나머지 값
        y = n % h;
        
        // 나머지가 0이라는 것은 맨 꼭대기 층.
        // 즉, 호실이 바뀌기 전 꼭대기 층이므로 그에 대한 각각의 값처리를 해 준다.
        if(y==0) {x-=1; y=h;}
        
        // 층 수와 호실 사이에 0 처리를 해주기 위한 연산
        result=y*100+x;
        printf("%d\n",result);
    }
}
