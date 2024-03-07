#include <iostream>
#include <chrono>
#include <cmath>
 #include <random>
using namespace std;
bool f2(int arr[], unsigned N) {
    bool is_any_positive = false;
    for (auto idx = 0u; idx != N; ++idx)
        if (arr[idx] > 0) is_any_positive = true;
    return is_any_positive;
}


int main(){
    unsigned seed = 1001;
    default_random_engine rng(seed);
    
    int N[] = {100, 500, 1000, 5000, 10000, 50000, 100000, 500000};
    for (auto size: N) {
        uniform_int_distribution<unsigned> dstr1(1,-1);
        int arr[size];
        for (size_t i = 0; i < size; ++i) {
            arr[i] = i;
        }
        cout << f2(arr, size) << endl;
        double f2_bad_meantime = 0, f2_good_meantime = 0;
        auto begin = std::chrono::steady_clock::now();
        for (size_t i = 0; i < 100000; ++i) {
            
            f2(arr, size);
            
            
        }
        auto end = std::chrono::steady_clock::now();
        f2_bad_meantime += std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
        cout << size << ": bad  " << f2_bad_meantime << endl;
        uniform_int_distribution<unsigned> dstr2(1,-1);
        begin = std::chrono::steady_clock::now();
        for (size_t i = 0; i < 100000; ++i) {
            
            f2(arr, size);
            
        }
        end = std::chrono::steady_clock::now();
        f2_good_meantime += std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
        cout << size << ": good " << f2_good_meantime << endl << endl;
    }
   
return 0;
}