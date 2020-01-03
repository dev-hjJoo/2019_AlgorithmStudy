#include <stdio.h>

int main(int argc, const char * argv[]) {
    int n=0;
    while (1) {
        scanf("%d", &n);
        if (n==0) {
            break;
        }
        //에라토스테네스의 체 사용
        int array[246912] = {0, }; //배열을 0으로 초기화하고 0이 소수, 1이 소수가 아닌것을 의미
        for (int i=2; i*i<=264912; i++) { 
            if (array[i] == 0) {  
                for (int j=i*i; j<246912; j+=i) { //어떤 수의 배수인 부분은 소수가 아니므로 1로 값 변경
                    array[j] = 1;
                }
            }
        }
        int count=0;
        for (int i=n+1; i<=(2*n); i++) { //n+1부터 2n까지 배열에서 값이 0인 부분(소수) 찾기
            if (array[i] == 0) {
                count += 1; //몇 개인지만 알면 되니까 변수 count에 +1씩 하기
            }
        }
        printf("%d\n", count);
        count = 0;
    }
}
