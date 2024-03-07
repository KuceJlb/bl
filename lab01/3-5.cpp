#include <iostream>
#include <chrono>
#include <cmath>
 #include <random>
using namespace std;
int bad_alg(int A[], int size_A, int a){
    for (int i = 0; i < size_A; i++){
        if (A[i] == a){
            return i;
        }
    }
    return -1;
}
int good_alg(int A[], int size_A, int a){
    int r = size_A - 1;
    int l = 0;
    int c = size_A/2;
    while ((r > l) and (A[c] != a)) {
        if (A[c] < a) {
            if (c < size_A-1){l = c+1;} 
            else {l = c;}
            c = r - (r-l)/2;
        } else {
            if (c > 0){r = c-1;} else {r = c;}
            c = r - (r-l)/2;
        }
    }
    if (A[c] == a){
        return c;
    }
    return -1;
}
int main(){
    unsigned seed = 1001;
    default_random_engine rng(seed);
    
    int N[] = {100, 500, 1000, 5000, 10000, 50000, 100000, 500000};
    for (auto size: N) {
        uniform_int_distribution<unsigned> dstr1(size,size*2);
        uniform_int_distribution<unsigned> dstr2(0,size);
        int arr[size];
        for (size_t i = 0; i < size; ++i) {
            arr[i] = i;
        }
        double f2_bad_meantime = 0, f2_good_meantime = 0;
        
        auto begin = std::chrono::steady_clock::now();
        for (size_t i = 0; i < 100000; ++i) {
            good_alg(arr, size, dstr1(rng));
        }
        auto end = std::chrono::steady_clock::now();
        f2_bad_meantime += std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
        cout << size << ": bad time good alg  " << f2_bad_meantime << endl;
        
        begin = std::chrono::steady_clock::now();
        
        for (size_t i = 0; i < 100000; ++i) {
            good_alg(arr, size, dstr2(rng));            
        }
        end = std::chrono::steady_clock::now();
        f2_good_meantime += std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
        cout << size << ": mean time good alg " << f2_good_meantime << endl;

        begin = std::chrono::steady_clock::now();
        
        for (size_t i = 0; i < 100000; ++i) {
            bad_alg(arr, size, dstr2(rng));            
        }
        end = std::chrono::steady_clock::now();
        f2_good_meantime += std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
        cout << size << ": bad time bad alg " << f2_good_meantime << endl;

        begin = std::chrono::steady_clock::now();
        
        for (size_t i = 0; i < 100000; ++i) {
            bad_alg(arr, size, dstr2(rng));            
        }
        end = std::chrono::steady_clock::now();
        f2_good_meantime += std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
        cout << size << ": mean time bad alg " << f2_good_meantime << endl << endl;
    }
return 0;
}