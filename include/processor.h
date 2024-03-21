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
            processor_memory.set_register("jump to", -1);
            processor_memory.set_register("is running", 0);
            int run_flag=0;
            for(int i=0; i<commands.size(); ++i){
                run_flag = processor_memory.get_register("is running");

                commands[i]->run(processor_memory);
                if(!run_flag) {
                    if (processor_memory.get_register("is running") == run_flag) {
                        throw std::invalid_argument("Processor: can't run command while complier not active");
                    }
                }
                manage_calls();
                manage_jumps();
            }
            if(processor_memory.get_register("is running")){
                throw std::invalid_argument("Processor: don't found END command");
            }
        }
        void manage_calls(){

        }
        void manage_jumps(){
            if(processor_memory.get_register("jump to") != -1){

            }
        }
    };
}

#endif //MY_PROJECT_PROCESSOR_H
