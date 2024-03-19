#ifndef TMP_STACK_H
#define TMP_STACK_H

#include <cstdlib>

// My STack
namespace MST{
    template <typename T>
    struct Node{
        T data;
        Node* prev;
        Node(T data, Node* prev);
    };

    template <typename T>
    class Stack{
    private:
        Node<T> *last;
        size_t arr_size;
    public:
        Stack(); // constructor
        ~Stack(); // destructor
        Stack(const Stack &other); // copy constructor
        Stack(Stack&& other) noexcept ; // move constructor
        Stack& operator=(const Stack& other);// copy assignment
        Stack& operator=(Stack&& other) noexcept ;// move assignment
        void push(T var); // push elem in stack
        void pop(); // pop elem from top of stack
        T top(); // return top elem of stack
        bool empty(); // return true if stack empty
        size_t size(); // return size of stack
        void clear(); // clear stack
    };

}


#endif //TMP_STACK_H
