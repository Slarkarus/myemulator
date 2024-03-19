#include "../include/stack.h"


using namespace MST;

namespace {
    template<typename T>
    void recursion_copy(Stack<T> &stack, Node<T> *node) {
        if (node->prev == nullptr) {
            stack.push(node->data);
            return;
        }
        recursion_copy(stack, node->prev);
        stack.push(node->data);
    }
}



template <typename T>
Node<T>::Node(T data_, Node* prev_)
{
    data = data_;
    prev = prev_;
}

template <typename T>
Stack<T>::Stack()
{
    last = nullptr;
    arr_size = 0;
}

template <typename  T>
Stack<T>::~Stack()
{
    if (arr_size == 0) {
        return;
    }

    Node<T> *head;
    do {
        head = last->prev;
        delete last;
        last = head;
    }
    while (head);
}

template <typename T>
Stack<T>::Stack(const Stack<T>& other)
{
    arr_size = other.arr_size;
    recursion_copy((*this), other.last);
}

template <typename T>
Stack<T>::Stack(Stack &&other) noexcept{
    last = other.last;
    other.last = nullptr;
    arr_size = other.arr_size;
    other.arr_size = 0;

}

template <typename T>
Stack<T>& Stack<T>::operator=(const Stack& other)
{
    //Stack<T> result;
    arr_size = other.arr_size;
    recursion_copy(this, other.last);
    //return result;
}

template <typename T>
Stack<T>& Stack<T>::operator=(Stack&& other) noexcept
{
    Stack<T> result;
    result.last = other.last;
    other.last = nullptr;
    result.arr_size = other.arr_size;
    other.arr_size = 0;
    return result;
}

template <typename T>
void Stack<T>::push(const T var)
{
    auto *new_node = new Node<T>(var, last);
    new_node->prev = last;
    arr_size++;
    last = new_node;
}

template <typename T>
void Stack<T>::pop()
{
    if(empty()) {
        return;
    }
    Node<T>* node = last->prev;
    delete last;
    arr_size--;
    last = node;
}

template <typename T>
T Stack<T>::top()
{
    return last->data;
}

template <typename T>
bool Stack<T>::empty()
{
    return arr_size == 0;
}

template <typename T>
size_t Stack<T>::size()
{
    return arr_size;
}

template <typename T>
void Stack<T>::clear()
{
    while (!empty()) {
        pop();
    }
}