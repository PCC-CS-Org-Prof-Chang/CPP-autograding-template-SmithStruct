all: clean test

appTests: tests.cpp student.hpp
	# add custom source files here to be compiled; disabled -Wall option to turn off verbose warnings
	g++ --std=c++17 helper_functions.cpp tests.cpp catch_amalgamated.cpp -o appTests

test: appTests
	# executes all tests
	./appTests

clean:
	rm -f appTests
