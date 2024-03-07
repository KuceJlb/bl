#include <iostream>
#include <cstdio>

using namespace std;


int alg_num(int n, int m, int i) {
    if (n < m) {
        int z;
        z = n;
        n = m;
        m = z;
    }
    int l;
    l = n % m;
    n = m;
    m = l;
    if (m == 0) {
        return i;
    }
    else {
        return alg_num(n, m, i+1);
    }
}

int alg_nod(int n, int m) {
    if (n < m) {
        int z;
        z = n;
        n = m;
        m = z;
    }
    int l;
    l = n % m;
    n = m;
    m = l;
    if (m == 0) {
        return n;
    }
    else {
        return alg_nod(n, m);
    }
}

int poisk_x(int n, int m, int i){
    int f;
    f = 0;
    if (n < m) {
        int z;
        z = n;
        n = m;
        m = z;
        f = 1;
    }
    int l;
    int q;
    l = n % m;
    q = n / m;
    n = m;
    m = l;
    if (i > 1) { 
        return (poisk_x(n, m, i-2) - q*poisk_x(n, m, i-1));
    }
    else {
        if (i==1){
            return -n / m;
        }
        else {
            if (i==0){
                return 1;
            }
            else { 
                if (f) {
                    return 1;
                }
                else {
                    return 0;
                }
            }
        }
    }
}

int poisk_y(int n, int m, int i){
    int f;
    f = 1;
    if (n < m) {
        int z;
        z = n;
        n = m;
        m = z;
        f = 0;
    }
    int l;
    int q;
    l = n % m;
    q = n / m;
    n = m;
    m = l;
    if (i > 1) { 
        return (poisk_y(n, m, i-2) - q*poisk_y(n, m, i-1));
    }
    else {
        if (i==1){
            return 1+q*(n/m);
        }
        else {
            if (i==0){
                return -q;
            }
            else { 
                if (f) {
                    return 1;
                }
                else {
                    return 0;
                }
            }
        }
    }
}

void solve(int a, int b, int c, int& x, int& y) {
    int k;
    int nod;
    k = alg_num(abs(a), abs(b), 0)-1;
    x = poisk_x(abs(a), abs(b), k);
    y = poisk_y(abs(a), abs(b), k);
    nod = alg_nod(abs(a), abs(b));
    if ((abs(a) < abs(b)) and k >= 0) {
        int w;
        w = x;
        x = y;
        y = w;
    }
    if (c % nod == 0) {
        x *= (c / nod);
        y *= (c / nod);
        if (a < 0){
            x *= -1;
        }
        if (b < 0){
            y *= -1;
        }
    }
    else {
        x = 0;
        y = 0;
    }
}

int main() {
    int a1;
    int a2;
    int a3;
    int x;
    int y;
    cin >> a1 >> a2 >> a3;
    x = 0;
    y = 0;
    solve(a1, a2, a3, x, y);
    cout << x << endl << y;
    return 0;
}