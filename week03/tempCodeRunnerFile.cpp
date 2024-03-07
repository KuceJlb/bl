#include <iostream>
#include <cstdio>
using namespace std;
int const N = 9;
int arr[N] = {0,0,5,1,2,0,0,1,2};
void printArray(int (&arr)[N]);


int fun(int (&a)[N]) {
    
    static int a0 = 0;
    static int b0 = N - 1;
    int c = 0;
    int g;
    if ((a0 != b0) and (a0 < b0)){
    for (int i = 0; i < b0 - a0; i++) {
        if ((a[a0] < a[a0 + 1 + i - c])) {
            g = a[a0 + 1 + i - c];
            a[a0 + 1 + i - c] = a[b0-c];
            a[b0-c] = g;
            c++;
        }
    }
    int f = 1;
    int j = 0;
    g = a[a0];
    a[a0] = a[b0-c];
    a[b0-c] = g;
    f = 0;
    g = b0;
    b0 = b0-1-c;
    fun(a);
    b0 = g;
    a0 = b0-c+1;
    fun(a);
    }
    for (int i = 0; i < N; i += 2) {
        if (a[i] != a[i+1]) {
            return a[i];
        }
    }
    return a[N-1];