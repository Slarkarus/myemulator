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

        std::string name;
        std::string arg;
    };

    class Begin: public Command{
    public:
        Begin()=default;
        std::string name = "BEGIN";

        void run(MME::Memory &mem) const override
        {
            mem.set_register("running", 1);
        }

    };

    class End: public Command{
    public:
        End()=default;
        std::string name = "END";

        void run(MME::Memory &mem)const override
        {
            mem.set_register("running", 0);
        }
    };

    class Push: public Command{
    public:
        Push() = default;
        std::string name = "PUSH";

        void run(MME::Memory &mem)const override
        {
            mem.push_main_stack(stoi(arg));
        }
    };

    class Pop: public Command{
    public:
        Pop() = default;
        std::string name = "POP";


        void run(MME::Memory &mem)const override
        {
            mem.pop_main_stack();
        }
    };

    class Pushr: public Command{
    public:
        Pushr() = default;
        std::string name = "PUSHR";

        void run(MME::Memory &mem)const override
        {
            mem.push_main_stack(mem.get_register(arg));
        }
    };

    class Popr: public Command{
    public:
        Popr() = default;
        std::string name = "POPR";

        void run(MME::Memory &mem)const override
        {
            mem.set_register(arg, mem.top_main_stack());
            mem.pop_main_stack();
        }
    };

    class Add: public Command{
    public:
        Add() = default;
        std::string name = "ADD";

        void run(MME::Memory &mem)const override
        {
            int x = mem.top_main_stack();
            mem.pop_main_stack();
            int y = mem.top_main_stack();
            mem.pop_main_stack();
            mem.push_main_stack(x+y);
        }
    };

    class Sub: public Command{
    public:
        Sub() = default;
        std::string name = "SUB";

        void run(MME::Memory &mem)const override
        {
            int x = mem.top_main_stack();
            mem.pop_main_stack();
            int y = mem.top_main_stack();
            mem.pop_main_stack();
            mem.push_main_stack(x-y);
        }
    };

    class Mul: public Command{
    public:
        Mul() = default;
        std::string name = "MUL";

        void run(MME::Memory &mem)const override
        {
            int x = mem.top_main_stack();
            mem.pop_main_stack();
            int y = mem.top_main_stack();
            mem.pop_main_stack();
            mem.push_main_stack(x*y);
        }
    };

    class Div: public Command{
    public:
        Div() = default;
        std::string name = "DIV";

        void run(MME::Memory &mem)const override
        {
            int x = mem.top_main_stack();
            mem.pop_main_stack();
            int y = mem.top_main_stack();
            mem.pop_main_stack();
            mem.push_main_stack(x/y);
        }
    };

    class Out: public Command{
    public:
        Out() = default;
        std::string name = "OUT";

        void run(MME::Memory &mem)const override
        {
            int x = mem.top_main_stack();
            mem.pop_main_stack();
            std::cout << x << '\n';
        }
    };

    class In: public Command{
    public:
        In() = default;
        std::string name = "IN";

        void run(MME::Memory &mem)const override
        {
            int x;
            std::cin >> x;
            mem.push_main_stack(x);
        }
    };

    class Jmp: public Command{ // НЕ РАБОТАЕТ
    public:
        Jmp() = default;
        std::string name = "JMP";

        void run(MME::Memory &mem)const override
        {
            mem.pop_main_stack();
        }
    };

    class Jeq: public Command{ // НЕ РАБОТАЕТ
    public:
        Jeq() = default;
        std::string name = "JEQ";

        void run(MME::Memory &mem)const override
        {
            mem.pop_main_stack();
        }
    };

    class Jne: public Command{ // НЕ РАБОТАЕТ
    public:
        Jne() = default;
        std::string name = "JNE";

        void run(MME::Memory &mem)const override
        {
            mem.pop_main_stack();
        }
    };

    class Ja: public Command{ // НЕ РАБОТАЕТ
    public:
        Ja() = default;
        std::string name = "JA";

        void run(MME::Memory &mem)const override
        {
            mem.pop_main_stack();
        }
    };

    class Jae: public Command{ // НЕ РАБОТАЕТ
    public:
        Jae() = default;
        std::string name = "JAE";

        void run(MME::Memory &mem)const override
        {
            mem.pop_main_stack();
        }
    };

    class Jb: public Command{ // НЕ РАБОТАЕТ
    public:
        Jb() = default;
        std::string name = "JB";

        void run(MME::Memory &mem)const override
        {
            mem.pop_main_stack();
        }
    };

    class Call: public Command{ // НЕ РАБОТАЕТ
    public:
        Call() = default;
        std::string name = "CALL";

        void run(MME::Memory &mem)const override
        {
            mem.pop_main_stack();
        }
    };

    class Ret: public Command{ // НЕ РАБОТАЕТ
    public:
        Ret() = default;
        std::string name = "RET";

        void run(MME::Memory &mem)const override
        {
            mem.pop_main_stack();
        }
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
