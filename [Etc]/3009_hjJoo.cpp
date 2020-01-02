#include<stdio.h>
#include<queue>
using namespace std;
int main()
{
    // 쉬운 구현, but 메모리 낭비 높음
    int i;
    int x[1001]={0,};
    int y[1001]={0,};
    int x1, y1;
    
    for(i=0;i<3;i++){
        scanf("%d %d",&x1,&y1);
        x[x1]+=1;
        y[y1]+=1;
    }
    for(i=1;i<=1000;i++){
        if(x[i]==1) printf("%d ",i);
    }
    for(i=1;i<=1000;i++){
        if(y[i]==1) printf("%d",i);
    }
}
