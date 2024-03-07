#include <iostream>
#include <cstdio>
#include <math.h>
int n;
using namespace std;
int f(int a, int b){
    if (b != 0){
        return f(a * n, b-1);
    } else {return a;}
}
int main() {
    long long int r;
    r=1;
    int m;
    cin >> n >> m;
    cout << f(r, m);
    return 0;
}