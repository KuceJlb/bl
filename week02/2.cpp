#include <iostream>
#include <cstdio>
#include <math.h>

using namespace std;

int enter(int i) {
    int a;
    int ii;
    ii = i;
    cin >> a;
    if (a != 0) {
        if (a % 2 == 0) {
            ii++;
        }
        return(enter(ii));
    } else {
        return ii;
    }
    
}

int main() {
    int c;
    c = 0;
    cout << enter(c);
    return 0;
}