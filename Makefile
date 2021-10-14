build:
	rm -rf build/ && mkdir build && cd build && cmake .. && make

run:
	./build/main

run-tests:
	./build/Gtest/tests

valgrind-check:
	valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all --undef-value-errors=no --verbose --log-file=$(filename)  $(directory)

valgrind:
	rm -rf valgrind_output && mkdir valgrind_output && make valgrind-check directory=./build/Gtest/tests filename=valgrind_output/report