//
// Created by marmlll on 21.03.2024.
//

#include "gtest/gtest.h"
#include "emulator.h"
#include "processor.h"
#include "preprocessor.h"
#include <fstream>


TEST(EmulatorTest_1, TestProgram_1){

    std::string str = "BEGIN\nPUSH 10\nPUSH 20\nADD\nOUT\nEND\n";
    MPE::Preprocessor preprocessor;
    MPR::Processor processor;

    processor.run(preprocessor.process(str));
}

TEST(EmulatorTest_2, TestFib){
    MEM::Emulator emu;
    emu.start("../test/program_fib.txt");
}