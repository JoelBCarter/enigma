CXX=g++
CXXFLAGS=-std=c++17 -Wall -g -I/opt/homebrew/Cellar/googletest/1.14.0/include
LDFLAGS=
LDLIBS=

# Main application
SRCS=main.cpp Enigma.cpp
OBJS=$(SRCS:.cpp=.o)
EXECUTABLE=Enigma

# Unit tests
TEST_SRCS=EnigmaTests.cpp Enigma.cpp
TEST_OBJS=$(TEST_SRCS:.cpp=.o)
TEST_EXECUTABLE=EnigmaTests
GTEST_LIBS=-L/opt/homebrew/Cellar/googletest/1.14.0/lib -lgtest -lgtest_main -pthread

.PHONY: all clean test

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJS)
	$(CXX) $(LDFLAGS) -o $@ $^ $(LDLIBS)

$(OBJS): $(SRCS)
	$(CXX) $(CXXFLAGS) -c $(SRCS)

test: $(TEST_EXECUTABLE)

$(TEST_EXECUTABLE): $(TEST_OBJS)
	$(CXX) $(LDFLAGS) -o $@ $^ $(GTEST_LIBS)

$(TEST_OBJS): $(TEST_SRCS)
	$(CXX) $(CXXFLAGS) -c $(TEST_SRCS)

clean:
	rm -f $(OBJS) $(EXECUTABLE) $(TEST_OBJS) $(TEST_EXECUTABLE)
