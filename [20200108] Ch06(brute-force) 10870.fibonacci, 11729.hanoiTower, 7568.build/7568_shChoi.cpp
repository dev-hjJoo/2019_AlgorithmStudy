#include <iostream>
using namespace std;
int main(){
	int n = 0;
	cin >> n;
	int name[n][2];
	int count = 1;
	for (int i = 0; i < n; i++){
		cin >> name[i][0];                        //몸무게 입력 받기
		cin >> name[i][1];                        //키 입력 받기
	}
	for (int j = 0; j < n; j++){
		for(int k =0; k < n; k++){
			if(name[j][0] < name[k][0] && name[j][1] < name[k][1]){          //몸무게와 키 모두 크면 카운트를 통해 등수를 센다
				count++;
			}
		} 
		cout << count <<" ";                                               //등수를 출력하고 count를 다시 1로 초기화 시켜준다
		count = 1;
	}
}
