#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    int c = -1;
    int l = 0;
    int *ptr_1 = new int [0];
    int *ptr_2 = new int [0];
    cin >> c;
    while (c != 0){
        l++;
        ptr_2 = new int [l];
        for (int i = 0; i < l-1; i++){
            ptr_2[i] = ptr_1[i];
        }
        delete [] ptr_1;
        if (c != 0){
            ptr_2[l-1] = c;
        }
        ptr_1 = new int [l];
        for (int i = 0; i < l; i++){
            ptr_1[i] = ptr_2[i];
        }
        delete [] ptr_2;
        cin >> c;
    }
    for (int i; i < l-1; i++){
            cout << ptr_1[i]-ptr_1[i+1] << ' ';
        }
    
}