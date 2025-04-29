//
// Created by marmlll on 20.03.2024.
//

#ifndef MY_PROJECT_EMULATOR_H
#define MY_PROJECT_EMULATOR_H

#include <string>
#include "preprocessor.h"
#include "processor.h"
#include <fstream>



// My EMulator
namespace MEM {
    class Emulator {
    private:
        std::string read_file(const std::string &fileName) {
            std::ifstream f(fileName);
            std::stringstream ss;
            ss << f.rdbuf();
            return ss.str();
        }

    public:
        void start(std::string path) {
            std::string str = read_file(path);
            MPE::Preprocessor preprocessor;
            MPR::Processor processor;

            processor.run(preprocessor.process(str));
        }
    };

}

#endif //MY_PROJECT_EMULATOR_H
