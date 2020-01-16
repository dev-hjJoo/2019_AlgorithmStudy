#include <stdio.h>

struct size {
    int weight;
    int height;
};

int main(int argc, const char * argv[]) {
    int N;
    int count = 0;
    scanf("%d",&N);
    
    struct size arr[N];
    for(int i=0; i<N; i++){
        scanf("%d %d",&arr[i].weight,&arr[i].height);
    }
    //구조체 배열에 각각의 몸무게와 키를 입력
    for(int i=0; i<N; i++){
        for(int k=0; k<N; k++){
            if(arr[i].weight < arr[k].weight && arr[i].height < arr[k].height){
                count += 1;
            }
        }
        //자신보다 덩치가 크면 count 를 1 증가시킴
        printf("%d ",count + 1);//자신보다 덩치가 큰 명수만큼 등수가 밀리게 됨
        count = 0;
    }
    
}
