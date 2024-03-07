#include <iostream>
#include <cstdio>
#include <math.h>

using namespace std;

int is_p(int a,int b){
    if (a == 1){
        return 0;
    } else {
        if (b*b > a) {
            return 1;
        } else {
            if (a % b == 0) {
                return 0;
            } else {return is_p(a,b+1);}
        }
    }
}

int main() {
    int n;
    int ans;
    cin >> n;
    ans = is_p(n,2);
    if (ans) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}