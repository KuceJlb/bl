#include <iostream>
#include <cstdio>
using namespace std;
int const N = 10;
int arr[N] = {0};
int trace(int (&array)[N * N]) {
    int c = 0;
    for (int i = 0; i < N; i++) {
        c += array[i+N*(i-1)];
    }
    return c;
}

int main() {
    
}