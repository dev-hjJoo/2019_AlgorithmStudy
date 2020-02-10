#include <iostream>
using namespace std;
int Map[128][128] = { 0 , };
int N = 0;
int Count_Zero = 0;
int Count_One = 0;

void Div_Map(int startXP, int startYP, int endXP, int endYP) {

	int check = Map[startXP][startYP];

	for (int i = startXP; i < endXP; i++) {
		for (int j = startYP; j < endYP; j++) {
			if (check == 0 && Map[i][j] == 1)
				check = 2;
			else if (check == 1 && Map[i][j] == 0)
				check = 2;
			if (check == 2) {
				Div_Map(startXP, startYP, ((startXP + endXP) / 2), ((startYP + endYP) / 2));
				Div_Map(((startXP + endXP) / 2), ((startYP + endYP) / 2), endXP, endYP);
				Div_Map(startXP, ((startYP + endYP) / 2), ((startXP + endXP) / 2), endYP);
				Div_Map(((startXP + endXP) / 2), startYP, endXP, ((startYP + endYP) / 2));
				return;
			}
		}
	}

	if (check == 0) 
		++Count_Zero;

	else if (check == 1) 
		++Count_One;

	return;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cin >> Map[i][j];
	}

	Div_Map(0, 0, N, N);
	
	cout << Count_Zero << endl;
	cout << Count_One << endl;
	
	return 0;
}
