#include <iostream>
#include <algorithm>
using namespace std;

int Data[50][50];                                 
string str;

int MIN = 0;                                                       //최솟값 비교를 위해 임시적으로 0으로 둠

int tmp = 1;                                                        //정사각형의 넓이 비교 대상이자 저장

int main() {
	int n;
	int m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {                               //띄어쓰기 없이 입력 받는다는 조건 때문에 string으로 받은 후 각각 짤라서 배열에 넣어주는 형태
		cin >> str;
		for (int j = 0; j < m; j++)
			Data[i][j] = str[j] - '0';
	}

	MIN = min(n, m);                                            //최솟값 만큼 정사각형의 최대 넓이가 만들어지기 때문에 최솟값을 찾는다

	for (int i = 0; i < n; i++) {                               //행을 확인하면서
		for (int j = 0; j < m; j++) {                       //각 열을 확인한다
			for (int k = 1; k < MIN; k++) {             //정사각형의 길이는 최솟값을 넘지 못하기 때문에 
				if ((i + k < n) && (j + k < m) && Data[i][j] == Data[i + k][j] 
				    && Data[i][j] == Data[i][j + k] && Data[i][j] == Data[i + k][j + k])

//행과 열이 범위를 넘어가지 않는 선에서 첫번째 기준 점과 같은 열에 같은 숫자가 있고 같은 행에도 같은 숫자가 있으며 대칭점 또한 같은 값이면 tmp에 대입
				
					tmp = max(tmp, (k + 1));
				
//tmp와 새로 대입대는 값과의 크기 비교로 크면 tmp에 큰 값을 다시 대입 (k+1인 이유는 첫번째 기준점을 포함해줘야 하기때문)
			}
		}
	}

	cout << (tmp * tmp) << endl;            //tmp 제곱이 넓이이고 따라서 출력해준다.
}
