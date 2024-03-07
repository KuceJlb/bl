#include <iostream>
#include <cstdio>
using namespace std;
int const N = 9;
int arr[N] = {5,1,2,1,2};
void printArray(int (&arr)[N]);
void fun(int (&a)[N], int a0, int b0);
int find_unique(int (&a)[N]){
    fun(a, 0, N-1);
    for (int i = 0; i < N; i += 2) {
        if (a[i] != a[i+1]) {
            return a[i];
        }
    }
    return a[N-1];
}
int a0 = 0;
int b0 = N - 1;
int fun(int (&a)[N]) {
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
    int l;
    l = fun(a);
    b0 = g;
    a0 = b0-c+1;
    l = fun(a);
    }
    for (int i = 0; i < N; i += 2) {
        if (a[i] != a[i+1]) {
            return a[i];
        }
    }
    return a[N-1];
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
    cout << fun(arr);
    return 0;
}