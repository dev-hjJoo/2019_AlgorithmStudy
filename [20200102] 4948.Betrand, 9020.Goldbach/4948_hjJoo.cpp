 #include <stdio.h>
#include <math.h>
int main()
{
    const int SIZE=123456;
    int cntPrime[SIZE*2+1]={0,}; //각 인덱스까지의 소수의 개수값 저장, 초기화
    int n;
    int i, j;
    
    //MARK: 소수의 개수 구하기(count number of prime)
    int checkPrime;     // 소수 여부 확인 (=소수:0, 소수X:1)
    int cnt;            // 1부터 i까지의 소수 개수
    
    cnt=1;
    cntPrime[2]=1;
    
    // 수정 전: for(i=2; i<=SIZE*2; i++)
    for(i=3; i<=SIZE*2; i+=2){          // 반복문에서 짝수 제외
        checkPrime=0;
        // 수정 전: for(j=2; j<=sqrt(i); j++)
        for(j=3; j<=sqrt(i); j+=2){             // 짝수를 제외시켰기 때문에 짝수로 나누는 것 무의미
            if(i%j==0) {checkPrime=1;break;}
        }
        if(checkPrime==0) cnt++;        // i가 소수이면 cnt 증가
        cntPrime[i]=cnt;
        cntPrime[i+1]=cnt;
    }
    cntPrime[SIZE*2]=cntPrime[SIZE*2-1];
    
    // MARK: 입력 및 메인 연산
    int result;
    while(1){
        scanf("%d",&n);
        if(n==0) break;
        result=cntPrime[2*n]-cntPrime[n];
        printf("%d\n",result);
    }
}
