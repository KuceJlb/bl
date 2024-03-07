#include <iostream>
#include <cstdio>
#include <math.h>

using namespace std;

int rec_fib(int a) {
    if (a == 0 or a == 1){
        return 1;
    }
    if (a < 0) {
        return -1;
    }
    return rec_fib(a - 1) + rec_fib(a - 1);
}

int main() {
    cout << rec_fib(10) << endl;
    return 0;
}