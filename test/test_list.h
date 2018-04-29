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

        void testParameterizedConstructor() {
            //int *input = new int[5]{1,2,3,4,5}; warning
            int *input = new int[5];
            for(int i=0; i<5; i++) input[i] = i+1;

            List list = List(5, input);

            TS_ASSERT(&list != NULL);
            TS_ASSERT_EQUALS(list.size(), 5);
            TS_ASSERT_EQUALS(list.at(0), 1);
            TS_ASSERT_EQUALS(list.at(3), 4);
        }

        void testSize(){
            List list = List();
            TS_ASSERT_EQUALS(list.size(),0);
        }

        void testIsEmpty() {
            List list = List();
            TS_ASSERT_EQUALS(list.isEmpty(), true);
        }

        void testSort() {
            //int *input = new int[10]{33,88,55,44,00,99,22,77,11,66};
            
            int *input = new int[10];
            input[0] = 00;
            input[1] = 99;
            input[2] = 22;
            input[3] = 77;
            input[4] = 11;
            input[5] = 33;
            input[6] = 88;
            input[7] = 55;
            input[8] = 44;
            input[9] = 66;
            
            List list = List(10, input);

            list.insertionSort();

            list.toString();

            TS_ASSERT_EQUALS(list.at(0), 00);
            TS_ASSERT_EQUALS(list.at(1), 11);
            TS_ASSERT_EQUALS(list.at(2), 22);
            TS_ASSERT_EQUALS(list.at(3), 33);
            TS_ASSERT_EQUALS(list.at(4), 44);
            TS_ASSERT_EQUALS(list.at(5), 55);
            TS_ASSERT_EQUALS(list.at(6), 66);
            TS_ASSERT_EQUALS(list.at(7), 77);
            TS_ASSERT_EQUALS(list.at(8), 88);
            TS_ASSERT_EQUALS(list.at(9), 99);            
        }
};

#endif