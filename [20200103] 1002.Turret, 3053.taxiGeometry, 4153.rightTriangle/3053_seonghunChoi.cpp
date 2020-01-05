#include<iostream>
#define PI 3.141592653589793238462643383279502;                 //PI 파이 값 지정
using namespace std;
int main(){
    double R;                                                   //float와 double의 차이를 몰라서 계속 틀렸다. double이 더 정확한 것
    double Ucir;
    double Tcir;
    cin >> R;
    Ucir = R * R * PI;                                          //유클리드 기하의 공식
    Tcir = R * R * 2;                                           //택시 기하의 공식
    cout << fixed;                                              //소수점을 고정 시키겠다 라는 의미
    cout.precision(6);                                          //소수점 6번째 자리 까지 출력
    cout << Ucir << endl;
    cout << Tcir << endl;
}
