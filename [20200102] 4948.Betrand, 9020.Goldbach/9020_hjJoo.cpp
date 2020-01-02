#include<stdio.h>
#include<vector>
#include<math.h>
using namespace std;
int main()
{
    int i, j;
    
    // MARK: 소수 구하기 알고리즘
    bool checkPrime[10000]={false,};     // 소수 여부 확인 (소수:1, 소수X:0)
    checkPrime[2]=true;
    
    bool check;
    for(i=3;i<10000; i+=2){
        check=true;
        for(j=3; j<=sqrt(i); j+=2){
            if(i%j==0) {check=false; break;}
        }
        checkPrime[i]=check;
    }
    
    // MARK: 메인 연산
    int t, n;               // 테스트케이스 t, 입력값 n
    int n1, n2;             // 찾으려는 값 n1, n2
    
    scanf("%d",&t);

    for(i=0; i<t; i++){
        scanf("%d",&n);
        n1=(n/2)+1;
        while(1){
            n1-=1;
            if(!checkPrime[n1]) continue;
            n2=n-n1;
            if(checkPrime[n2]) { printf("%d %d\n",n1,n2); break; }
        }
    }
}
