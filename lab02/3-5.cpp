#include <iostream>
#include <chrono>
#include <cmath>
#include <random>
#include <chrono>
#include <cmath>
using namespace std;

struct list {
    int* array = nullptr;
    int size = 0;
    int n = 0;
};
void printArray(list* arr) {
    for (int i = 0; i < arr->n+1; i++) {
        cout << arr->array[i];
        if (i != arr->n+1) {
            cout << ' ';
        }
    }
    cout << endl;
}
list* push1(list* array, int el){
    if (array->size > array->n + 1){
        array->array[array->n +1] = el;
        array->n=array->n + 1;
        return array;
    }
    if (array->size == 0){
        array->array = new int[1];
        array->array[0] = el;
        array->size = 1;
        return array;
    }
    int* array1 = array->array;
    array->size = array->size + 1;
    array->n = array->n + 1;
    array->array = new int[array->size];
    for (int i=0; i<array->n; i++){
        array->array[i] = array1[i];
    }
    delete[] array1;
    array->array[array->n] = el;
    return array;
}

list* push100(list* array, int el){
    if (array->size > array->n + 1){
        array->array[array->n +1] = el;
        array->n=array->n + 1;
        return array;
    }
    if (array->size == 0){
        array->array = new int[1];
        array->array[0] = el;
        array->size = 1;
        return array;
    }
    int* array1 = array->array;
    array->size = array->size + 100;
    array->n = array->n + 1;
    array->array = new int[array->size];
    for (int i=0; i<array->n; i++){
        array->array[i] = array1[i];
    }
    delete[] array1;
    array->array[array->n] = el;
    return array;
}

list* push_x2(list* array, int el){
    if (array->size > array->n + 1){
        array->array[array->n +1] = el;
        array->n=array->n + 1;
        return array;
    }
    if (array->size == 0){
        array->array = new int[1];
        array->array[0] = el;
        array->size = 1;
        return array;
    }
    int* array1 = array->array;
    array->size = array->size * 2;
    array->n = array->n + 1;
    array->array = new int[array->size];
    for (int i=0; i<array->n; i++){
        array->array[i] = array1[i];
    }
    delete[] array1;
    array->array[array->n] = el;
    return array;
}

int main(){
    int N[] = {100, 500, 1000, 5000, 10000, 50000, 100000};
    list* array;
    auto begin = std::chrono::steady_clock::now();
    auto end = std::chrono::steady_clock::now();
    auto time = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
    for (auto size: N) {
    array = new list;
    begin = std::chrono::steady_clock::now();
        for (size_t i = 0; i < size; ++i) {
            push1(array, 0);
        }
    end = std::chrono::steady_clock::now();
    time = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
    cout << size << ": push1  " << time << endl;
    delete[] array->array;

    }
    for (auto size: N) {
    array = new list;
    begin = std::chrono::steady_clock::now();
        for (size_t i = 0; i < size; ++i) {
            push100(array, 0);
        }
    end = std::chrono::steady_clock::now();
    time = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
    cout << size << ": push100  " << time << endl;
    delete[] array->array;
    }
    for (auto size: N) {
    array = new list;
    begin = std::chrono::steady_clock::now();
        for (size_t i = 0; i < size; ++i) {
            push_x2(array, 0);
        }
    end = std::chrono::steady_clock::now();
    time = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
    cout << size << ": push_x2  " << time << endl;
    delete[] array->array;
    }
}