#include <iostream>
#include <cstdio>
#include <math.h>

using namespace std;

int main() {
    int a = 0;
    cin >> a;
    if (a % 400 == 0) {
        cout << "YES";
    } else {
        if (a % 100 == 0) {
            cout << "NO";
        } else {
            if (a % 4 == 0) {
                cout << "YES";
            } else {
                cout << "NO";
            }
        }
    }
    return 0;
}