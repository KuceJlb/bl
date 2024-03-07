#include <iostream>
#include <cstdio>
using namespace std;
int const N = 9;
int arr[N] = {0,3,5,1,2,0,6,1,1};



void printArray(int (&arr)[N]) {
    for (int i = 0; i < N; i++) {
        cout << arr[i];
        if (i != N) {
            cout << ' ';
        }
    }
    cout << endl;
}

void h_sort(int (&array)[N], int right_ind){
    int _2N = 1;
    int g;
    while (_2N <= right_ind){
        _2N *= 2;
    }
    for (int i = _2N/2-2; i >= 0; i--){
        if (array[i] < array[2*i+1] and 2*i+1 <= right_ind){
            g = array[i];
            array[i] = array[2*i+1];
            array[2*i+1] = g;
        }
        if (array[i] < array[2*i+2] and 2*i+2 <= right_ind){
            g = array[i];
            array[i] = array[2*i+2];
            array[2*i+2] = g;
        }
    }
    g = array[right_ind];
    array[right_ind] = array[0];
    array[0] = g;
    if (right_ind != 0){
        h_sort(array, right_ind-1);
    }
}

int main() {
    h_sort(arr, N-1);
    printArray(arr);
    return 0;
}