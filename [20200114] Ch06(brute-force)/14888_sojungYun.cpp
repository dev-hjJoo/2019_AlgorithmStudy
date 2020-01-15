#include <iostream>
#include <algorithm>
using namespace std;
int n=0;
int num[11];
int op[4];
int maxN = -987654321;
int minN = 987654321;

void rec(int plus, int minu, int mul, int div, int count, int sum){ //재귀함수 이용하여 반복

    if (count==n) { //count가 입력한 수가 되면 최댓값과 최솟값 찾기
        
        maxN = max(maxN, sum);
        minN = min(minN, sum);
        return;
    }
    if (plus>0) { 
        rec(plus-1, minu, mul, div, count+1, sum + num[count]);
    }
    if (minu>0) {
        rec(plus, minu-1, mul, div, count+1, sum - num[count]);
    }
    if (mul>0) {
        rec(plus, minu, mul-1, div, count+1, sum * num[count]);
    }
    if (div>0) {
        rec(plus, minu, mul, div-1, count+1, sum / num[count]);
    }
}
int main(int argc, const char * argv[]) {
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> num[i];
    }
    for (int i=0; i<4; i++) {
        cin >> op[i];
    }
    rec(op[0], op[1], op[2], op[3], 1, num[0]); //처음 입력받은 값으로 함수 
    cout << maxN << endl;  //최대, 최소 출력
    cout << minN << endl;
    return 0;
         }
