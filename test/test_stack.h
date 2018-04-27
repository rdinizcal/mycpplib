#ifndef TEST_STACK_H
#define TEST_STACK_H

#include <cxxtest/TestSuite.h>
#include "../include/stack.h"

class StackTestSuite : public CxxTest::TestSuite {
    public:

        void testPushBack() {
            Stack stack = Stack(3);

            stack.push_back(42);

            TS_ASSERT_EQUALS(stack.size(),1);
            TS_ASSERT_EQUALS(stack.at(0),42);
        }

        void testPullBack() {
            Stack stack = Stack();

            stack.push_back(42);
            int x = stack.pull_back();

            TS_ASSERT_EQUALS(stack.size(),0);
            TS_ASSERT_EQUALS(stack.at(0),-1);
            TS_ASSERT_EQUALS(x, 42);
        }

        void testMultiplePushesAndPulls() {
            Stack stack = Stack();

            stack.push_back(42);
            stack.push_back(53);
            stack.push_back(64);
            stack.push_back(75);
            stack.push_back(86);
            stack.pull_back();
            stack.pull_back();
            stack.pull_back();
            stack.pull_back();
            stack.push_back(32);
            stack.pull_back();
            stack.push_back(21);
            int x = stack.pull_back();
            stack.push_back(10);
            stack.push_back(0);

            TS_ASSERT_EQUALS(stack.size(),3);
            TS_ASSERT_EQUALS(stack.at(0),42);
            TS_ASSERT_EQUALS(stack.at(1),10);
            TS_ASSERT_EQUALS(stack.at(2),0);
            TS_ASSERT_EQUALS(x,21);
        }
};

#endif