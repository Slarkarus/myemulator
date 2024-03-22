//
// Created by marmlll on 20.03.2024.
//

#ifndef MY_PROJECT_COMMANDS_H
#define MY_PROJECT_COMMANDS_H

#include <iostream>
#include <string>
#include <vector>
#include "memory.h"
#include <map>
#include <memory>

// My CoMmands
namespace MCM {


    class Command {
    public:
        Command()= default;
        virtual void run(MME::Memory&) const = 0;
        virtual std::string name() const = 0;

        std::string arg;
    };

    class Begin: public Command{
    public:
        Begin()= default;
        std::string name() const override{return "BEGIN";}

        void run(MME::Memory &mem) const override
        {
            mem.set_register("is running", 1);
        }

    };

    class End: public Command{
    public:
        End()= default;
        std::string name() const override{return "END";}

        void run(MME::Memory &mem)const override
        {
            mem.set_register("is running", 0);
        }
    };

    class Push: public Command{
    public:
        Push()= default;
        std::string name() const override{return "PUSH";}

        void run(MME::Memory &mem)const override
        {
            mem.push_main_stack(stoi(arg));
        }
    };

    class Pop: public Command{
    public:
        Pop()= default;
        std::string name() const override{return "POP";}


        void run(MME::Memory &mem)const override
        {
            mem.pop_main_stack();
        }
    };

    class Pushr: public Command{
    public:
        Pushr()= default;
        std::string name() const override{return "PUSHR";}

        void run(MME::Memory &mem)const override
        {
            mem.push_main_stack(mem.get_register(arg));
        }
    };

    class Popr: public Command{
    public:
        Popr()= default;
        std::string name() const override{return "POPR";}

        void run(MME::Memory &mem)const override
        {
            mem.set_register(arg, mem.top_main_stack());
            mem.pop_main_stack();
        }
    };

    class Add: public Command{
    public:
        Add()= default;
        std::string name() const override{return "ADD";}

        void run(MME::Memory &mem)const override
        {
            int x = mem.top_main_stack();
            mem.pop_main_stack();
            int y = mem.top_main_stack()+x;
            mem.push_main_stack(x);
            mem.push_main_stack(y);
        }
    };

    class Sub: public Command{
    public:
        Sub()= default;
        std::string name() const override{return "SUB";}

        void run(MME::Memory &mem)const override
        {
            int x = mem.top_main_stack();
            mem.pop_main_stack();
            int y = x-mem.top_main_stack();
            mem.push_main_stack(x);
            mem.push_main_stack(y);
        }
    };

    class Mul: public Command{
    public:
        Mul()= default;
        std::string name() const override{return "MUL";}

        void run(MME::Memory &mem)const override
        {
            int x = mem.top_main_stack();
            mem.pop_main_stack();
            int y = x*mem.top_main_stack();
            mem.push_main_stack(x);
            mem.push_main_stack(y);
        }
    };

    class Div: public Command{
    public:
        Div()= default;
        std::string name() const override{return "DIV";}

        void run(MME::Memory &mem)const override
        {
            int x = mem.top_main_stack();
            mem.pop_main_stack();
            int y = x/mem.top_main_stack();
            mem.push_main_stack(x);
            mem.push_main_stack(y);
        }
    };

    class Out: public Command{
    public:
        Out()= default;
        std::string name() const override{return "OUT";}

        void run(MME::Memory &mem)const override
        {
            int x = mem.top_main_stack();
            mem.pop_main_stack();
            std::cout << x << '\n';
        }
    };

    class In: public Command{
    public:
        In()= default;
        std::string name() const override{return "IN";}

        void run(MME::Memory &mem)const override
        {
            int x;
            std::cin >> x;
            mem.push_main_stack(x);
        }
    };

    class Jmp: public Command{
    public:
        Jmp()= default;
        std::string name() const override{return "JMP";}

        void run(MME::Memory &mem)const override
        {
            mem.set_register("jump to", mem.get_label_pos(arg));
        }
    };

    class Jeq: public Command{
    public:
        Jeq()= default;
        std::string name() const override{return "JEQ";}

        void run(MME::Memory &mem)const override
        {
            int a = mem.top_main_stack();
            mem.pop_main_stack();
            if(mem.top_main_stack() == a) {
                mem.set_register("jump to", mem.get_label_pos(arg));
            }
            mem.push_main_stack(a);
        }
    };

    class Jne: public Command{
    public:
        Jne()= default;
        std::string name() const override{return "JNE";}

        void run(MME::Memory &mem)const override
        {
            int a = mem.top_main_stack();
            mem.pop_main_stack();
            if(mem.top_main_stack() != a) {
                mem.set_register("jump to", mem.get_label_pos(arg));
            }
            mem.push_main_stack(a);
        }
    };

    class Ja: public Command{
    public:
        Ja()= default;
        std::string name() const override{return "JA";}

        void run(MME::Memory &mem)const override
        {
            int a = mem.top_main_stack();
            mem.pop_main_stack();
            if(mem.top_main_stack() < a) {
                mem.set_register("jump to", mem.get_label_pos(arg));
            }
            mem.push_main_stack(a);
        }
    };

    class Jae: public Command{
    public:
        Jae()= default;
        std::string name() const override{return "JAE";}

        void run(MME::Memory &mem)const override
        {
            int a = mem.top_main_stack();
            mem.pop_main_stack();
            if(mem.top_main_stack() <= a) {
                mem.set_register("jump to", mem.get_label_pos(arg));
            }
            mem.push_main_stack(a);
        }
    };

    class Jb: public Command{
    public:
        Jb()= default;
        std::string name() const override{return "JB";}

        void run(MME::Memory &mem)const override
        {
            int a = mem.top_main_stack();
            mem.pop_main_stack();
            if(mem.top_main_stack() > a) {
                mem.set_register("jump to", mem.get_label_pos(arg));
            }
            mem.push_main_stack(a);
        }
    };

    class Jbe: public Command{
    public:
        Jbe()= default;
        std::string name() const override{return "JBE";}

        void run(MME::Memory &mem)const override
        {
            int a = mem.top_main_stack();
            mem.pop_main_stack();
            if(mem.top_main_stack() >= a) {
                mem.set_register("jump to", mem.get_label_pos(arg));
            }
            mem.push_main_stack(a);
        }
    };

    class Call: public Command{
    public:
        Call()= default;
        std::string name() const override{return "CALL";}

        void run(MME::Memory &mem)const override
        {
            mem.set_register("call to", mem.get_label_pos(arg));
        }
    };

    class Ret: public Command{
    public:
        Ret()= default;
        std::string name() const override{return "RET";}

        void run(MME::Memory &mem)const override
        {
            mem.set_register("return back", 1);
        }
    };

    class Lab: public Command{
    public:
        Lab()= default;
        std::string name() const override{return "LAB";}
        void run(MME::Memory &mem)const override{}

    };


    std::map<std::string, int> COMMANDS_LIST{
            {"BEGIN", 0},
            {"END",   1},
            {"PUSH",  2},
            {"POP",   3},
            {"PUSHR", 4},
            {"POPR",  5},
            {"ADD", 6},
            {"SUB", 7},
            {"MUL", 8},
            {"DIV", 9},
            {"OUT", 10},
            {"IN", 11},
            {"JMP", 12},
            {"JEQ", 13},
            {"JNE", 14},
            {"JA", 15},
            {"JAE", 16},
            {"JB", 17},
            {"JBE", 18},
            {"CALL", 19},
            {"RET", 20}
    };


    //std::vector<std::unique_ptr<Command>> TRUE_COMMANDS_LIST{std::make_unique<Begin>()};



}

#endif //MY_PROJECT_COMMANDS_H
