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

void g_sort(int (&array)[N]){
    int c = 0;
    while (c+1 != N){
        if (array[c] <= array[c+1]){
            c++;
            continue;
        }
        else{
            array[c] += array[c+1];
            array[c+1] = array[c] - array[c+1];
            array[c] -= array[c+1];
            c--;
        }
    }
}

int main() {
    g_sort(arr);
    printArray(arr);
    return 0;
}