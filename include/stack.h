#ifndef TMP_STACK_H
#define TMP_STACK_H

#include <cstdlib>

// My STack
namespace MST{

    template <typename  T>
    struct Node{
        T data;
        Node* prev;
        explicit Node(T &data_, Node* prev_= nullptr)
        {
            data = data_;
            prev = prev_;
        }
    };

    template <typename  T>
    class Stack{
    private:
        Node<T> *last;
        size_t arr_size;
        void copy(Stack<T> *stack, Node<T> *node) {
            if(!node){
                return;
            }

            copy(stack, node->prev);
            stack->push(node->data);
        }

        void self_delete(Node <T> *node){
            if(!node){
                return;
            }
            self_delete(node->prev);
            delete node;

        }

    public:
        Stack()
        {
            last = nullptr;
            arr_size = 0;
        }


        ~Stack()
        {
            arr_size = 0;
            delete last;
        }

        
        Stack(const Stack<T>& other)
        {
            if(this != &other) {
                arr_size = 0;
                copy(this, other.last);
            }
        }

        
        Stack(Stack &&other) noexcept{
            if(this != &other) {
                last = other.last;
                other.last = nullptr;
                arr_size = other.arr_size;
                other.arr_size = 0;
            }
        }

        
        Stack<T>& operator=(const Stack& other)
        {
            if(this != &other){
                arr_size = 0;
                copy(this, other.last);
            }
            return *this;
        }

        
        Stack<T>& operator=(Stack&& other) noexcept
        {
            if(this != &other) {
                last = other.last;
                other.last = nullptr;
                arr_size = other.arr_size;
                other.arr_size = 0;
            }
            return *this;
        }

        
        void push(T var)
        {
            auto *new_node = new Node<T>(var, last);
            new_node->prev = last;
            arr_size++;
            last = new_node;
        }

        void push(T&& var)
        {
            auto *new_node = new Node<T>(var, last);
            new_node->prev = last;
            arr_size++;
            last = new_node;
        }
        
        void pop()
        {
            if(empty()) {
                return;
            }
            Node<T>* node = last->prev;
            delete last;
            arr_size--;
            last = node;
        }

        
        T top()
        {
            return last->data;
        }

        
        bool empty()
        {
            return arr_size == 0;
        }

        
        size_t size()
        {
            return arr_size;
        }

        
        void clear()
        {
            while (!empty()) {
                pop();
            }
        }
    };

}


#endif //TMP_STACK_H
