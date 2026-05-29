# Makefile for the project
CXX      = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -g

TARGET = main
# Automatically find all .cpp files in subdirectories
SRCS   = main.cpp $(wildcard RegularPractice/*.cpp) $(wildcard DataStructureandAlgorithm/*.cpp)
OBJS   = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) *.o RegularPractice/*.o DataStructureandAlgorithm/*.o

.PHONY: all clean