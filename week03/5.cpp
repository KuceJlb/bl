#include <iostream>
#include <cstdio>
using namespace std;
int const N = 10;
int arr[N] = {1,-2,3,4,-5,-6,7,-8,9,0};
void printArray(int (&arr)[N]);

void shiftArrayRight(int (&arr)[]) {
    int c = arr[N-1];
    for (int i = 0; i < N - 1; i++) {
        arr[N-1-i] = arr[N-1-i-1];
    }
    arr[0] = c;
}

void moveNegativeToEnd(int (&array)[]) {
    int k = 0;
    for (int i = N - 1; i > -1; i--) {
        if (array[i] < 0) {
            int c = array[i];
            for (int j = i; j < N - 1 - k; j++) {
                array[j] = array[j+1];
            }
            array[N - 1 - k] = c;
            k++;
        }
    }
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
    moveNegativeToEnd(arr);
    printArray(arr);
    return 0;
}