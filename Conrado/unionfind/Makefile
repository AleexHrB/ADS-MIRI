# Makefile for compiling and linking main.cc and UnionFind.cc

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++11

# Target executable
TARGET = main.exe

# Source files
SOURCES = main.cc UnionFind.cc

# Object files
OBJECTS = $(SOURCES:.cc=.o)

# Header files
HEADERS = UnionFind.hh

# Default target
all: $(TARGET)

# Link the object files to create the executable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

# Compile the source files to object files
%.o: %.cc $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(TARGET) $(OBJECTS)

# Phony targets
.PHONY: all clean
