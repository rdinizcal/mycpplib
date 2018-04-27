CXX = g++
CXXTEST = cxxtestgen
CXXFLAGS = -Wall -Werror
CXXTESTFLAGS = --error-printer
OBJS = staticstack.o

all: ss test

ss:
	$(info Compiling Static Stack ...)
	$(CXX) $(CXXFLAGS) -c staticstack.cpp -o staticstack.o 

test:
	$(info Compiling tests...)
	$(CXXTEST) $(CXXTESTFLAGS) -o runner.cpp test_staticstack.h 
	$(CXX) -std=c++11 -c runner.cpp  -o a.o
	$(CXX) runner.cpp -o runner.out $(OBJS)

	$(info Executing tests...)
	./runner.out

clean:
	$(info Clean all)
	rm -f *~ *.out *.o runner.cpp