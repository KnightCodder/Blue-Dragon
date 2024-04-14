# Compiler
CXX = g++

# Compilation flags
CXXFLAGS = -Iinclude -Wall -Wextra -g -std=c++17

# Source files directory
SRC_DIR = src

# Object files directory
OBJ_DIR = output

# Library directory
LIB_DIR = lib

# List of source files
SRCS = $(wildcard $(SRC_DIR)/*.cpp)

# List of object files
OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))

# Static library name
LIB_NAME = libchessMoveGeneration.a

# Main executable file name
EXE_NAME = run

# Main target
all: $(LIB_DIR)/$(LIB_NAME) $(OBJS)
	$(CXX) $(OBJS) -o $(OBJ_DIR)/$(EXE_NAME) -L$(LIB_DIR) -lchessMoveGeneration
	./$(OBJ_DIR)/$(EXE_NAME)

# Rule to compile individual source files into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) -c $< $(CXXFLAGS) -o $@

# Rule to clean all the .o and executables
clean:
	rm -f $(OBJ_DIR)/*.o $(OBJ_DIR)/$(EXE_NAME)
