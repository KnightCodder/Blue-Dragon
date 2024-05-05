# Compiler
CXX = g++

# Compilation flags
CXXFLAGS = -Iinclude -Iheader -Wall -Wextra -g -std=c++17 -O0

# Source files directory
SRC_DIR = src

# Object files directory
OBJ_DIR = output

# Library directory
LIB_DIR = lib

# Test files directory
TEST_DIR = tests

# main app
APP = playWithAI/main.cpp

APP_EXE = playWithAI

# List of source files
SRCS = $(wildcard $(SRC_DIR)/*.cpp)

# List of object files
OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))

# Static library name
LIB_NAME = libchessMoveGeneration.a

# Main executable file name
EXE_NAME = run

# Main target
all: $(LIB_DIR)/$(LIB_NAME) $(OBJS) $(OBJ_DIR)/test1.o
	$(CXX) $(OBJS) $(OBJ_DIR)/test1.o -o $(OBJ_DIR)/$(EXE_NAME) -L$(LIB_DIR) -lchessMoveGeneration
	./$(OBJ_DIR)/$(EXE_NAME)

# Rule to compile individual source files into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) -c $< $(CXXFLAGS) -o $@

# Rule to compile test1.cpp into object file
$(OBJ_DIR)/test1.o: $(TEST_DIR)/test1.cpp
	$(CXX) -c $(TEST_DIR)/test1.cpp $(CXXFLAGS) -o $(OBJ_DIR)/test1.o

$(OBJ_DIR)/main.o: $(APP)
	$(CXX) -c $(APP) $(CXXFLAGS) -o $(OBJ_DIR)/main.o

# Rule to clean all the .o and executables
clean:
	rm -f $(OBJ_DIR)/*.o $(OBJ_DIR)/$(EXE_NAME)

# Rule to debug with gdb
debug: $(LIB_DIR)/$(LIB_NAME) $(OBJS) $(OBJ_DIR)/test1.o
	$(CXX) $(OBJS) $(OBJ_DIR)/test1.o -o $(OBJ_DIR)/$(EXE_NAME) -L$(LIB_DIR) -lchessMoveGeneration $(CXXFLAGS) -g
	gdb $(OBJ_DIR)/$(EXE_NAME)

# Rule to check memory with valgrind
valgrind: $(LIB_DIR)/$(LIB_NAME) $(OBJS) $(OBJ_DIR)/test1.o
	$(CXX) $(OBJS) $(OBJ_DIR)/test1.o -o $(OBJ_DIR)/$(EXE_NAME) -L$(LIB_DIR) -lchessMoveGeneration $(CXXFLAGS) -g
	valgrind ./$(OBJ_DIR)/$(EXE_NAME)

# to create the app exe
createApp: $(LIB_DIR)/$(LIB_NAME) $(OBJS) $(OBJ_DIR)/main.o
	$(CXX) $(OBJS) $(OBJ_DIR)/main.o -o $(APP_EXE) -L$(LIB_DIR) -lchessMoveGeneration -static-libgcc -static-libstdc++
	./$(APP_EXE)