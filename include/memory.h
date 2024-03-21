//
// Created by marmlll on 20.03.2024.
//

#ifndef MY_PROJECT_MEMORY_H
#define MY_PROJECT_MEMORY_H

#include "stack.h"
#include <map>
#include <string>
// My MEmory
namespace MME{
    class Memory {
    private:
        MST::Stack<int> main_stack;
        std::map<std::string, int> registers;
        MST::Stack<int> call_stack;
    public:
        int get_register(const std::string& reg) {
            return registers[reg];
        }

        void set_register(std::string reg, int value){
            registers[reg] = value;
        }

        void push_main_stack(int x){
            main_stack.push(x);
        }

        void pop_main_stack(){
            main_stack.pop();
        }

        int top_main_stack(){
            return main_stack.top();
        }

        size_t size_main_stack(){
            return main_stack.size();
        }

    };
}

#endif //MY_PROJECT_MEMORY_H
