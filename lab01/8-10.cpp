#include <iostream>
#include <chrono>
#include <cmath>
 #include <random>
using namespace std;

int f1(int (&A)[], int size_A, int a){
    int c = 0;
    for (int i = 0; i < size_A; i++){
        if (A[i] == a){
            c = i;
            return i;
        }
    }
    return -1;
}
int f1_1(int (&A)[], int size_A, int a){
    int c = 0;
    for (int i = 0; i < size_A; i++){
        if (A[i] == a){
            c = i;
            return i;
        }
    }
    int g;
    if (A[c] == a){
        g = A[0];
        A[0] = A[c];
        A[c] = g;
        return c;
    }
    return -1;
}
int f1_2(int (&A)[], int size_A, int a){
    int c = 0;
    for (int i = 0; i < size_A; i++){
        if (A[i] == a){
            c = i;
            return i;
        }
    }
    int g;
    if (A[c] == a){
        if (c != 0){
        g = A[c-1];
        A[c-1] = A[c];
        A[c] = g;
        }
        return c;
    }
    return -1;
}

int f1_3(int (&A)[],int (&B)[], int size_A, int a){
    int c = 0;
    for (int i = 0; i < size_A; i++){
        if (A[i] == a){
            c = i;
            return i;
        }
    }
    int g;
    if (A[c] == a){
        B[c]++;
        if ((B[c] > B[c-1]) and (c != 0)){
            g = A[c-1];
            A[c-1] = A[c];
            A[c] = g;
        }
        return c;
    }
    return -1;
}

int main(){
    unsigned seed = 1001;
    default_random_engine rng(seed);
    
    int N[] = {100, 200, 300, 400, 500, 600, 700, 800, 900, 1000};
    for (auto size: N) {
        int B[size] = {0};
        int A[size];
        uniform_int_distribution<unsigned> dstr1(size,size*2);
        uniform_int_distribution<unsigned> dstr2(size-size/9,size-size/10);

        for (size_t i = 0; i < size; ++i) {
            A[i] = i;
        }
        
        double f2_bad_meantime = 0, f2_good_meantime = 0;
        auto begin = std::chrono::steady_clock::now();
        for (size_t i = 0; i < 10000000; ++i) {
            f1(A, size, dstr2(rng));
            
            
        }
        auto end = std::chrono::steady_clock::now();
        for (size_t i = 0; i < size; ++i) {
            A[i] = i;
        }
        f2_bad_meantime += std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
        cout << size << ": 0  " << f2_bad_meantime << endl;
        
        begin = std::chrono::steady_clock::now();
        
        for (size_t i = 0; i < 10000000; ++i) {
            f1_1(A, size, dstr2(rng));
            
        }
        end = std::chrono::steady_clock::now();
        for (size_t i = 0; i < size; ++i) {
            A[i] = i;
        }
        f2_good_meantime += std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
        cout << size << ": 1 " << f2_good_meantime << endl;

        begin = std::chrono::steady_clock::now();
        
        for (size_t i = 0; i < 10000000; ++i) {
            f1_2(A, size, dstr2(rng));
            
        }
        end = std::chrono::steady_clock::now();
        for (size_t i = 0; i < size; ++i) {
            A[i] = i;
        }
        f2_good_meantime += std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
        cout << size << ": 2 " << f2_good_meantime << endl;

        begin = std::chrono::steady_clock::now();
        for (size_t i = 0; i < 10000000; ++i) {
            f1_3(A, B, size, dstr2(rng));
            
            
        }
        end = std::chrono::steady_clock::now();
        f2_bad_meantime += std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
        cout << size << ": 3  " << f2_bad_meantime << endl << endl;
    }
return 0;
}