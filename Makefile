all: 
	@cxxtestgen --error-printer -o runner.cpp MyTestSuite1.h
	@g++ runner.cpp -o runner.out
	
	./runner.out