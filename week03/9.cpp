#include <iostream>
#include <cstdio>
using namespace std;
int const N = 3;
int const M = 2;



int arr[N][M] = {{0,1},{2,3},{4,5}};
void printTransposed(int (&array)[N][M]) {
    for (int j = 0; j < M; j++){
    for (int i = 0; i < N; i++) {
        cout << arr[i][j];
        if (i != N) {
            cout << ' ';
        }
    }
    cout << endl;
    }
    cout << endl;
}
int main() {
    printTransposed(arr);
    return 0;
}
