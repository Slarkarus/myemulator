#include "../include/stack.h"

#include <iostream>

using namespace MST;

template <typename T>
void Stack<T>::push(T var){
    MST::Node<T> new_node;
    new_node.data = var;
    new_node.prev = last;
    last = *new_node;
}
template <typename T>
void Stack<T>::pop(){
    MST::Node<T> node = last->prev;
    delete last->data;
    delete last;
    last = node;

}