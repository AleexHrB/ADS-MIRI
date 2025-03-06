# Compiler
CXX = g++
# Compiler flags
CXXFLAGS = -std=c++11 -O2 -g
# Source files (BST class)
BST_SRC = bst.cc
BST_OBJ = $(BST_SRC:.cc=.o)

# Main source files and corresponding executables
insertion_SRC = mainInsertion.cc
insertion_OBJ = $(insertion_SRC:.cc=.o)
insertion_TARGET = insertion

ipl_SRC = mainIPL.cc
ipl_OBJ = $(ipl_SRC:.cc=.o)
ipl_TARGET = ipl

delete_SRC = mainDelete.cc
delete_OBJ = $(delete_SRC:.cc=.o)
delete_TARGET = delete

# Default rule (show usage)
all:
	@echo "Usage: make [insertion | ipl | delete]"

# Rules for compiling each executable
$(insertion_TARGET): $(insertion_OBJ) $(BST_OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(ipl_TARGET): $(ipl_OBJ) $(BST_OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(delete_TARGET): $(delete_OBJ) $(BST_OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compiling source files to object files
%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build files
clean:
	rm -f $(insertion_OBJ) $(ipl_OBJ) $(delete_OBJ) $(BST_OBJ) $(insertion_TARGET) $(ipl_TARGET) $(delete_TARGET)

# Phony targets
.PHONY: all clean insertion ipl delete
