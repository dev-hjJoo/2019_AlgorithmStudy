#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    int a=0, b=0, c=0;
    while (1) {
        cin >> a >> b >> c;
        if (a==0 && b==0 && c==0) { //변수 세 개가 모두 0이 입력되면 종료
            break;
        }

        if (b*b + c*c == a*a || a*a + c*c == b*b || a*a + b*b == c*c) { //가장 긴 변의 길이 제곱이 나머지 두 변의 제곱의 합과 같으면 직각삼각형
            cout << "right" << "\n";
        }
        else
            cout << "wrong" << "\n";
    }
}
