#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
const int MAX = 50;
int arr[MAX][MAX];
int M, N;
int square = 1;

int squareSize(void){
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            for (int k=1; k<min(N, M); k++) { //기준인 arr[0][0]에서 더하는 용이므로 N과 M 중 작은 수 전까지만 반복(1부터 시작)
                if (i+k<N && j+k<M && arr[i][j] == arr[i+k][j] && arr[i][j] == arr[i][j+k] && arr[i][j] == arr[i+k][j+k] ) 
                                   //범위안에 있거나 각모서리의 수가 같을 때
                {
                    square = max(square, k+1); //square의 값은 원래result와 막 구한 k+1 중 큰 수
                }
            }
        }
    }
    return square * square; //최대 정사각형 크기
}

int main(int argc, const char * argv[]) {
    // insert code here...
    string str;
    cin >> N >> M ;
    for (int i=0; i<N; i++) {  //2차원 배열 사용하여 수 직사각형 입력받기
        cin >> str;            //공백으로 구분하지 않으려면 문자열로 한줄을 입력받음
        for (int j=0; j<M; j++) {
            arr[i][j] = str[j] - '0'; //그 한줄을 배열에 나눠서 넣어줌
        }
    }
    cout << squareSize() << endl; //함수호출
}
