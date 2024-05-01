#include <iostream>
#include <chrono>
#include <cmath>
#include <random>
#include <chrono>
#include <cmath>
using namespace std;



void queue_new(std::size_t &read, std::size_t &write, int* &data){
    read = 0;
    write = 0;
}

bool queue_poll(std::size_t &read, std::size_t &write, int* &data, int &element){
    if (data == nullptr){
        return false;
    }
    if (read == write){
        return false;
    }
    element = data[read];
    read = (read+1)%(sizeof(data)/sizeof(data[0]));
    return true;
}

bool queue_push(std::size_t &read, std::size_t &write, int* &data, int element){
    if (data == nullptr){
        return false;
    }
    if ((write+1)%(sizeof(data)/sizeof(data[0]))==read){
        int* data1 = new(std::nothrow) int [sizeof(data)/sizeof(*data) * 2];
        if (data1 == nullptr){
            return false;
        }
        for (size_t i = 0; i<sizeof(data)/sizeof(data[0]); i++){
            if(i<=write){
                data1[i] = data[i];
            } else{
                data1[sizeof(data)/sizeof(data[0])+i] = data[i];
            }
        }
        data1[write] = element;
        write = (write+1)%(sizeof(data1)/sizeof(data1[0]));
        read = read + (sizeof(data1)/sizeof(data1[0]));
        delete[] data;
        data = data1;
        return true;
    }
    data[write] = element;
    write = (write+1)%(sizeof(data)/sizeof(data[0]));
    return true;
}
void queue_del(int* &data){
    delete[] data;
}
int main(){
    int N[] = {100, 500, 1000, 5000, 10000, 50000, 100000};
    int* array;
    size_t read = 0;
    size_t write = 0;
    auto begin = std::chrono::steady_clock::now();
    auto end = std::chrono::steady_clock::now();
    auto time = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();
    for (auto size: N) {
    array = new int[1] {0};
    queue_new(read, write, array);
    begin = std::chrono::steady_clock::now();
        for (size_t i = 0; i < size; ++i) {
            queue_push(read, write, array, 0);
        }
    end = std::chrono::steady_clock::now();
    time = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();
    cout << size << ": push  " << time << endl;
    int el = 0;
    begin = std::chrono::steady_clock::now();
        for (size_t i = 0; i < size; ++i) {
            queue_poll(read, write, array, el);
        }
    end = std::chrono::steady_clock::now();
    time = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();
    cout << size << ": poll  " << time << endl;
    queue_del;
    cout << endl;
    }
    return 0;
}