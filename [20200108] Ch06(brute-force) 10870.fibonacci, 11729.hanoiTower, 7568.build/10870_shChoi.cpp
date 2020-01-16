#include <iostream>
using namespace std;
int fib(int n)                                                  //피보나치 함수
	{
		if(n==0)                                         
			return 0;
		else if(n==1)                                      
			return 1;
		else 
			return(fib(n-1) + fib(n-2));                         //n = 0, n = 1일 때 까지 재귀적으로 함수 호출
	}
	
int main() {
    int n;
    cin >> n;
    cout << fib(n) << endl;
	
}
