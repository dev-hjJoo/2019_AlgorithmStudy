#include <iostream>
using namespace std;

int First[100][100];
int Second[100][100];
int Data[100][100];

int main() {
	int N;
	int M;
	int K;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			cin >> First[i][j];
	}

	cin >> M >> K;

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < K; j++)
			cin >> Second[i][j];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K; j++) {
			for (int l = 0; l < M; l++) {
				Data[i][j] += (First[i][l] * Second[l][j]);
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K; j++) {
			cout << Data[i][j] << " ";
		}
		cout << endl;
	}
}
