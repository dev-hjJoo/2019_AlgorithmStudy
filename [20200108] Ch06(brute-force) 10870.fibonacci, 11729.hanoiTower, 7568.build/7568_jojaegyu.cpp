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
    for(int i=0; i<N; i++){
        for(int k=0; k<N; k++){
            if(arr[i].weight < arr[k].weight && arr[i].height < arr[k].height){
                count += 1;
            }
        }
        printf("%d ",count + 1);
        count = 0;
    }
}
