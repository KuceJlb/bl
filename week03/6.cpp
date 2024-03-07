#include <iostream>
#include <cstdio>
using namespace std;
int const N = 10;
int arr[N] = {1,2,3,4,5,6,7,8,9,0};
int arr1[2*N] = {0};
void mergeArrays(int (&lhs)[N], int (&rhs)[N], int (&res)[2 * N]) {
    for (int i = 0; i < N; i++) {
        res[i] = lhs[i];
    }
    for (int i = 0; i < N; i++) {
        res[i+N] = rhs[i];
    }
}

void printArray(int (&arr)[2*N]) {
    for (int i = 0; i < 2 * N; i++) {
        cout << arr[i];
        if (i != 2* N) {
            cout << ' ';
        }
    }
    cout << endl;
}

int main() {
    mergeArrays(arr, arr, arr1);
    printArray(arr1);
    return 0;
}