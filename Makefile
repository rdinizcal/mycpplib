CXX = g++
CXXTEST = cxxtestgen
CXXFLAGS = -Wall -Werror
CXXTESTFLAGS = --error-printer
PROGS = list stack 
OBJS = list.o stack.o
TSTS = test_list.h test_stack.h

all:

list-all: list-compile list-compile-tests list-run-tests

list-compile:
	$(info Compiling list ...)
	$(CXX) $(CXXFLAGS) -c list.cpp -o list.o

list-compile-tests:

	$(info Compiling list tests...)	
	$(CXXTEST) $(CXXTESTFLAGS) -o runner.cpp test_list.h
	$(CXX) -std=c++11 -c runner.cpp  -o a.o
	$(CXX) runner.cpp -o runner.out list.o

list-run-tests:
	$(info Running list tests...)
	./runner.out



stack:
	$(info Compiling stack ...)
	$(CXX) $(CXXFLAGS) -c stack.cpp -o stack.o 

test-all:
	$(info Compiling all tests...)
	$(CXXTEST) $(CXXTESTFLAGS) -o runner.cpp $(TSTS)
	$(CXX) -std=c++11 -c runner.cpp  -o a.o
	$(CXX) runner.cpp -o runner.out $(OBJS)

	$(info Executing all tests...)
	./runner.out

clean:
	$(info Clean all)
	rm -f *~ *.out *.o runner.cpp