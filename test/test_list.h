#ifndef TEST_LIST_H
#define TEST_LIST_H

#include <cxxtest/TestSuite.h>
#include "../include/list.h"

class ListTestSuite : public CxxTest::TestSuite {

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
        
};

#endif