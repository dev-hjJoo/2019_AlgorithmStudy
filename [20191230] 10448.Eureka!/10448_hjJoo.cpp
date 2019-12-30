#include<stdio.h>
int main()
{
    int n, k;
    int i, j;
        
    // MARK: 삼각수 구하기
    int t[100]; // T[n]: 삼각수
    int sum=0;
    int cntTriangle=1;
    while(1){
        sum+=cntTriangle;
        if(sum>1000) break;
        t[cntTriangle++]=sum;
    }
    
    // MARK: 삼각수 두 개로 나뉘는 지 여부 찾기
    int x[1000]; // X[n]: 여부 저장 (0:X, 1:O)
    x[1]=0;
    for(k=2; k<1000; k++){
        int key=0;
        int n1, n2;
        for(i=1;t[i]<k; i++){
            n1=t[i];
            n2=k-t[i];
            for(j=1;t[j]<=n2;j++){
                if(t[j]==n2) {key=1; break;}
            }
            if(key==1) break;
        }
        x[k]=key;
    }

    // MARK: 입력 및 실질 연산
    scanf("%d",&n);
    for(i=0; i<n; i++){
        scanf("%d",&k);
        int key=0;
        int n1, n2;
        for(j=1;t[j]<k; j++){
            n1=t[j];
            n2=k-t[j];
            if(x[n2]==1) {key=1; break;}
        }
        if(key==1) printf("1\n");
        else printf("0\n");
    }
}
