#include <stdio.h>

int main(int argc, const char * argv[]) {
    int n=0;
    int num=0;
    int p=0;
    scanf("%d", &num);
    while (p<num) {
        scanf("%d", &n);
        
        int array[10000] = {0, }; //배열을 0으로 초기화하고 0이 소수, 1이 소수가 아닌것을 의미 -eratosthenes
        for (int i=2; i*i<=10000; i++) { //배열에 0과 1로 소수인 것과 소수가 아닌 것을 표시(0이 소수)
            if (array[i] == 0) {
                for (int j=i*i; j<10000; j+=i) {
                    array[j] = 1;
                }
            }
        }
        
        for (int a =(n/2), b = (n/2); a>1; a--, b++) { //두 수의 차가 가장 작아야 하므로 입력받은 n의 값의 반 지점에서 시작
            if (array[a]==0 && array[b]==0) { //변수 a는 1씩 감소하고 변수 b는 1씩 증가하며 배열이 둘 다 0인 것을 찾음
                printf("%d %d\n", a, b);
                break;
            }
        }
        p++;
    }
}
