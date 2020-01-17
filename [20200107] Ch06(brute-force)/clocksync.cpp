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

int minimum = 987654321;
vector<int> clock_arr;
vector<vector<int>> button({
    vector<int>({ 0, 1, 2 }),
    vector<int>({ 3, 7, 9, 11 }),
    vector<int>({ 4, 10, 14, 15 }),
    vector<int>({ 0, 4, 5, 6, 7 }),
    vector<int>({ 6, 7, 8, 10, 12 }),
    vector<int>({ 0, 2, 14, 15 }),
    vector<int>({ 3, 14, 15 }),
    vector<int>({ 4, 5, 7, 14, 15 }),
    vector<int>({ 1, 2, 3, 4, 5 }),
    vector<int>({ 3, 4, 5, 9, 13 })
    });



void button_event(int button_num) {
    for (int i = 0; i < button[button_num].size(); i++) {
        if (clock_arr[button[button_num][i]] == 12) {
            clock_arr[button[button_num][i]] = 3;
        }
        else {
            clock_arr[button[button_num][i]] += 3;
        }
    }
    //clcok_arr[button[button_num]] 은 해당 버튼의 바꿔야하는 시계들의 배열
}
void button_recover(int button_num) {
    for (int i = 0; i < button[button_num].size(); i++) {
        if (clock_arr[button[button_num][i]] == 3) {
            clock_arr[button[button_num][i]] = 12;
        }
        else {
            clock_arr[button[button_num][i]] -= 3;
        }
    }
}

bool clock_check() {
    int count = 0;
    for (int i = 0; i < 16; i++) {
        if (clock_arr[i] == 12) {
            count++;
        }
    }
    if (count == clock_arr.size()) {
        return 1;
    }
    return 0;
}

int clock(int count,int button_num) {
    if (button_num == 10) {
        if (clock_check()) {
            if (minimum > count) {
                minimum = count;
            }
        }
        return 0;
    }
    
    clock(count, button_num + 1);
    for (int i = 1; i < 4; i++) {
        button_event(button_num);
        clock(count + i, button_num + 1);
    }
    button_event(button_num);
}

int main() {
    int num;
    for (int i = 0; i < 16; i++) {
        cin >> num;
        clock_arr.push_back(num);
    }
    clock(0, 0);
    cout << minimum;
}
