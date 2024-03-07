#include <iostream>
#include <cstdio>
using namespace std;
int const N = 3;
int arr[N] = {0, 1, 2};
int findLastZero(int (&array)[N]) {
    if (array[N-1] == 0) {
        return N-1;
    }
    int c = N/2;
    int k = 2;
    while ((array[c] != 0) or (array[c+1] != 1)) {
        k *= 2;
        if (array[c] == 0) {
            c += N/k+1;
        } else {
            c -= N/k+1;
        }
        cout << 'x';
    }
    return c;
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
    cout << findLastZero(arr) << endl;
    printArray(arr);
    return 0;
}