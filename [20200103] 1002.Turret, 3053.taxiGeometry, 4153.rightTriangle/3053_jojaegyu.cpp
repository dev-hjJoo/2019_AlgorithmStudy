#include <stdio.h>
#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <cstdlib>
#include <queue>
#include <algorithm>
#include <cmath>

#define pi 3.141592653589793238;
using namespace std;


int main(){
	double R,u,t;
	cin >> R;
	cout << fixed;
	cout.precision(6);
	u = R * R * pi;
	t = R * R * 2;
	cout << u << "\n" << t;
}

