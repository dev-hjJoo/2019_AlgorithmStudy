/*
 이 코드는 보글 게임의 문제를 푼 코드가 아닙니다. 보글 게임의 알고리즘을 코드로 옮겨놓은 것입니다~!
 작성자: 주효진
 작성일: 2020.01.07.화요일
 */

#include<iostream>
#include<string>
using namespace std;

// MARK: 전역변수 선언부
const int size = 5;
const char board[size][size]={
    'U', 'R', 'L', 'P', 'M',
    'X', 'P', 'R', 'E', 'T',
    'G', 'I', 'A', 'E', 'T',
    'X', 'T', 'N', 'Z', 'Y',
    'X', 'O', 'Q', 'R', 'S'
};
const int dx[8]={-1,-1,-1,1,1,1,0,0};
const int dy[8]={-1,0,1,-1,0,1,-1,1};

// MARK: inRange, 좌표가 범위 밖이면 false, 안이면 true를 반환.
bool inRange(int y, int x){
    if(y<size && x<size && y>=0 && x>=0) return true;
    else return false;
}
// MARK: hasWord, 5x5 보글 게임 판의 해당 위치(x, y)에서 주어진 단어가 시작하는 지를 반환
bool hasWord(int y, int x,const string& word){
//    cout << y << ", "<< x << endl;
//    cout << "board[y][x]: " << board[y][x] << ", word[0]: " << word[0] << endl;
    // 범위가 보드판을 벗어나면 실패
    if(!inRange(y,x)) return false;
    // 위치에 있는 글자가 원하는 단어의 첫 글자가 아닌 경우 실패
    if(board[y][x]!=word[0]) return false;
    // 원하는 단어가 한 글자인 경우 성공
    if(word.size()==1) return true;
    
    for(int direction=0; direction<8; direction++){
        int nextY=y+dy[direction];
        int nextX=x+dx[direction];
        // substr(pos, count), pos: 문자열을 가져올 시작 위치, count: 가져올 개수
        if(hasWord(nextY, nextX, word.substr(1))) return true;
    }
    return false;
}
// MARK: main()
int main()
{
    string searchStr;
    cout << "찾을 문자열을 입력하세요 : ";
    cin >> searchStr;
    
    // 첫 글자의 위치를 함수의 인자로 보내기 위하여 반복문 사용
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            if(hasWord(i, j, searchStr)) cout << "(" << i << ", " << j << ") 위치에 " << searchStr << "가 있습니다." << endl;
        }
    }
}
