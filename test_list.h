#ifndef TEST_LIST_H
#define TEST_LIST_H

#include <cxxtest/TestSuite.h>
#include "list.h"

class StackTestSuite : public CxxTest::TestSuite {

    public:

        void testDefaultConstructor() {
            List list = List();
            TS_ASSERT(&list != NULL);
        }

        void testConstructor() {
            List list = List(5);
            TS_ASSERT(&list != NULL);
        }

        void testSize(){
            List list = List();
            TS_ASSERT_EQUALS(list.size(),0);
        }

        void testIsEmpty() {
            List list = List();
            TS_ASSERT_EQUALS(list.isEmpty(), true);
        }

        void testInsertAt() {
            List list = List();

            list.insertAt(0, 42);
            TS_ASSERT_EQUALS(list.size(), 1);
            TS_ASSERT_EQUALS(list.at(0), 42);
        }

        void testInsertAtTheEnd() {
            List list = List();

            list.insertAt(0, 42);
            list.insertAt(1, 31);
            list.insertAt(3, 53);
            
            TS_ASSERT_EQUALS(list.size(), 3);
            TS_ASSERT_EQUALS(list.at(0), 42);
            TS_ASSERT_EQUALS(list.at(1), 31);
            TS_ASSERT_EQUALS(list.at(2), 53);
        }

        void testInsertAtMiddle() {
            List list = List();

            list.insertAt(0, 42);
            list.insertAt(1, 31);
            list.insertAt(2, 53);
            list.insertAt(1, 99);
            
            TS_ASSERT_EQUALS(list.size(), 4);
            TS_ASSERT_EQUALS(list.at(0), 42);
            TS_ASSERT_EQUALS(list.at(1), 99);
            TS_ASSERT_EQUALS(list.at(2), 31);          
            TS_ASSERT_EQUALS(list.at(3), 53);
        }
        
        void testDeleteAt() {
            List list = List();

            list.insertAt(0, 42);
            list.deleteAt(0);

            TS_ASSERT_EQUALS(list.size(), 0);
            TS_ASSERT_EQUALS(list.at(0), -1);
        }

        void testDeleteAtTheEnd() {
            List list = List();

            list.insertAt(0, 42);
            list.insertAt(1, 31);
            list.insertAt(2, 53);
            list.deleteAt(2);

            TS_ASSERT_EQUALS(list.size(), 2);
            TS_ASSERT_EQUALS(list.at(0), 42);
            TS_ASSERT_EQUALS(list.at(1), 31);
            TS_ASSERT_EQUALS(list.at(2), -1);
        }

        void testDeleteAtTheMiddle() {
            List list = List();

            list.insertAt(0, 42);
            list.insertAt(1, 31);
            list.insertAt(2, 53);
            list.insertAt(3, 99);
            list.deleteAt(1);

            TS_ASSERT_EQUALS(list.size(), 3);
            TS_ASSERT_EQUALS(list.at(0), 42);
            TS_ASSERT_EQUALS(list.at(1), 53);
            TS_ASSERT_EQUALS(list.at(2), 99);            
        }
};

#endif