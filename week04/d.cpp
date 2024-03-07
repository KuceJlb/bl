#include <iostream>
#include <cstdio>
using namespace std;


void input_array(int* ptr, size_t N){
    for  (int i = 0; i < N; i++){
        cin >> ptr[i];
    }

}
void reverse(int* ptr, size_t N){
    int el = 0;

    for  (int i = 0; i < N/2; i++){
        el = ptr[i];
        ptr[i] = ptr[N-1-i];
        ptr[N-1-i] = el;
    } 
}
void print(const int* ptr, size_t N){
    for  (int i = 0; i < N; i++){
        cout << ptr[i] << ' ';
    }
}

int main(){
    int N = 0;
    int* ptr = nullptr;
    cin >> N;
    ptr = new int [N];
    input_array(ptr, N);
    reverse(ptr, N);
    print(ptr, N);
    delete[] ptr;
    return 0;
}