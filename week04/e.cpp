#include <iostream>
#include <cstdio>
using namespace std;

bool reserve_memory(size_t N, int *&dst){
    if (dst != nullptr){
        return 0;
    }
    try {
        dst = new int [N];
        return 1;
    }
    catch (const bad_alloc& e) {
        return 0;
    }
}
void free_memory(int* ptr){
    delete ptr;
}
int main(){
    int N = 0;
    int* ptr = nullptr;
    cin >> N;
    cout << reserve_memory(N, ptr) << endl;
    free_memory(ptr);
    return 0;
}