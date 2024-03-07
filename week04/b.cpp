#include <iostream>
#include <cstdio>
using namespace std;
int main(){
    short int *ptr = new short int [10];
    for (int i = 0; i < 10; i++){
        ptr[i] = i;
        cout << &ptr[i] << ' ';
    }
    cout << endl;
    for (int i = 0; i < 10; i++){
        cout << ptr[i] << ' ';
    }
    cout << endl;
    for (int i = 1; i < 10; i+=2){
        ptr[i] *= ptr[i];
    }
    for (int i = 0; i < 10; i++){
        cout << ptr[i] << ' ';
    }

}