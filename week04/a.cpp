#include <iostream>
#include <cstdio>
using namespace std;
int main(){
    double *ptr;
    double n = 0;
    ptr = &n;
    cout << ptr << ' ' << *ptr << endl;
    ptr -= 3;
    cout << ptr << ' ' << *ptr << endl;
    ptr   += 5;
    cout << ptr << ' ' << *ptr << endl;
}