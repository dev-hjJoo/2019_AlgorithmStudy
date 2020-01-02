#include <stdio.h>
int main()
{
    int x, y, w, h;
    int min=1001;
    
    scanf("%d %d %d %d",&x,&y,&w,&h);
    
    int length[4]={w-x,x,h-y,y}; // 각 테두리와의 길이
    int i;
    for(i=0;i<4;i++){           // 반복문을 이용하여 최소값 탐색
        if(min>length[i]) min=length[i];
    }
    printf("%d",min);
    
}
