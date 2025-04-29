//
// Created by marmlll on 20.03.2024.
//


#include "gtest/gtest.h"
#include "my_parser.h"

TEST(ParserTest, ParseCommands){

    std::string input = "  BEGIN \nPUSH 140 \n PUSHR AX \nlabel\n\0";
    auto tokens = MPS::parse_commands(input);

    for (const auto &token: tokens) {
        std::cout << token.value << std::endl;
    }

    EXPECT_EQ(tokens[0].value, "BEGIN");
}

TEST(ParserTest, ParseProgram_1){
    std::string input = " BEGIN \n PUSH 10 \nPUSH 20\nADD\nOUT\nEND\n";
    auto tokens = MPS::parse_commands(input);

    //for (const auto &token: tokens) {
    //    std::cout << token.value << std::endl;
    //}
    EXPECT_EQ(tokens.size(), 8);
    EXPECT_EQ(tokens[0].value, "BEGIN");
    EXPECT_EQ(tokens[1].value, "PUSH");
    EXPECT_EQ(tokens[2].value, "10");
    EXPECT_EQ(tokens[3].value, "PUSH");
    EXPECT_EQ(tokens[4].value, "20");
    EXPECT_EQ(tokens[5].value, "ADD");
    EXPECT_EQ(tokens[6].value, "OUT");
    EXPECT_EQ(tokens[7].value, "END");
}