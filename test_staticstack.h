#include <cxxtest/TestSuite.h>
#include "staticstack.h"

class StaticStackTestSuite : public CxxTest::TestSuite {
    public:

        void testDefaultConstructor(void) {

            StaticStack stack = StaticStack();

            TS_ASSERT(&stack != 0);
        }

        void testConstructor(void) {

            StaticStack stack = StaticStack(10);

            TS_ASSERT(&stack != 0);
        }

        void testEmptyStack(void) {
            
            StaticStack stack = StaticStack(10);
            
            TS_ASSERT(stack.isEmpty() == true);
        }

        void testStackSize(void) {
            
            StaticStack stack10 = StaticStack(10);
            TS_ASSERT(stack10.size() == 0);
        }

        void testStackCapacity(void) {

            StaticStack stack1  = StaticStack(10);
            TS_ASSERT(stack1.getCapacity() == 10);
        }

        void testStackPush(void) {

            StaticStack stack = StaticStack();

            stack.push(5);
            TS_ASSERT_EQUALS(stack.size(), 1);
            TS_ASSERT(stack.at(0) == 5);

            stack.push(-1);
            TS_ASSERT(stack.size() == 2);
            TS_ASSERT(stack.at(0) == 5);
            TS_ASSERT(stack.at(1) == -1);
        }

        void testStackOverflow(void) {

            StaticStack stack = StaticStack(3);

            stack.push(1);
            stack.push(2);
            stack.push(3);
            stack.push(4);

            TS_ASSERT(stack.size() == 3);
            TS_ASSERT(stack.at(2) == 3);            
            TS_ASSERT(stack.at(3) == 0);            
        }

        void testGetTopElement(void){
            StaticStack stack = StaticStack(10);

            TS_ASSERT_EQUALS(stack.isEmpty(), true);

            stack.push(1);
            TS_ASSERT_EQUALS(stack.at(stack.size()-1), 1);

            stack.push(2);
            TS_ASSERT_EQUALS(stack.at(stack.size()-1), 2);

            stack.push(3);
            TS_ASSERT_EQUALS(stack.at(stack.size()-1), 3);

        }

        void testStackPullElement(void) {
            
            StaticStack stack = StaticStack(10);

            stack.push(1);
            stack.push(1);
            stack.push(2);
            stack.push(3);

            int x = stack.pull();

            TS_ASSERT_EQUALS(x, 3);
            TS_ASSERT_EQUALS(stack.size(), 3);
            TS_ASSERT_EQUALS(stack.at(stack.size()-1), 2);
        }

        void testStackUnderflow(void) {
            
            StaticStack stack = StaticStack(10);

            stack.push(1);

            int x = stack.pull();
            TS_ASSERT_EQUALS(x, 1);
            TS_ASSERT_EQUALS(stack.size(), 0);

            x = stack.pull();
            TS_ASSERT_EQUALS(x,0);
            TS_ASSERT_EQUALS(stack.size(), 0);
            
        }
};