#include <iostream>
#include <chrono>
#include <cmath>
#include <random>
using namespace std;

int fun(int (&a)[], int N) {
    
    static int a0 = 0;
    static int b0 = N - 1;
    int c = 0;
    int g;
    if ((a0 != b0) and (a0 < b0)){
    for (int i = 0; i < b0 - a0; i++) {
        if ((a[a0] < a[a0 + 1 + i - c])) {
            g = a[a0 + 1 + i - c];
            a[a0 + 1 + i - c] = a[b0-c];
            a[b0-c] = g;
            c++;
        }
    }
    int f = 1;
    int j = 0;
    g = a[a0];
    a[a0] = a[b0-c];
    a[b0-c] = g;
    f = 0;
    g = b0;
    b0 = b0-1-c;
    fun(a, N);
    b0 = g;
    a0 = b0-c+1;
    fun(a, N);
    }
    for (int i = 0; i < N; i += 2) {
        if (a[i] != a[i+1]) {
            return a[i];
        }
    }
    return a[N-1];
}
void printArray(int (&arr)[], int N) {
    for (int i = 0; i < N; i++) {
        cout << arr[i];
        if (i != N) {
            cout << ' ';
        }
    }
    cout << endl;
}
int main(){
    int N[] = {600000};
    unsigned seed = 1001;
    default_random_engine rng(seed);
    
    for (int j = 0; j < 8; j++){
    uniform_int_distribution<unsigned> dstr(0,N[j]-1);
    int arr[N[j]]; 
    for (int i = 0; i < N[j]; i++){
        arr[i] = dstr(rng);
    }
    auto begin = std::chrono::steady_clock::now();
    for (unsigned cnt = 1; cnt != 0; --cnt){
        fun(arr, N[j]);
    }
    auto end = std::chrono::steady_clock::now();
    auto time_span = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
    cout << "\n\n";
    cout << N[j] << ' ' <<time_span.count() << endl;
    }
    return 0;
}