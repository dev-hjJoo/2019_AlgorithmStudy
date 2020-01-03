#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, const char * argv[]) {
    int n=0;
    cin >> n;
    int i=0;
    int x1=0, y1=0, r1=0, x2=0, y2=0, r2=0;
    while (i<n) { //두 좌표와 거리가 있으므로 원으로 생각하면됨
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        double d = sqrt((y2-y1)*(y2-y1) + (x2-x1)*(x2-x1)) ; //두 좌표의 거리
        if (x1 == x2 && y1==y2 && r1 == r2) { //두 좌표와 두 거리가 모두 같으면 위치 개수는 무한대
            cout << -1 << "\n";
        }
        else if (r1>r2) {
            if (r1-r2 < d && d < r1+r2 ) { //두점에서 만난다
                cout << 2 << "\n";
            }
            else if (r1+r2 == d || r1-r2 == d) //한 점에서 내접 또는 외접
                cout << 1 << "\n";
            else if (d > r1+r2 || d < r1-r2) // 작은 원이 큰 원 안에 있거나 원이 외접하지 않음
                cout << 0 << "\n";
        }
        else { //r2>r1
            if ((r2-r1) < d && d< (r1+r2) ) { //두점에서 만난다
                cout << 2 << "\n";
            }
            else if ((r1+r2) == d || (r2-r1) == d) //한 점에서 내접 또는 외접
                cout << 1 << "\n";
            else if (d > (r1+r2) || d < (r2-r1) )// 작은 원이 큰 원 안에 있거나 원이 외접하지 않음
                cout << 0 << "\n";
        }
        i++;
    }
}
