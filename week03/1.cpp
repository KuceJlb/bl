#include <iostream>
#include <cstdio>
using namespace std;
int const N = 10;
int arr[N] = {0};
void readArray(int (&arr)[N]) {
    for (int i = 0; i < N; i++) {
        cin >> arr[i] ;
    }
}

int main() {
    readArray(arr);
    for (int i = 0; i < N; i++) {
        cout << arr[i];
    }
    return 0;
}