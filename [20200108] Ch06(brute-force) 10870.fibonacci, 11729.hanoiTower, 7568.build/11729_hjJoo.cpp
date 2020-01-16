#include<stdio.h>
// MARK: n개의 원판이 주어질 때 이동 횟수를 세는 함수
int countHanoiTower(int n){
    // 원판이 한 개인 경우 이동횟수는 무조건 1회이므로 기저 사례로 빼준다.
    if(n==1) return 1;
    // 그 외에는 n-1개를 다른 기둥에 옮겨두고 가장 아래 원판을 옮기려는 기둥에 옮겨야 한다.
    // 이후 다른 기둥에 옮겨둔 원판들을 옮기고자 하는 기둥에 옮기므로 아래와 같은 코드가 된다.
    return countHanoiTower(n-1)+1+countHanoiTower(n-1);
}
// MARK: n개의 원판이 주어질 때 이동 위치를 출력하는 함수
void printMovementOfHanoi(int n, int origin, int temp, int destination){
    // 원판이 한 개인 경우 출발지(origin)에서 목적지(destination)으로 옮겼단 상태를 출력해준다.
    if(n==1) {
        printf("%d %d\n",origin, destination);
        return;
    }
    // 그 외에는 n-1개의 원판을 옮기고자 하는 기둥이 아닌 빈 기둥에 옮겨둔다.
    printMovementOfHanoi(n-1, origin, destination, temp);
    // 가장 아래의 원판을 옮기고자 하는 기둥에 옮겨준다.
    printMovementOfHanoi(1, origin, temp, destination);
    // 빈 기둥에 옮겨둔 원판들을 목적지로 다시 옮겨준다.
    printMovementOfHanoi(n-1, temp, origin, destination);
}
int main()
{
    int k;
    scanf("%d",&k);
    printf("%d\n",countHanoiTower(k));
    printMovementOfHanoi(k, 1, 2, 3);
}
