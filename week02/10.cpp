#include <iostream>
#include <cstdio>

using namespace std;

int perevod(unsigned long long int a, int b) {
    if (a/b > 0) {
        perevod(a/b, b);
        cout << (a % b);
    }
    else {if (a != 0) {
        cout << a;
    }
    }
    return 0;
}

int main() {
    unsigned long long int n;
    int s;
    cin >> n >> s;
    if (n!=0) {
        perevod(n,s);
    } else {
        cout << 0;
    }
    return 0;
}