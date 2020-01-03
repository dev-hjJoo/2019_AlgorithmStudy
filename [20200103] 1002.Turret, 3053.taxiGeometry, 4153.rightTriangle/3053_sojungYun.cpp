#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    double r=0;
    cin >> r;
    cout << fixed;
    cout.precision(6); //소수점 6번째짜리까지 출력
    cout << r*r*3.14159265359 << "\n";
    cout << 2.0*r*r << "\n"; //택시 기하학에서 원의 넓이
}
