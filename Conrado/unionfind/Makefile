# Makefile for compiling and linking main and generator

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++11 -g

# Targets
TARGETS = main.exe generator.exe

# Source files
MAIN_SRC = main.cc UnionFind.cc
GEN_SRC = generator.cc UnionFind.cc

# Object files
MAIN_OBJ = $(MAIN_SRC:.cc=.o)
GEN_OBJ = $(GEN_SRC:.cc=.o)

# Header files
HEADERS = UnionFind.hh

# Default target
all: $(TARGETS)

# Build main executable
main: main.exe

main.exe: $(MAIN_OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $(MAIN_OBJ)

# Build generator executable
generator: generator.exe

generator.exe: $(GEN_OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $(GEN_OBJ)

# Compile source files to object files
%.o: %.cc $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(TARGETS) $(MAIN_OBJ) $(GEN_OBJ)

# Phony targets
.PHONY: all clean main generator

