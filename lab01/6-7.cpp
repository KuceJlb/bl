#include <iostream>
#include <chrono>
#include <cmath>
 #include <random>
using namespace std;

int bad_alg(int arr[], int size_arr, int summ){
    for (int i=0; i < size_arr; i++){
        for (int j=i+1; j < size_arr; j++){
            if (arr[i] + arr[j] == summ){
                return 1;
            }
        }
    }
    return 0;
}

int good_alg(int arr[], int size_arr, int summ){
    int r = size_arr-1;
    int l = 0;
    for (int i = 0; i < size_arr-1; i++){
        if (arr[r]+arr[l] == summ){
            return 1;
        }
        if (arr[r]+arr[l] < summ){
            l++;
        } else {
            if (arr[r]+arr[l] > summ){
                r--;
            }
        }
    }
    return 0;
}

int main(){
    unsigned seed = 1001;
    default_random_engine rng(seed);
    
    int N[] = {1000, 1500, 2000, 2500, 3000, 3500, 4000, 4500, 5000};
    for (auto size: N) {
        uniform_int_distribution<unsigned> dstr1(-size,size*3);
        int arr[size];
        for (size_t i = 0; i < size; ++i) {
            arr[i] = i;
        }
        double f2_bad_meantime = 0, f2_good_meantime = 0;
        auto begin = std::chrono::steady_clock::now();
        for (size_t i = 0; i < 1000; ++i) {
            bad_alg(arr, size, dstr1(rng));
            bad_alg(arr, size, dstr1(rng));
        }
        auto end = std::chrono::steady_clock::now();
        f2_bad_meantime += std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
        cout << size << ": bad  " << f2_bad_meantime << endl;
        
        begin = std::chrono::steady_clock::now();
        
        for (size_t i = 0; i < 100000; ++i) {
            good_alg(arr, size, dstr1(rng));
            good_alg(arr, size, dstr1(rng));
        }
        end = std::chrono::steady_clock::now();
        f2_good_meantime += std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
        cout << size << ": good " << f2_good_meantime << endl << endl;
    }
    return 0;
}