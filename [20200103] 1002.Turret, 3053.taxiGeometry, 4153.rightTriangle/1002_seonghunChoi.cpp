#include <iostream>
#include <cmath>
using namespace std;
int main(){

    int n;                                                       //테스트 타입 갯수 
    int x[2];                                                    //x,y,r의 입력을 배열을 통해 받아 버림
    int y[2];
    int r[2];
    double D=0.0;                                                //D = 점과 점사이의 거리 
    int PR=0                                                     //Plus R = R 들의 덧셈 값
    int MR=0;                                                    //Minus R = R들의 뺄셈 값
   
    
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x[0] >> y[0] >> r[0] >> x[1] >> y[1] >> r[1];
        D = sqrt((x[1] - x[0]) * (x[1] - x[0]) + (y[1] - y[0]) * (y[1] - y[0]));
    
    PR = r[0] + r[1];                   
    MR = abs(r[0] - r[1]);                                        //abs == 절대값으로 만들어줌 단 double float는 cmath에 int는 cstdlib에 존재
        
    if(D == 0.0){                                                 //D = 0.0 서로 같은 점일경우 
    	if(r[0] == r[1])                                            //두개의 R의 길이가 같으면 똑같은 위치의 똑같은 크기의 원
    		cout << "-1" << endl;                                     
    	else                                                        //R의 크기가 다르면 똑같은 위치의 반지름이 다른 원
    		cout << "0" <<endl;                  
    }
    else{                                                         //D != 0.0 서로 다른 점일 경우
    	if(PR > D && MR < D)                                        //두 R의 합보다 D가 크고 두 R의 차이보다 D가 작으면 접점 두개
    		cout << "2" << endl;
    	else if(PR == D || MR == D)                                 //두 R의 합이 D와 같거나 두 R의 차이가 D와 같으면 접점 한개
    		cout <<"1" << endl;
    	else                                                        //나머지 경우에는 점접 0개 <여기가 가장 이해가 안되서 막혔음>
    		cout << "0" << endl;
    }
    }
}
