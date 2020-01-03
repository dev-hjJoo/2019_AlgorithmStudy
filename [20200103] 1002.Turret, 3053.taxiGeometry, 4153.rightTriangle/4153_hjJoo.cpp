#include<stdio.h>
#include<deque>
#include<math.h>
using namespace std;
int main()
{
    int i, n;
    deque<int> sides;
    
    while(1){
        for(i=0;i<3;i++){
            scanf("%d",&n);
            if(sides.empty()) sides.push_back(n);
            else{
                // 가장 큰 값이 앞에 삽입
                if(sides.front()>n) sides.push_back(n);
                else sides.push_front(n);
            }
        }
        if(n==0) break;     // 입력은 양의 정수이므로 0이 나오면 마지막 줄 테스트 케이스.
        if(pow(sides[0], 2)==pow(sides[1], 2)+pow(sides[2], 2)) printf("right\n");
        else printf("wrong\n");
        sides.clear();
    }
}
