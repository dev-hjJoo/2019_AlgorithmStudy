#include<stdio.h>
#include<math.h>
int main()
{
    int t;
    int i;
    
    int x1, x2, y1, y2, r1, r2;
    double distance;
    int sumR,subR;
    int result;
    
    scanf("%d",&t);
    for(i=0;i<t;i++){
        scanf("%d %d %d %d %d %d",&x1,&y1,&r1,&x2,&y2,&r2);
    
        distance=sqrt(((x1-x2)*(x1-x2)) + ((y1-y2)*(y1-y2))); // 두 점의 거리
        sumR = r1+r2;                   // 반지름의 합
        subR = (r1>r2)? r1-r2:r2-r1;    // 반지름의 차 :삼항연산자를 이용해서 큰 수에서 작은 수 빼기
        
        // 원이 일치할 경우 (접점 무한개)
        if(distance==0 && r1==r2) result=-1;
        // 만나지 않을 경우 1. 멀리 떨어진 경우
        else if(distance>sumR) result=0;
        // 만나지 않을 경우 2. 한 원이 다른 원에 포함 된 경우
        else if(distance<subR) result=0;
        // 한 점에서 만나는 경우 1. 외접
        else if(distance==sumR) result=1;
        // 한 점에서 만나는 경우 2. 내접
        else if(distance==subR) result=1;
        // 두 점에서 만나는 경우 (distance<sumR && distance>subR)
        else result=2;

        printf("%d\n",result);
    }
}
