CXX = g++
CXXTEST = cxxtestgen
CXXFLAGS = -Wall -Werror
CXXTESTFLAGS = --error-printer
OBJS = list.o stack.o

SRC-FOLDER = src/
INCLUDE-FOLDER = include/
TEST-FOLDER = test/

all:

list-all: list-compile list-compile-tests list-run-tests

list-compile:
	$(info Compiling list ...)
	$(CXX) $(CXXFLAGS) -c $(SRC-FOLDER)list.cpp -I $(INCLUDE-FOLDER) -o list.o

list-compile-tests:
	$(info Compiling list tests...)	
	$(CXXTEST) $(CXXTESTFLAGS) -o runner.cpp $(TEST-FOLDER)test_list.h
	$(CXX) -std=c++11 -c runner.cpp  -o a.o
	$(CXX) runner.cpp -o runner.out list.o

list-run-tests:
	$(info Running list tests...)
	./runner.out

stack-all: stack-compile stack-compile-tests stack-run-tests

stack-compile: list-compile
	$(info Compiling stack ...)
	$(CXX) $(CXXFLAGS) -c $(SRC-FOLDER)stack.cpp -I $(INCLUDE-FOLDER) -o stack.o 

stack-compile-tests:
	$(info Compiling stack tests...)	
	$(CXXTEST) $(CXXTESTFLAGS) -o runner.cpp $(TEST-FOLDER)test_stack.h
	$(CXX) -std=c++11 -c runner.cpp  -o a.o
	$(CXX) runner.cpp -o runner.out list.o stack.o

stack-run-tests:
	$(info Running stack tests...)
	./runner.out

test-all: list-compile stack-compile
	$(info Compiling all tests...)
	$(CXXTEST) $(CXXTESTFLAGS) -o runner.cpp $(TEST-FOLDER)test_list.h $(TEST-FOLDER)test_stack.h
	$(CXX) -std=c++11 -c runner.cpp  -o a.o
	$(CXX) runner.cpp -o runner.out $(OBJS)

	$(info Executing all tests...)
	./runner.out

clean:
	$(info Clean all)
	rm -f *~ *.out *.o runner.cpp