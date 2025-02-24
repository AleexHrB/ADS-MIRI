# Compiler
CXX = g++
# Compiler flags
CXXFLAGS = -std=c++11 -O2
# Target executable name
TARGET = main

# Source files
SRC = main.cc bst.cc
# Object files
OBJ = $(SRC:.cc=.o)

# Default rule
all: $(TARGET)

# Linking step
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

# Compiling source files to object files
%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build files
clean:
	rm -f $(OBJ) $(TARGET)

# Phony targets
.PHONY: all clean

