//
// Created by marmlll on 20.03.2024.
//

#ifndef MY_PROJECT_PROCESSOR_H
#define MY_PROJECT_PROCESSOR_H

#include <vector>
#include "commands.h"
#include "memory.h"


// My PRocessor
namespace MPR {
    class Processor {
    private:
        MME::Memory processor_memory;

        void add_labels(const std::vector<std::shared_ptr<MCM::Command>> &commands){
            for (int i = 0; i < commands.size(); ++i) {
                if (commands[i]->name() == "LAB") {
                    processor_memory.add_label(commands[i]->arg, i);
                }
            }
        }
        int current_position = 0;

        void manage_calls() {
            if(processor_memory.get_register("call to")!=-1){
                processor_memory.push_call_stack(current_position);

                current_position = processor_memory.get_register("call to");

                processor_memory.set_register("call to", -1);
            }
            if(processor_memory.get_register("return back")!=0){
                current_position = processor_memory.pop_call_stack();
                processor_memory.set_register("return back", 0);
            }
        }

        void manage_jumps() {
            if (processor_memory.get_register("jump to") != -1) {
                current_position = processor_memory.get_register("jump to");
                processor_memory.set_register("jump to", -1);
            }
        }
    public:


        void run(const std::vector<std::shared_ptr<MCM::Command>> &commands) {
            processor_memory.set_register("jump to", -1);
            processor_memory.set_register("return back", 0);
            processor_memory.set_register("call to", -1);
            processor_memory.set_register("is running", 0);


            add_labels(commands);

            int run_flag;
            run_flag = processor_memory.get_register("is running");

            while(current_position < commands.size()){
                run_flag = processor_memory.get_register("is running");


                commands[current_position]->run(processor_memory);

                if (!run_flag) {
                    if (processor_memory.get_register("is running") == run_flag) {
                        throw std::invalid_argument("Processor: can't run command while complier not active");
                    }
                }
                manage_calls();
                manage_jumps();
                current_position++;
            }

            if (processor_memory.get_register("is running")) {
                throw std::invalid_argument("Processor: don't found END command");
            }
        }


    };
}

#endif //MY_PROJECT_PROCESSOR_H
