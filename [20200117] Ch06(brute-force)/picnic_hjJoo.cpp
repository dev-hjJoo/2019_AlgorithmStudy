 #include<iostream>
#include<vector>
using namespace std;
//MARK: 전역 변수 선언부
int numberOfStudents;    // 총 사람 수
bool areFriends[10][10]; // 두 사람이 친구인지 여부를 저장하는 배열

// MARK: countPairs() // 쌍을 세고 그 수를 반환해주는 함수
int countPairs(bool taken[10]){
    // 남은 학생들 중 가장 번호가 빠른 학생 찾기
    int firstFree = -1;
    for(int i=0; i<numberOfStudents; i++) {
        if(!taken[i]) { firstFree=i; break; }
    }
    // 기저 사례: 모든 학생이 짝을 찾았다면 하나의 경우의 수 증가(1 반환)
    // -> firstFree가 -1이라는 것은 taken[]의 배열 값이 모두 true -> 짝지어지지 않은 사람이 없음을 의미.
    if(firstFree == -1) return 1;
    // ret: 짝지을 수 있는 모든 경우의 수
    int ret=0;
    // firstFree 학생과 짝지을 학생을 결정
    for(int pairWith=firstFree+1; pairWith<numberOfStudents; pairWith++) {
        // !taken[pairWith]: pairWith가 짝이 없음
        // areFriends[firstFree][pairWith]: firstFree와 pairWith가 친구임
        // 위의 두 조건이 모두 참이면 조건문 아래 코드 실행
        if(!taken[pairWith] && areFriends[firstFree][pairWith]) {
            // 둘은 짝을 찾았음을 표현
            taken[firstFree] = taken[pairWith] = true;
            // 남은 사람들 마저 짝 짓기
            ret += countPairs(taken);
            // 재귀함수에서 다음 단계를 찾으므로, 위의 경우 외의 다른 경우 또한 찾아보기 위해 false로 다시 바꿔주기
            taken[firstFree] = taken[pairWith] = false;
        }
    }
    return ret;
}

// MARK: main()
int main()
{
    int testCase;           // 테스트 케이스 수
    int numberOfPairs;      // 친구 짝 수
    int fir, sec;           // 친구인 멤버 1, 2
    bool taken[10]={0,};    // !초기화 필수! 초기값이 멋대로 들어있음. (0: false)
    cin >> testCase;
    for(int i=0; i<testCase; i++){
        cin >> numberOfStudents >> numberOfPairs;
        // areFriends 배열 초기화
        for(int x=0; x<numberOfStudents; x++){
            for(int y=0; y<numberOfStudents; y++){
                areFriends[x][y]=false;
            }
        }
        // 친구 여부 입력
        for(int j=0; j<numberOfPairs; j++){
            // 친구인 학생들 쌍 입력
            cin >> fir >> sec;
            areFriends[fir][sec]=true;
            areFriends[sec][fir]=true;
        }
        // 연산 결과 출력
        cout << countPairs(taken) << endl;
    }
    
}
