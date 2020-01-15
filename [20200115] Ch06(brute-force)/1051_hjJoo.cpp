#include<iostream>
#include<string.h>
using namespace std;
// MARK: 전역변수 선언부
int n, m;
string board[50];
const int dx[4]={0, 1, 1, 0};
const int dy[4]={0, 0, 1, 1};
int findMaxArea(int stX, int stY, int length){
    char origin=board[stY][stX];
    for(int i=1; i<4; i++){
        if(origin != board[stY+(dy[i]*length)][stX+(dx[i]*length)]) {
            return 1;
        }
    }
    length++;
    return length*length;
}
// MARK: 메인 함수
int main()
{
    cin >> n >> m ;
    for(int i=0; i<n; i++){
        cin >> board[i];
    }
    
    int maxLength = n<m?n:m;        // 정사각형으로 만들 수 있는 가장 긴 변 = 직사각형의 짧은 변
    int maxArea=1;                  // 정사각형으로 만들어지는 것이 없는 경우 1
    int result;
    for(int length=1; length<maxLength; length++){ // 크기가 1인 경우는 볼 필요 없으므로 생략
        for(int y=0; y<n-length; y++){
            for(int x=0; x<m-length; x++){
                result = findMaxArea(x, y, length);
                maxArea = maxArea<result ? result:maxArea;
            }
        }
    }
    cout << maxArea << endl;
}
