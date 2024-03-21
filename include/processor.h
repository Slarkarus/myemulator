//
// Created by marmlll on 20.03.2024.
//

#ifndef MY_PROJECT_PROCESSOR_H
#define MY_PROJECT_PROCESSOR_H

#include <vector>
#include "commands.h"
#include "memory.h"


// My PRocessor
namespace MPR{
    class Processor{
    private:
        MME::Memory processor_memory;
    public:

        void run(std::vector <std::shared_ptr<MCM::Command>> commands){


            for(auto &com:commands){
                com->run(processor_memory);
                manage_calls();
                manage_jumps();
            }
        }
        void manage_calls(){

        }
        void manage_jumps(){

        }
    };
}

#endif //MY_PROJECT_PROCESSOR_H
