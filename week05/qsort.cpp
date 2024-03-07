#include <iostream>
#include <cstdio>
using namespace std;
int const N = 9;
int arr[N] = {0,3,5,1,2,0,6,1,1};
void printArray(int (&arr)[N]);


void qsort(int (&array)[N], int ind_left_base, int ind_right_base) {
    int c = 0;
    int g;
    if ((ind_left_base != ind_right_base) and (ind_left_base < ind_right_base)){
    for (int i = 0; i < ind_right_base - ind_left_base; i++) {
        if ((array[ind_left_base] < array[ind_left_base + 1 + i - c])) {
            g = array[ind_left_base + 1 + i - c];
            array[ind_left_base + 1 + i - c] = array[ind_right_base-c];
            array[ind_right_base-c] = g;
            c++;
        }
    }
    g = array[ind_left_base];
    array[ind_left_base] = array[ind_right_base-c];
    array[ind_right_base-c] = g;
    g = ind_right_base;
    ind_right_base = ind_right_base-1-c;
    qsort(array, ind_left_base, ind_right_base);
    ind_right_base = g;
    ind_left_base = ind_right_base-c+1;
    qsort(array, ind_left_base, ind_right_base);
    }
}
int h_sort(int (&array){N}, int right_ind){
    int _2N = 1;
    int g;
    while (_2N < right_ind){
        _2N *= 2;
    }
    for (i = _2N/2-2; i >= 0; i++){
        if (array[i] < array[2*i+1]){
            g = array[i];
            array[i] = array[2*i+1];
            array[2*i+1] = g;
        }
        if (array[i] < array[2*i+2]){
            g = array[i];
            array[i] = array[2*i+2];
            array[2*i+2] = g;
        }
    }
    g = array[right_ind];
    array[right_ind] = array[0];
    array[0] = g;
    if (right_ind != 0){
        h_sort(array, right_ind-1)
    }
    return 0;
}

void printArray(int (&arr)[N]) {
    for (int i = 0; i < N; i++) {
        cout << arr[i];
        if (i != N) {
            cout << ' ';
        }
    }
    cout << endl;
}

int main() {
    qsort(arr, 0, N-1);
    printArray(arr);
    return 0;
}