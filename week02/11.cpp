#include <iostream>
#include <cstdio>

using namespace std;
long long int n;
int zet;
int por(long long, int, int);
int f(long long int a, int b, int c){
    if (b > zet){
        return f(a % c, b % zet, c);
    }
    if (b != 0){
        return f((a * n) % c, b-1, c);
    } else {return a;}
}
int g(long long int a, int b, int c){
    if (b !=0) {
        return f(1, g(a, b-1, c), c) % c;
    } else {return a % c;}
}
int por(long long n, int o, int p){
    int i;
    i = 0;
    long long n1;
    n1 = 1;
    while (i < p){
        n1 *= n % o;
        i++;
    }
    if (n1 % o == n % o){
        return p-1;
    }
    return por(n,o,p+1);
}

int main() {
    long long int a;
    int k;
    int m;
    cin >> n >> k >> m;
    n %= m;
    zet = por(n, m, 2);
    cout << g(n, k, m) << endl;
}