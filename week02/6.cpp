#include <iostream>
#include <cstdio>
#include <math.h>

using namespace std;
int fact(int a) {
    if (a != 0) {
        return a*fact(a-1);
    } else {return 1;}
}
int main() {
    int a;
    cin >> a;
    cout << fact(a);
    return 0;
}