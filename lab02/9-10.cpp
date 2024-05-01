#include <iostream>
#include <chrono>
#include <cmath>
#include <random>
#include <chrono>
#include <cmath>
using namespace std;
struct Node {
    void * key = nullptr;
    Node * next = nullptr;
    Node * prev = nullptr;
};
struct queue {
    Node * NIL = nullptr;
    Node * first = NIL;
    Node * last = NIL;
    int size = 0;
    int size_el = 0;
};
queue* new_queue(int size_el){
    queue* que = new queue;
    que->size_el = size_el;
    que->NIL = new Node;
    que->first =que->NIL;
    que->last = que->NIL;
    return que;
}
bool push_front(queue*& queue, void* new_key){
    Node* new_el = new(std::nothrow) Node;
    if (new_el == nullptr){
        return false;
    }
    if (queue->size == 0){
        new_el->key = new_key;
        queue->first = new_el;
        queue->last = new_el;
        new_el->next = queue->NIL;
        new_el->prev = queue->NIL;
        queue->size++;
        return true;
    }
    new_el->key = new_key;
    queue->first->next = new_el;
    new_el->prev = queue->first;
    queue->first = new_el;
    new_el->next = queue->NIL;
    queue->size++;
    return true;
}
bool push_back(queue*& queue, void* new_key){
    Node* new_el = new(std::nothrow) Node;
    if (new_el == nullptr){
        return false;
    }
    if (queue->size == 0){
        new_el->key = new_key;
        queue->first = new_el;
        queue->last = new_el;
        new_el->next = queue->NIL;
        new_el->prev = queue->NIL;
        queue->size++;
        return true;
    }
    new_el->key = new_key;
    queue->last->prev = new_el;
    new_el->next = queue->last;
    queue->last = new_el;
    new_el->prev = queue->NIL;
    queue->size++;
    return true;
}

void* poll_front(queue*& queue){
    Node *ptr_el = queue->first;
    queue->first = ptr_el->prev;
    queue->first->next = queue->NIL;
    queue->size--;
    return ptr_el->key;
}

void* poll_back(queue*& queue){
    Node *ptr_el = queue->last;
    queue->last = ptr_el->next;
    queue->last->prev = queue->NIL;
    queue->size--;
    return ptr_el->key;
}

void del_queue(queue*& queue){
    Node * c = queue->first;
    Node * c1;
    while (c!=queue->NIL){
        c1 = c->next;
        delete c;
        c = c1;
    }
    delete c;
    delete queue;
}

int main(){
    queue* q = new_queue(8);
    del_queue(q);
    q = new_queue(8);
    int* a = new int [10];
    for (int i = 0; i < 10; i++){
        a[i] = i;
    }
    //cout << *(reinterpret_cast<int*>(reinterpret_cast<void*>(&a[3])));
    for (int i = 0; i < 10; i++){
        push_front(q, (reinterpret_cast<void*>(&a[i])));
    }
    void * ptr;
    for (int i = 0; i < 10; i++){
        push_back(q, (reinterpret_cast<void*>(&a[i])));
    }
    Node * ptr1=q->first;
    for (int i = 0; i < 20; i++){
        cout << *(reinterpret_cast<int*>(ptr1->key))<< endl;
        ptr1 = ptr1->prev;
    }
    cout << endl;
    //cout << *(reinterpret_cast<int*>(q->first->key)) << endl;
    for (int i = 0; i < 10; i++){
        ptr = poll_back(q);
        cout << *(reinterpret_cast<int*>(ptr)) << endl;
        ptr = poll_front(q);
        cout << *(reinterpret_cast<int*>(ptr)) << endl;
        cout << endl;
    }

    return 0;
}