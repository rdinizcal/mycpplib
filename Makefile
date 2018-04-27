CXX = g++
CXXTEST = cxxtestgen
CXXFLAGS = -Wall -Werror
CXXTESTFLAGS = --error-printer
OBJS = stack.o

all: stack test

stack:
	$(info Compiling stack ...)
	$(CXX) $(CXXFLAGS) -c stack.cpp -o stack.o 

queue:
	$(info Compiling queue ...)
	$(CXX) $(CXXFLAGS) -c stack.cpp -o stack.o

test:
	$(info Compiling tests...)
	$(CXXTEST) $(CXXTESTFLAGS) -o runner.cpp test_stack.h 
	$(CXX) -std=c++11 -c runner.cpp  -o a.o
	$(CXX) runner.cpp -o runner.out $(OBJS)

	$(info Executing tests...)
	./runner.out

clean:
	$(info Clean all)
	rm -f *~ *.out *.o runner.cpp