//임시적으로 알고리즘을 구현한 코드 입니다. 
#include <iostream>
using namespace std;                                                                //질문1 : 여기에 #include <string>을 해주는 이유는 무엇인가?

const int n = 1;
const int SIZE = 5;
const char board[SIZE][SIZE] = {
	'U' , 'R' , 'L' , 'P' , 'M',
	'X' , 'P' , 'R' , 'E' , 'T',
	'G' , 'I' , 'A' , 'E' , 'T',
	'X' , 'T' , 'N' , 'Z' , 'Y',
	'X' , 'O' , 'Q' , 'R' , 'S'
};

const int dx[8] = { -1 , -1 , -1 , 1 , 1 , 1 , 0 , 0 };                             //상 하 좌 우로 이동하게 해주는 좌표
const int dy[8] = { -1 , 0 , 1 , -1 , 0 , 1 , -1 , 1 }; 

bool inRange(int y, int x) {                                                        //범위 내에 있는지 확인하는 과정
	if (y < SIZE && x < SIZE && y >= 0 && x >= 0)
		return true;
	else
		return false;
}

bool hash_word(int y, int x, const string& word){                                   //(y,x)는 시작 지점 지정해주는 것 
	if (!inRange(y , x))                                                              //범위 내에 없으면 false 출력  
		return false;
	if (board[y][x] != word[0])                                                       //시작 부분과 주어진 점이 다르면 false 출력
		return false;
	if (word.size() == 1)                                                             //한 글자일 경우 true 출력
		return true;
	for (int direction = 0; direction < 8; ++direction) {                             //x y의 좌표를 이동해주면서 단어와 일치하는지 확인
		int nextY = y + dy[direction];
		int nextX = x + dx[direction];
		if(hash_word(nextY, nextX, &word[n])) 
			return true;
	}
	return false;
}

int main() {
	cout << "찾고자 하는 단어를 입력하시오: ";
	string word;
	cin >> word;
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (hash_word(j, i, word))
				cout << "(" << j << ", " << i << ") 위치에 " << word << "가 있습니다." << endl;     
		}
	}
}
