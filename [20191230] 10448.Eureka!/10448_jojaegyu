#include <stdio.h>
#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <cstdlib>
#include <queue>


using namespace std;


vector <int> v;
vector <int> answers;

int main() {
	bool end = false;
	int N, T;
	cin >> T;



	int i = 1;
	v.push_back(1);
	while (i * (i + 1) / 2 < 1000) {
		i++;
		v.push_back(i * (i + 1) / 2);
	}
	v.pop_back();

	for (int i = 0; i < T; i++) {
		end = false;
		cin >> N;
		for (int i = 0; i < v.size(); i++) {
			for (int k = 0; k < v.size(); k++) {
				for (int q = 0; q < v.size(); q++) {
					if (N == v[i] + v[k] + v[q]) {
						cout << 1 << "\n";
						end = true;
						break;
					}
				}
				if (end) {
					break;
				}
			}
			if (end) {
				break;
			}
		}
		if (!end) {
			cout << 0 << "\n";
		}

	}
}
