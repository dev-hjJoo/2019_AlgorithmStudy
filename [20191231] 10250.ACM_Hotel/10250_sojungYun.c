#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    int n=0; //입력 횟수
    int H=0, W=0, N=0; //층수, 방수, 손님수
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%d %d %d", &H, &W, &N);
        
        for (int j=1; j<=W; j++) { //방수
            
            for (int k=1; k<=H; k++) { //층수
                N -= 1;
                if (N==0) { //손님수가 0이 되면 출력 후 break
                    printf("%d \n", k*100 + j);
                    break;
            }
            }
            if (N==0) {
                break;
            }
        }
    }
}
