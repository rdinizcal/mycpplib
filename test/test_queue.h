#ifndef TEST_QUEUE_H
#define TEST_QUEUE_H

#include <cxxtest/TestSuite.h>
#include "../include/queue.h"

class QueueTestSuite : public CxxTest::TestSuite {
    public:

        void testPushBack() {
            Queue queue = Queue();

            queue.push_back(42);

            TS_ASSERT_EQUALS(queue.size(), 1);
            TS_ASSERT_EQUALS(queue.at(0), 42);
        }

        void testPopBack() {
            Queue queue = Queue();

            queue.push_back(42);
            int x = queue.pop_front();

            TS_ASSERT_EQUALS(queue.size(),0);
            TS_ASSERT_EQUALS(queue.at(0),-1);
            TS_ASSERT_EQUALS(x, 42);
        }

        void testMultiplePushesAndPulls() {
            Queue queue = Queue();

            queue.push_back(42);
            queue.push_back(53);
            queue.push_back(64);
            queue.push_back(75);
            queue.push_back(86);
            queue.pop_front();
            queue.pop_front();
            queue.pop_front();
            queue.pop_front();
            queue.push_back(32);
            queue.pop_front();
            queue.push_back(21);
            int x = queue.pop_front();
            queue.push_back(10);
            queue.push_back(0);

            TS_ASSERT_EQUALS(queue.size(),3);
            TS_ASSERT_EQUALS(queue.at(0),21);
            TS_ASSERT_EQUALS(queue.at(1),10);
            TS_ASSERT_EQUALS(queue.at(2),0);
            TS_ASSERT_EQUALS(x,32);
        }
};

#endif