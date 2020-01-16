#include<iostream>
using namespace std;
int main()
{
    int n;                      // test case (입력받을 사람 수)
    int weight[51], height[51]; // 각각의 사람들의 체중과 키를 저장할 배열
    int rank[51]={0,};          // 사람들의 등수를 저장할 배열
    
    //MARK: 입력부
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> weight[i] >> height[i];
    }
    //MARK: 등수 연산
    for(int i=0; i<n; i++){
        rank[i]=1;              // 초기값 1, 본인보다 키와 몸무게 모두 높은 사람이 있으면 증가
        for(int j=0; j<n; j++){
            if(weight[i]<weight[j] && height[i]<height[j]) rank[i] += 1;
        }
    }
    for(int i=0; i<n; i++){
        cout << rank[i] << " ";
    }
}
