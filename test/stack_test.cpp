//
// Created by marmlll on 19.03.2024.
//
#include "gtest/gtest.h"
#include "stack.h"

using namespace MST;

TEST(NodeTest, CheckHandleInt) {
    int k1 = 5;
    int k2 = 125;

    Node <int> node_1(k1, nullptr);
    Node <int> node_2(k2,  &node_1);

    EXPECT_EQ(node_1.data, k1);
    EXPECT_EQ(node_2.data, k2);
    EXPECT_EQ(node_2.prev->data, k1);
}

TEST(NodeTest, CheckHandleString) {
    std::string s1 = "abracadabra_1";
    std::string s2 = "abracadabra_2";

    Node <std::string> node_1(s1, nullptr);
    Node <std::string> node_2(s2,  &node_1);

    EXPECT_EQ(node_1.data, s1);
    EXPECT_EQ(node_2.data, s2);
    EXPECT_EQ(node_2.prev->data, s1);
}

TEST(StackTest, CheckConstructors) {
    Stack<int> stack_1;
    EXPECT_EQ(stack_1.size(), 0);

    stack_1.push(1);
    stack_1.push(2);

    Stack<int>stack_2;
    stack_2 = stack_1;

    EXPECT_EQ(stack_1.size(), 2);
    EXPECT_EQ(stack_2.size(), 2);

    EXPECT_EQ(stack_2.top(), 2);
    stack_2.pop();
    EXPECT_EQ(stack_1.top(), 2);
    EXPECT_EQ(stack_2.top(), 1);

    Stack<int>stack_3(stack_1);


    EXPECT_EQ(stack_1.size(), 2);
    EXPECT_EQ(stack_3.size(), 2);

    EXPECT_EQ(stack_3.top(), 2);
    stack_3.pop();
    EXPECT_EQ(stack_1.top(), 2);
    EXPECT_EQ(stack_3.top(), 1);

}

TEST(StackTest, CheckDestructor) {
    // I don't know, how to write this test
}


//checks push, pop, top, empty, size, clear


TEST(StackTest, CheckMethodsString)
{
    std::string str_1 = "Hello, world_1!";
    std::string str_2 = "Hello, world_2!";
    Stack<std::string> stack;

    stack.push(str_1);
    EXPECT_EQ(stack.top(), str_1);
    EXPECT_EQ(stack.empty(), false);
    EXPECT_EQ(stack.size(), 1);

    stack.push(str_2);
    EXPECT_EQ(stack.top(), str_2);
    EXPECT_EQ(stack.empty(), false);
    EXPECT_EQ(stack.size(), 2);

    stack.pop();
    EXPECT_EQ(stack.top(), str_1);
    EXPECT_EQ(stack.empty(), false);
    EXPECT_EQ(stack.size(), 1);

    stack.pop();
    EXPECT_EQ(stack.empty(), true);


    stack.push(str_1);
    stack.push(str_2);

    EXPECT_EQ(stack.empty(), false);
    EXPECT_EQ(stack.size(), 2);

    stack.clear();

    EXPECT_EQ(stack.empty(), true);

}

TEST(StackTest, CheckMethodsInt)
{
    int k1 = 1;
    int k2 = 2;
    Stack<int> stack;

    EXPECT_EQ(stack.empty(), true);

    stack.push(k1);
    EXPECT_EQ(stack.top(), k1);
    EXPECT_EQ(stack.empty(), false);
    EXPECT_EQ(stack.size(), 1);

    stack.push(k2);
    EXPECT_EQ(stack.top(), k2);
    EXPECT_EQ(stack.empty(), false);
    EXPECT_EQ(stack.size(), 2);

    stack.pop();
    EXPECT_EQ(stack.top(), k1);
    EXPECT_EQ(stack.empty(), false);
    EXPECT_EQ(stack.size(), 1);

    stack.pop();
    EXPECT_EQ(stack.empty(), true);


    stack.push(k1);
    stack.push(k2);

    EXPECT_EQ(stack.empty(), false);
    EXPECT_EQ(stack.size(), 2);

    stack.clear();

    EXPECT_EQ(stack.empty(), true);
}

TEST(StackTest, CheckMethods_BigTest)
{
    Stack<int> stack;
    EXPECT_EQ(stack.empty(), true);

    for(int i=1; i<=10000; ++i)
    {
        stack.push(i);
        EXPECT_EQ(stack.top(), i);
        EXPECT_EQ(stack.size(),i);
    }

    for(int i=10000; i>=1; --i){
        EXPECT_EQ(stack.top(), i);
        EXPECT_EQ(stack.size(),i);
        stack.pop();
    }
}