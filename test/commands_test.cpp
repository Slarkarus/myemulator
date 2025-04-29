//
// Created by marmlll on 21.03.2024.
//
#include "gtest/gtest.h"
#include "commands.h"
#include "memory.h"

TEST(CommandsTest, BeginTest){
    MME::Memory mem;

    MCM::Begin beg;
    beg.run(mem);
    EXPECT_EQ(mem.get_register("running"), 1);
}
TEST(CommandsTest, EndTest){
    MME::Memory mem;

    MCM::Begin beg;
    MCM::End end;
    beg.run(mem);
    EXPECT_EQ(mem.get_register("running"), 1);
}
TEST(CommandsTest, PushTest){
    MME::Memory mem;

    MCM::Push com;
    com.arg = "1";
    com.run(mem);
    EXPECT_EQ(mem.top_main_stack(), 1);
}

TEST(CommandsTest, PopTest){
    MME::Memory mem;

    MCM::Push com;
    com.arg = "1";
    com.run(mem);
    MCM::Pop com_2;
    com_2.run(mem);
    EXPECT_EQ(mem.size_main_stack(), 0);
}