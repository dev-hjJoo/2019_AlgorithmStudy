#include <stdio.h>
#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <cstdlib>
#include <queue>
#include <algorithm>
#include <cmath>


using namespace std;


int main(){
	int a, b, c;
	while (1) {
		cin >> a >> b >> c;
		if (a == 0 && b == 0 && c == 0) {
			break;
		}

		if (max(a, c) == a) {
			swap(a, c);
		}
		else if (max(b, c) == b) {
			swap(b, c);
		}


		if (sqrt((a * a) + (b * b)) == c) {
			cout << "right" << "\n";
		}
		else {
			cout << "wrong" << "\n";
		}
	}
}
