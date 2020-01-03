#include<stdio.h>
#include<math.h>
#define _USE_MATH_DEFINES
int main()
{
    int r;
    scanf("%d",&r);
    
    double S, St;
    S = r*r*M_PI;       // math.h 파일에서 PI값 가져오기
    St = 2*r*r;
    
    printf("%f\n%f\n",S,St);
    
}
