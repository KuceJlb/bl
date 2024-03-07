#include <iostream>
#include <cstdio>
#include <math.h>

using namespace std;
int fib(int n) {
    if (n==1 or n==0){
        return 1;
    } else {
        return fib(n-1)+fib(n-2);
    }
}
int main() {
    int a;
    cin >> a;
    cout << fib(a);
}