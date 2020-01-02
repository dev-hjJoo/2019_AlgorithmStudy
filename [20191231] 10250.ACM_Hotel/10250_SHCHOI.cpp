#include <iostream>
using namespace std;
int main() {
    int T = 0;       //테스트 케이스
    int H;           //호텔 층 수
    int W;           //호텔 각 층 별 방 수
    int N;           //몇번째 손님인가?
    int data[T];     //데이터 값 저장
   
    //MARK: 여기서 생각한 알고리즘은 손님수 나누기 층수의 몫은 방번호를 의미하고 나머지는 층수를 의미한다는 것임
    cin >> T;
    
    for(int i = 0; i < T; i++){
        cin >> H >> W >> N;                                 //각 데이터 입력 받음
        if((N % H) > 0){                                    //나머지가 1이상 일때는 정상정으로 나옴
            data[i] = ((N / H) + 1) + (100 * (N % H));
        }
        else{
            data[i] = ((N / H)) + 100 * H;
        }
         cout << data[i] <<endl;
    }
    return 0;
}
