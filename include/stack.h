#ifndef TMP_STACK_H
#define TMP_STACK_H

// My STack

#include <cstdlib>

namespace MST{

    template <typename T>
    struct Node{
        T data;
        Node *prev;
    };

    template <typename T>
    class Stack{
    private:
        Node<T> *last;
        size_t arr_size;
    public:
        Stack(T cur_last, size_t cur_size); // конструктор
        ~Stack(); // деструктор
        Stack(const Stack& other):last(other.last); // copy - копирование
        Stack(Stack&& other)noexcept:last(other.last); // move - перемещение
        Stack& operator=(const Stack& other);// присваивание копированием
        Stack& operator=(Stack&& other);// присваивание перемеещнием
        void push(T var); //+
        void pop();
        T top();
        bool empty();
        size_t size();



    };
}


#endif //TMP_STACK_H
