#include <iostream>
#include "../../include/stlmp.h"

using namespace std;
using namespace stlmp::LinkedList;

template<class T>
void stlmp::Queue::Queue<T>::push(T new_data) {
    LLNode<T> *new_node = new LLNode<T>(new_data);
    LLNode<T> *temp_node = this->head;
    new_node->next = temp_node;
    this->head = new_node;
    this->size++;
}

template<class T>
void stlmp::Queue::Queue<T>::print() {
    if (this->size == 0) {
        cout << "queue is empty" << endl;
        return;
    }
    LLNode<T> *temp_node = this->head;
    cout << "Printing queue:" << endl;
    for (int i = 0; i < this->size; i++) {
        cout << temp_node->data << " ";
        temp_node = temp_node->next;
    }
    cout << endl;
}

template<class T>
T stlmp::Queue::Queue<T>::pop() {
    if (this->size == 0) {
        cout << "queue is empty, can't pop" << endl;
        return (T) '\0';
    }
    if (this->size == 1) {
        T data = this->head->data;
        this->head = NULL;
        this->size = 0;
        return data;
    }
    LLNode<T> *new_node = this->head;
    // move to second last element
    for (int i = 0; i < this->size - 2; i++) new_node = new_node->next;
    //cout << new_node->data << endl;
    T data = new_node->next->data;
    new_node->next = NULL;
    this->size--;
    return data;
}

template<class T>
T stlmp::Queue::Queue<T>::peek() {
    return this->head->data;
}
