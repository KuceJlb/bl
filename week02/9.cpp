#include <iostream>
#include <cstdio>

using namespace std;

int log(int a) {
    int s;
    int c;
    s = 1;
    c = 0;
    while (s <= a) {
        s *= 2;
        c++;
    }
    return c-1;
}
int main() {
    int n;
    cin >> n;
    int q;
    for (int i=0; i<n; i++) {
        cin >>q;
        cout << log(q) << endl;
    }
    return 0; 
}