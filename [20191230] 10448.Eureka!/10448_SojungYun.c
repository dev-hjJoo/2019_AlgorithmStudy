#include <stdio.h>

int main(int argc, const char * argv[]) {
    int t[44];
    int n=1;
    int k=0, num=0,count=0;
    scanf("%d", &num);
    
    for (int a=0; a<44; a++) { //배열에 삼각수 저장
        t[a] = n*(n+1)/2;
        n++;
    }
    
    for (int p=0; p<num; p++) {
        count = 0;
    
        scanf("%d", &k);
        for (int i=0; i<44; i++) {
            for (int u=0; u<44; u++) {
                for (int j=0; j<44; j++) { //삼각수 값 찾는 삼중for문
                    if (k == t[i]+t[u]+t[j]) { //입력값과 같으면 1출력하고 break
                        printf("%d\n", 1);
                        count=1;
                        break;
                    }
                }
                if (count == 1) {
                    break;
                }
            }
            if (count == 1) {
                break;
            }
        }
        if (count == 0) { //입력값과 같은 값이 없으면 0출력
            printf("%d\n", 0);
        }
    }
}
