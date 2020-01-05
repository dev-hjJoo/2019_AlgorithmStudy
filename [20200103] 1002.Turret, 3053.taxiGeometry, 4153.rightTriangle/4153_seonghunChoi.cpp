#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int data[3] = {0, 0, 0};
    int tmp = 0;

    for(int i = 0; i < 30000; i++){
        for(int j = 0; j < 3; j++){
            cin >> data[j];
            if(data[j] > tmp)
                tmp = data[j];                                            //tmp에 가장 큰 배열의 값을 넣어주는 것
        }
        if(data[0] == 0 && data[1] == 0 && data[2] == 0) break;
        
        if(2 * tmp * tmp == (data[0] * data[0]) + (data[1] * data[1]) + (data[2] * data[2]))    //ex 5, 4, 3일 때 2*5^2 = 5^2 + 4^2 + 3^2 
            cout << "right" << endl;
        else
            cout << "wrong" << endl;
        tmp = 0;
    }
    
}
