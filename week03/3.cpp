#include <iostream>
#include <cstdio>
using namespace std;
int const N = 10;
int arr[N] = {1,2,3,4,5,6,7,8,9,0};
void void shiftArrayRight(int (&arr)[N]) {
    int c = arr[N-1];
    for (int i = 1; i < N; i++) {
        arr[N-1-i] = arr[N-1-i+1]
    }
    arr[0] = c
}

void printArray(int (&arr)[N]) {
    for (int i = 0; i < N; i++) {
        cout << arr[i];
        if (i != N) {
            cout << ' ';
        }
    }
    cout << endl;
}

int main() {
    reverseArray(arr);
    printArray(arr);
    return 0;
}