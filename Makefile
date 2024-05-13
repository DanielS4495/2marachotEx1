#!make -f

CXX=clang++
CXXFLAGS=-std=c++11 -Werror -Wsign-conversion -pedantic
VALGRIND_FLAGS=-v --leak-check=full --show-leak-kinds=all  --error-exitcode=99
LDLIBS=-pthread

SOURCES=Graph.cpp Algorithms.cpp MyTest.cpp #TestCounter.cpp Test.cpp Demo.cpp
OBJECTS=$(subst .cpp,.o,$(SOURCES))

# run: demo
# 	./$^

# demo:  $(OBJECTS) Demo.o
# 	$(CXX) $(CXXFLAGS) $^ -o demo


run: MyTest
	./$^

MyTest:  Graph.o Algorithms.o MyTest.o
	$(CXX) $(CXXFLAGS) $^ -o MyTest

# test: TestCounter.o Test.o $(OBJECTS)
# 	$(CXX) $(CXXFLAGS) $^ -o test

tidy:
	clang-tidy $(SOURCES) -checks=bugprone-*,clang-analyzer-*,cppcoreguidelines-*,performance-*,portability-*,readability-*,-cppcoreguidelines-pro-bounds-pointer-arithmetic,-cppcoreguidelines-owning-memory --warnings-as-errors=-* --

# valgrind: demo test
# 	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./demo 2>&1 | { egrep "lost| at " || true; }
# 	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./test 2>&1 | { egrep "lost| at " || true; }

%.o: %.cpp
	$(CXX) $(CXXFLAGS) --compile $< -o $@


clean:
	rm -f *.o demo test MyTest
