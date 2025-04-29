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

    testing::internal::CaptureStdout();
    processor.run(preprocessor.process(str));
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "30\n");
}

TEST(EmulatorTest_2, TestFib){
    MEM::Emulator emu;
    std::string answ = "1\n1\n2\n3\n5\n8\n13\n21\n34\n55\n89\n144\n233\n377\n610\n987\n1597\n2584\n4181\n6765\n10946\n17711\n28657\n46368\n75025\n121393\n196418\n317811\n514229\n832040\n1346269\n2178309\n3524578\n5702887\n9227465\n14930352\n24157817\n39088169\n63245986\n102334155\n";

    testing::internal::CaptureStdout();
    emu.start("../test/program_fib.txt");
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, answ);
}

TEST(EmulatorTest_2, TestFact_1){
    MEM::Emulator emu;

    testing::internal::CaptureStdout();
    emu.start("../test/program_fact_1.txt");
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "720\n");
}

TEST(EmulatorTest_3, TestFact_2){
    MEM::Emulator emu;

    testing::internal::CaptureStdout();
    emu.start("../test/program_fact_2.txt");
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "720\n");
}